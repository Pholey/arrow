// Copyright © 2014-2016 Ryan Leckey, All Rights Reserved.

// Distributed under the MIT License
// See accompanying file LICENSE

#ifndef ARROW_IR_TYPE_STRING_H
#define ARROW_IR_TYPE_STRING_H

#include <memory>
#include <string>

#include "arrow/ir/type.hpp"

#define ARROW_TTAG_STRING __COUNTER__

namespace arrow {
namespace ir {

struct TypeString : Type {
  TypeString() : Node(nullptr), Type("str") {
  }

  virtual ~TypeString() noexcept;

  virtual unsigned tag() const noexcept {
    return ARROW_TTAG_STRING;
  }

  virtual LLVMTypeRef handle(GContext&) noexcept {
    return LLVMPointerType(LLVMInt8Type(), 0);
  }
};

}  // namespace ir
}  // namespace arrow

#endif  // ARROW_IR_TYPE_STRING_H
