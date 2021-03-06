// Copyright © 2014-2016 Ryan Leckey, All Rights Reserved.

// Distributed under the MIT License
// See accompanying file LICENSE

#include <string>

#include "arrow/token.hpp"

using arrow::token::Token;
using arrow::token::Integer;
using arrow::token::Real;
using arrow::token::Symbol;
using arrow::token::Keyword;
using arrow::token::Identifier;
using arrow::token::String;

Token::Token(Type type, Span span) noexcept : type(type), span(span) {
}

Token::~Token() noexcept {
}

Integer::Integer(Span span, const std::string& text, unsigned base) :
  Token(Type::Integer, span), value(text, base) {
}

Integer::~Integer() noexcept {
}

Real::Real(Span span, long double value) :
  Token(Type::Real, span), value(value) {
}

Real::~Real() noexcept {
}

Keyword::Keyword(Type type, Span span) :
  Token(type, span) {
}

Keyword::~Keyword() noexcept {
}

Symbol::Symbol(Type type, Span span) :
  Token(type, span) {
}

Symbol::~Symbol() noexcept {
}

Identifier::Identifier(Span span, std::string text) :
  Token(Type::Identifier, span), text(text) {
}

Identifier::~Identifier() noexcept {
}

String::String(Span span, std::string text) :
  Token(Type::String, span), text(text) {
}

String::~String() noexcept {
}

std::ostream& arrow::token::operator<<(
  std::ostream &os, const Type &type
) {
  switch (type) {
  case Type::End:                            return os << "end";

  case Type::Integer:                        return os << "integer";
  case Type::Real:                           return os << "real";
  case Type::Identifier:                     return os << "identifier";
  case Type::String:                         return os << "string";

  case Type::And:                            return os << "`and`";
  case Type::Or:                             return os << "`or`";
  case Type::Not:                            return os << "`not`";
  case Type::Let:                            return os << "`let`";
  case Type::Mutable:                        return os << "`mutable`";
  case Type::Def:                            return os << "`def`";
  case Type::Extern:                         return os << "`extern`";
  case Type::True:                           return os << "`true`";
  case Type::False:                          return os << "`false`";
  case Type::If:                             return os << "`if`";
  case Type::Unless:                         return os << "`unless`";
  case Type::Else:                           return os << "`else`";
  case Type::Loop:                           return os << "`loop`";
  case Type::While:                          return os << "`while`";
  case Type::For:                            return os << "`for`";
  case Type::Until:                          return os << "`until`";
  case Type::Break:                          return os << "`break`";
  case Type::Continue:                       return os << "`continue`";
  case Type::Return:                         return os << "`return`";
  case Type::Global:                         return os << "`global`";
  case Type::As:                             return os << "`as`";
  case Type::Struct:                         return os << "`struct`";
  case Type::Underscore:                     return os << "`_`";
  case Type::Import:                         return os << "`import`";
  case Type::Type:                           return os << "`type`";
  case Type::Implement:                      return os << "`implement`";
  case Type::Interface:                      return os << "`interface`";
  case Type::Self:                           return os << "`self`";

  case Type::Plus:                           return os << "`+`";
  case Type::Minus:                          return os << "`-`";
  case Type::Slash:                          return os << "`/`";
  case Type::Asterisk:                       return os << "`*`";
  case Type::Percent:                        return os << "`%`";
  case Type::Ampersand:                      return os << "`&`";
  case Type::Pipe:                           return os << "`|`";
  case Type::Caret:                          return os << "`^`";
  case Type::Tilde:                          return os << "`~`";
  case Type::ExclamationMark:                return os << "`!`";
  case Type::Equals:                         return os << "`=`";
  case Type::LessThan:                       return os << "`<`";
  case Type::GreaterThan:                    return os << "`>`";
  case Type::Period:                         return os << "`.`";
  case Type::Colon:                          return os << "`:`";
  case Type::Semicolon:                      return os << "`;`";
  case Type::LeftBrace:                      return os << "`{`";
  case Type::RightBrace:                     return os << "`}`";
  case Type::LeftParenthesis:                return os << "`(`";
  case Type::RightParenthesis:               return os << "`)`";
  case Type::LeftBracket:                    return os << "`[`";
  case Type::RightBracket:                   return os << "`]`";
  case Type::Comma:                          return os << "`,`";
  case Type::Octothorpe:                     return os << "`#`";

  case Type::LeftArrow:                      return os << "`->`";
  case Type::Plus_Equals:                    return os << "`+=`";
  case Type::Minus_Equals:                   return os << "`-=`";
  case Type::Asterisk_Equals:                return os << "`*=`";
  case Type::Slash_Equals:                   return os << "`/=`";
  case Type::Percent_Equals:                 return os << "`%=`";
  case Type::Ampersand_Equals:               return os << "`&=`";
  case Type::Pipe_Equals:                    return os << "`|=`";
  case Type::Caret_Equals:                   return os << "`^=`";
  case Type::Equals_Equals:                  return os << "`==`";
  case Type::ExclamationMark_Equals:         return os << "`!=`";
  case Type::GreaterThan_Equals:             return os << "`>=`";
  case Type::LessThan_Equals:                return os << "`<=`";
  case Type::GreaterThan_GreaterThan:        return os << "`>>`";
  case Type::LessThan_LessThan:              return os << "`<<`";

  case Type::Ellipsis:                       return os << "`...`";
  case Type::LessThan_LessThan_Equals:       return os << "`<<=`";
  case Type::GreaterThan_GreaterThan_Equals: return os << "`>>=`";

  default:
    // Do nothing
    return os;
  }
}
