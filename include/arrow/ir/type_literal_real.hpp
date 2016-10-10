// Copyright © 2014-2016 Ryan Leckey, All Rights Reserved.

// Distributed under the MIT License
// See accompanying file LICENSE

#ifndef ARROW_IR_TYPE_LITERAL_REAL_H
#define ARROW_IR_TYPE_LITERAL_REAL_H

#include <memory>
#include <string>
#include <sstream>

#include "arrow/ir/type.hpp"

#define ARROW_TTAG_LITERAL_REAL __COUNTER__

namespace arrow {
namespace ir {

struct TypeLiteralReal : Type {
  TypeLiteralReal() : Node(nullptr), Type("float64") {
  }

  virtual ~TypeLiteralReal() noexcept;

  virtual unsigned tag() const noexcept {
    return ARROW_TTAG_LITERAL_REAL;
  }

  virtual LLVMTypeRef handle(GContext&) noexcept {
    return LLVMDoubleType();
  }

  virtual bool is_real() const { return true; }
};

}  // namespace ir
}  // namespace arrow

#endif  // ARROW_IR_TYPE_LITERAL_REAL_H
