// Copyright © 2014-2016 Ryan Leckey, All Rights Reserved.

// Distributed under the MIT License
// See accompanying file LICENSE

#ifndef ARROW_PASS_GENERATE_H
#define ARROW_PASS_GENERATE_H

#include "arrow/ptr.hpp"
#include "arrow/ir.hpp"
#include "llvm.hpp"

namespace arrow {

// Takes IR as input and will "generate" LLVM IR
class Generator {
 public:
  struct Context {
    // LLVM module context
    LLVMModuleRef mod;

    // LLVM instruction builder
    // Simplifies IR generation with LLVM
    LLVMBuilderRef irb;

    // LLVM target machine
    // Describes the target architecture
    LLVMTargetMachineRef target;
  };

  Generator();

  Generator(const Generator&) = delete;
  Generator(Generator&&) = delete;

  Generator& operator=(const Generator&) = delete;
  Generator& operator=(Generator&&) = delete;

  virtual ~Generator() noexcept;

  Generator& run(ptr<ir::Module> module);
  Generator& print();

 private:
  // Generation context.
  Context _ctx;

  void initialize();
};

}  // namespace arrow

#endif  // ARROW_PASS_GENERATE_H
