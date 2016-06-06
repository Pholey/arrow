// Copyright © 2014-2016 Ryan Leckey, All Rights Reserved.

// Distributed under the MIT License
// See accompanying file LICENSE

#include "mach7.hpp"
#include "arrow/ast/print.hpp"

using arrow::ast::Print;

void Print::print_variable(std::shared_ptr<Variable> n) {
  handle("Variable", n, [&, this] {
    _w.Key("name");
    _w.String(n->name.c_str());

    _w.Key("initializer");

    if (n->initializer) {
      print(n->initializer);
    } else {
      _w.Null();
    }
  });
}
