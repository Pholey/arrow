// Copyright (c) 2014-2015 Ryan Leckey, All Rights Reserved.

// Distributed under the MIT License
// See accompanying file LICENSE

#include "arrow/pass/build.hpp"

using arrow::pass::Build;

auto Build::handle_str(ptr<ast::String> x) -> ptr<ir::Value> {
  return make<ir::String>(x->value);
}
