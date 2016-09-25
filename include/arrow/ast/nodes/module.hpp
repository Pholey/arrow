// Copyright © 2014-2016 Ryan Leckey, All Rights Reserved.

// Distributed under the MIT License
// See accompanying file LICENSE

#ifndef ARROW_AST_MODULE_H
#define ARROW_AST_MODULE_H

#include <string>
#include <vector>

#include "arrow/ptr.hpp"
#include "arrow/ast/nodes/statement.hpp"
#include "arrow/ast/nodes/block.hpp"

namespace arrow {
namespace ast {

struct Module : Statement {
  Module(Span span, std::string name, ptr<Block> block)
  : Statement(span), name(name), block(block) {
  }

  virtual ~Module() noexcept;

  /// Name of the module.
  /// This is inferred from the filename in case of an automatic module, but
  /// is speicifed directly for an explicitly declared module.
  std::string name;

  /// A module is made up of 0..n statements.
  ptr<Block> block;
};

}  // namespace ast
}  // namespace arrow

#endif  // ARROW_AST_MODULE_H
