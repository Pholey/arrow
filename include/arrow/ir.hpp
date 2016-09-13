// Copyright © 2014-2016 Ryan Leckey, All Rights Reserved.

// Distributed under the MIT License
// See accompanying file LICENSE

#ifndef ARROW_IR_H
#define ARROW_IR_H

#include "llvm.hpp"

#include "arrow/ir/item.hpp"
#include "arrow/ir/module.hpp"
#include "arrow/ir/variable.hpp"
#include "arrow/ir/function.hpp"

#include "arrow/ir/type.hpp"
#include "arrow/ir/type_integer.hpp"
#include "arrow/ir/type_boolean.hpp"
#include "arrow/ir/type_function.hpp"
#include "arrow/ir/type_real.hpp"
#include "arrow/ir/type_literal_integer.hpp"
#include "arrow/ir/type_literal_real.hpp"

#include "arrow/ir/value.hpp"
#include "arrow/ir/transmute.hpp"
#include "arrow/ir/integer.hpp"
#include "arrow/ir/real.hpp"
#include "arrow/ir/boolean.hpp"
#include "arrow/ir/binary.hpp"
#include "arrow/ir/unary.hpp"
#include "arrow/ir/call.hpp"
#include "arrow/ir/return.hpp"

#include "arrow/ir/scope.hpp"

#endif  // ARROW_IR_H
