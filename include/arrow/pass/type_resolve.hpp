// Copyright © 2014-2016 Ryan Leckey, All Rights Reserved.

// Distributed under the MIT License
// See accompanying file LICENSE

#ifndef ARROW_TYPE_RESOLVE_H
#define ARROW_TYPE_RESOLVE_H

#include <memory>
#include <string>

#include "arrow/pass.hpp"
#include "arrow/ast/visitor.hpp"

namespace arrow {
namespace pass {

class TypeResolve : public ast::Visitor, public Pass {
 public:
  using Pass::Pass;

  virtual void run(ptr<ast::Node>);

 private:
  struct Assign { ptr<ir::Type> type; };
  struct Use { ptr<ir::Type> type; };

  std::vector<ptr<ir::Variable>> _declare;
  std::unordered_map<ir::Variable*, std::vector<Assign>> _assigns;
  std::unordered_map<ir::Variable*, std::vector<Use>> _uses;

  void visit_module(ptr<ast::Module>);
  void visit_block(ptr<ast::Block>);
  void visit_variable(ptr<ast::Variable>);
  void visit_assign(ptr<ast::Assign>);
  // void visit_function(ptr<ast::Function>);
  // void visit_extern_function(ptr<ast::ExternFunction>);
};

}  // namespace back
}  // namespace arrow

#endif  // ARROW_TYPE_RESOLVE_H
