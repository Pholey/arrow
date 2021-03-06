// Copyright © 2014-2016 Ryan Leckey, All Rights Reserved.

// Distributed under the MIT License
// See accompanying file LICENSE

#include "arrow/parser.hpp"
#include "arrow/log.hpp"

using arrow::Parser;

auto Parser::parse_str() -> ptr<ast::String> {
  // Expect: integer
  auto tok = expect<token::String>(token::Type::String);
  if (!tok) return nullptr;

  return std::make_shared<ast::String>(tok->span, tok->text);
}
