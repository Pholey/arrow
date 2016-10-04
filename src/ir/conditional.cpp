// Copyright (c) 2014-2015 Ryan Leckey, All Rights Reserved.

// Distributed under the MIT License
// See accompanying file LICENSE

#include "arrow/ir.hpp"
#include "arrow/generator.hpp"

using arrow::ir::Conditional;

// TODO: Value

LLVMValueRef Conditional::handle(GContext& ctx) noexcept {
  // Realize condition
  auto condition_handle = condition->value_of(ctx);

  // Launchpad
  auto current = LLVMGetInsertBlock(ctx.irb);
  auto parent_fn = LLVMGetBasicBlockParent(current);
  auto b_then = LLVMAppendBasicBlock(parent_fn, "conditional:then");
  auto b_otherwise = LLVMAppendBasicBlock(parent_fn, "conditional:otherwise");
  auto b_merge = LLVMAppendBasicBlock(parent_fn, "conditional:merge");
  auto divergent_then = false;
  auto divergent_otherwise = false;
  LLVMValueRef then_handle = nullptr;
  LLVMValueRef otherwise_handle = nullptr;

  // Test and Branch
  LLVMBuildCondBr(ctx.irb, condition_handle, b_then, b_otherwise);

  // Realize THEN
  LLVMMoveBasicBlockAfter(b_then, LLVMGetInsertBlock(ctx.irb));
  LLVMPositionBuilderAtEnd(ctx.irb, b_then);
  then_handle = ir::transmute(then, type)->value_of(ctx);
  b_then = LLVMGetInsertBlock(ctx.irb);

  // Terminate THEN (if needed)
  if (!LLVMGetBasicBlockTerminator(LLVMGetInsertBlock(ctx.irb))) {
  	LLVMBuildBr(ctx.irb, b_merge);
  } else {
    divergent_then = true;
  }

	// Realize OTHERWISE
  LLVMMoveBasicBlockAfter(b_otherwise, LLVMGetInsertBlock(ctx.irb));
  LLVMPositionBuilderAtEnd(ctx.irb, b_otherwise);
  if (otherwise) {
	  otherwise_handle = ir::transmute(otherwise, type)->value_of(ctx);
	  b_otherwise = LLVMGetInsertBlock(ctx.irb);

	  // Terminate OTHERWISE (if needed)
	  if (!LLVMGetBasicBlockTerminator(LLVMGetInsertBlock(ctx.irb))) {
	  	LLVMBuildBr(ctx.irb, b_merge);
	  } else {
      divergent_otherwise = true;
    }
	} else {
		// Terminate directly
		// NOTE: Easier then adjusting the algorithm
		LLVMBuildBr(ctx.irb, b_merge);
	}

  // Is the conditional divergent?
  auto divergent = divergent_then && divergent_otherwise;
  if (divergent) {
    // Remove the merge block
    LLVMDeleteBasicBlock(b_merge);
  } else {
    // Realize the merge block
    LLVMMoveBasicBlockAfter(b_merge, LLVMGetInsertBlock(ctx.irb));
    LLVMPositionBuilderAtEnd(ctx.irb, b_merge);
  }

  LLVMValueRef result = nullptr;
  if (!divergent) {
    // Result
    result = LLVMBuildPhi(ctx.irb, type->handle(ctx), "");
    LLVMAddIncoming(result, &then_handle, &b_then, 1);
    LLVMAddIncoming(result, &otherwise_handle, &b_otherwise, 1);
  }

  return result;
}
