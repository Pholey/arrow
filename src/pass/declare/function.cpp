// Copyright (c) 2014-2015 Ryan Leckey, All Rights Reserved.

// Distributed under the MIT License
// See accompanying file LICENSE

#include "arrow/pass/declare.hpp"

using arrow::pass::Declare;

void Declare::handle_function(ptr<ast::Function> x) {
  // Make: Function
  auto fn = make<ir::Function>(x, _ctx.modules.back(), x->name, nullptr);

  // Scope: put
  _ctx.scope->put(x, fn, fn->name);

  // Stack: push
  _ctx.function_s.push(fn.get());

  // Handle: Block
  fn->block = handle_block(x->block);

  // Stack: pop
  _ctx.function_s.pop();
}

void Declare::handle_extern_function(ptr<ast::ExternFunction> x) {
  // Make: Extern Function
  auto fn = make<ir::ExternFunction>(
    x, _ctx.modules.back(), x->name, nullptr);

  // Scope: put
  _ctx.scope->put(x, fn, fn->name);
}
