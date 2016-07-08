// Copyright © 2014-2016 Ryan Leckey, All Rights Reserved.

// Distributed under the MIT License
// See accompanying file LICENSE

#include "arrow/parser.hpp"
#include "arrow/log.hpp"

using arrow::Parser;

auto Parser::parse_float() -> ptr<ast::Float> {
  // Expect: integer
  auto tok = expect<token::Float>(token::Type::Float);
  if (!tok) return nullptr;

  return std::make_shared<ast::Float>(tok->span, tok->value);
}
