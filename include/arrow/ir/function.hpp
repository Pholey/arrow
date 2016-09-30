// Copyright © 2014-2016 Ryan Leckey, All Rights Reserved.

// Distributed under the MIT License
// See accompanying file LICENSE

#ifndef ARROW_IR_FUNCTION_H
#define ARROW_IR_FUNCTION_H

#include <vector>

#include "arrow/ir/item.hpp"
#include "arrow/ir/value.hpp"
#include "arrow/ir/type_function.hpp"
#include "arrow/ir/block.hpp"

namespace arrow {
namespace ir {

struct Module;
struct Function;

struct Parameter : Item, Value {
  Parameter(ptr<ast::Parameter> source, std::string name)
    : Node(source), Item(name), Value(nullptr) {
  }

  virtual ~Parameter() noexcept;

  virtual bool is_addressable() const {
    return true;
  }

  virtual LLVMValueRef handle(GContext&) noexcept {
    return _handle;
  }

 private:
  friend struct Function;

  // Slot
  LLVMValueRef _handle = nullptr;
};

struct Function : Item, Value {
  Function(ptr<ast::Function> source, ptr<Module> module, std::string name, ptr<TypeFunction> type)
    : Node(source), Item(name), Value(type), block(nullptr), parameters(), _module(module) {
  }

  virtual ~Function() noexcept;

  virtual LLVMValueRef handle(GContext&) noexcept;

  // Get mangled name (for linking and loading)
  std::string name_mangle() const;

  // Function block – body
  ptr<Block> block;

  // Function parameters
  std::vector<ptr<Parameter>> parameters;

 private:
  // Module (container)
  ptr<Module> _module;

  // Slot
  LLVMValueRef _handle = nullptr;
};

struct ExternFunction : Item, Value {
  ExternFunction(ptr<ast::ExternFunction> source, ptr<Module> module, std::string name, ptr<TypeExternFunction> type)
    : Node(source), Item(name), Value(type), _module(module) {
  }

  virtual ~ExternFunction() noexcept;

  virtual LLVMValueRef handle(GContext&) noexcept;

 private:
  // Module (container)
  ptr<Module> _module;

  // Slot
  LLVMValueRef _handle = nullptr;
};

}  // namespace ir
}  // namespace arrow

#endif  // ARROW_IR_FUNCTION_H
