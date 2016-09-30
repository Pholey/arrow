// Copyright (c) 2014-2015 Ryan Leckey, All Rights Reserved.

// Distributed under the MIT License
// See accompanying file LICENSE

#include "arrow/pass/declare.hpp"

using arrow::pass::Declare;

void Declare::visit_function(ptr<ast::Function> x) {
  // Make: Function
  auto fn = make<ir::Function>(x, _ctx.modules.back(), x->name, nullptr);

  // Scope: put
  _ctx.scope->put(x, fn, fn->name);

  // Stack: push
  _ctx.function_s.push(fn.get());

  // HACK: Can't use the generic block as I need to insert parameters
  //       into the scope BEFORE the block runs but after its created (?)

  // Declaring a block just creates it
  fn->block = make<ir::Block>(x->block, _ctx.scope);

  // Add block to scope for later get
  _ctx.scope->put(x->block, fn->block, "");

  // Scope: Enter
  auto sb = ir::Scope::enter(fn->block->scope, _ctx);

  // Iterate through each named parameter ..
  for (auto& param : x->parameters) {
    // Make: parameter
    auto p = make<ir::Parameter>(param, param->name);
    _ctx.scope->put(param, p, p->name);

    // Push to function vector
    fn->parameters.push_back(p);
  }

  // Iterate through each statement ..
  for (auto& statement : x->block->statements) accept(statement);

  // Scope: Exit
  sb.exit();

  // Stack: pop
  _ctx.function_s.pop();
}

void Declare::visit_extern_function(ptr<ast::ExternFunction> x) {
  // Make: Extern Function
  auto fn = make<ir::ExternFunction>(
    x, _ctx.modules.back(), x->name, nullptr);

  // Scope: put
  _ctx.scope->put(x, fn, fn->name);
}
