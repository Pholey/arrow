// Copyright © 2014-2016 Ryan Leckey, All Rights Reserved.

// Distributed under the MIT License
// See accompanying file LICENSE

#include "arrow/parser.hpp"
#include "arrow/log.hpp"

using arrow::Parser;

auto Parser::parse_variable() -> std::shared_ptr<ast::Variable> {
  // Expect: `let`
  auto initial_tok = expect(token::Type::Let);
  if (!initial_tok) return nullptr;

  // Expect: identifier
  auto id = expect<token::Identifier>(token::Type::Identifier);
  if (!id) return nullptr;

  // Check for `=` (which would indicate an initializer)
  std::shared_ptr<ast::Expression> initializer;
  if (_t.peek()->type == token::Type::Equals) {
    _t.pop();

    // Expect: Expression
    initializer = parse_expression();
    if (!initializer) return nullptr;
  }

  // Expect: `;`
  auto last_tok = expect(token::Type::Semicolon);
  if (!last_tok) return nullptr;

  return std::make_shared<ast::Variable>(
    initial_tok->span.extend(last_tok->span), id->text, nullptr, initializer);
}
