// Copyright © 2014-2016 Ryan Leckey, All Rights Reserved.

// Distributed under the MIT License
// See accompanying file LICENSE

#ifndef ARROW_BUILD_H
#define ARROW_BUILD_H

#include <memory>
#include <string>

#include "arrow/pass.hpp"

namespace arrow {
namespace pass {

class Build : public Pass {
 public:
  using Pass::Pass;

  ptr<ir::Value> run(ptr<ast::Node>);

 private:
  ptr<ir::Value> handle_module(ptr<ast::Module>);
  ptr<ir::Value> handle_variable(ptr<ast::Variable>);
  ptr<ir::Value> handle_function(ptr<ast::Function>);

  ptr<ir::Value> handle_identity(ptr<ast::Identity>);
  ptr<ir::Value> handle_negate(ptr<ast::Negate>);

  ptr<ir::Value> handle_add(ptr<ast::Add>);
  ptr<ir::Value> handle_sub(ptr<ast::Sub>);
  ptr<ir::Value> handle_mul(ptr<ast::Mul>);
  ptr<ir::Value> handle_div(ptr<ast::Div>);
  ptr<ir::Value> handle_mod(ptr<ast::Mod>);
  ptr<ir::Value> handle_assign(ptr<ast::Assign>);
  ptr<ir::Value> handle_call(ptr<ast::Call>);
  ptr<ir::Value> handle_argument(ptr<ast::Argument>);
  ptr<ir::Value> handle_return(ptr<ast::Return>);

  ptr<ir::Value> handle_bit_not(ptr<ast::BitNot>);
  ptr<ir::Value> handle_bit_and(ptr<ast::BitAnd>);
  ptr<ir::Value> handle_bit_or(ptr<ast::BitOr>);
  ptr<ir::Value> handle_bit_xor(ptr<ast::BitXor>);

  ptr<ir::Value> handle_id(ptr<ast::Identifier>);
  ptr<ir::Value> handle_bool(ptr<ast::Boolean>);
  ptr<ir::Value> handle_int(ptr<ast::Integer>);
  ptr<ir::Value> handle_real(ptr<ast::Real>);

  ptr<ir::Value> handle_expression_statement(ptr<ast::ExpressionStatement>);

  // Reduce two types using type coercion rules
  ptr<ir::Type> _type_reduce(ptr<ir::Type> a, ptr<ir::Type> b);
};

}  // namespace back
}  // namespace arrow

#endif  // ARROW_BUILD_H
