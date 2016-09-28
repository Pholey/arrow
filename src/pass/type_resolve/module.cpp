// Copyright (c) 2014-2015 Ryan Leckey, All Rights Reserved.

// Distributed under the MIT License
// See accompanying file LICENSE

#include "arrow/pass/type_resolve.hpp"

using arrow::pass::TypeResolve;

void TypeResolve::visit_module(ptr<ast::Module> x) {
  // Get: Module
  auto module = _ctx.scope->get<ir::Module>(x);
  if (!module) return;

  // Block
  accept(x->block);
}
