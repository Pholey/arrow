// Copyright (c) 2014-2015 Ryan Leckey, All Rights Reserved.

// Distributed under the MIT License
// See accompanying file LICENSE

#include "arrow/middle/build.hpp"

using arrow::middle::Build;

auto Build::handle_int(ptr<ast::Integer> x) -> ptr<ir::Value> {
  return make<ir::Integer>(x->value);
}
