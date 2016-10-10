// Copyright © 2014-2016 Ryan Leckey, All Rights Reserved.

// Distributed under the MIT License
// See accompanying file LICENSE

#ifndef ARROW_IR_TYPE_POINTER_H
#define ARROW_IR_TYPE_POINTER_H

#include <memory>
#include <string>
#include <sstream>

#include "arrow/ir/type.hpp"

#define ARROW_TTAG_POINTER __COUNTER__

namespace arrow {
namespace ir {

struct TypePointer : Type {
  explicit TypePointer(ptr<ast::Node> source, ptr<Type> element)
    : Node(source), Type(TypePointer::_name(element)), element(element) {
  }

  virtual ~TypePointer() noexcept;

  virtual unsigned tag() const noexcept {
    return ARROW_TTAG_POINTER;
  }

  virtual LLVMTypeRef handle(GContext& ctx) noexcept {
    return LLVMPointerType(element->handle(ctx), 0);
  }

  ptr<Type> element;

 private:
  static std::string _name(ptr<Type> element) {
    std::stringstream stream;
    stream << "*";
    stream << element->name;

    return stream.str();
  }
};

}  // namespace ir
}  // namespace arrow

#endif  // ARROW_IR_TYPE_POINTER_H
