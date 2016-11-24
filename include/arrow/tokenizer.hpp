// Copyright © 2014-2016 Ryan Leckey, All Rights Reserved.

// Distributed under the MIT License
// See accompanying file LICENSE

#ifndef ARROW_TOKENIZER_H
#define ARROW_TOKENIZER_H

#include <string>
#include <memory>
#include <deque>
#include <fstream>
#include <vector>
#include <sstream>
#include <functional>

#include "arrow/token.hpp"
#include "arrow/file.hpp"

namespace arrow {

class Tokenizer {
  using Token = token::Token;

 public:
  Tokenizer(ptr<std::istream> is, const std::string& filename);

  Tokenizer(const Tokenizer&) = delete;
  Tokenizer(Tokenizer&&) = delete;

  Tokenizer& operator=(const Tokenizer&) = delete;
  Tokenizer& operator=(Tokenizer&&) = delete;

  /// Peek (perserve) the next token and test if we are at the end
  /// of the input stream.
  bool empty() {
    return peek()->type == token::Type::End;
  }

  /// Peek (perserve) the token `offset` tokens away from the current position
  /// in the input stream.
  ptr<Token> peek(unsigned offset = 0);

  /// Push (prepend) a token in front of the input stream.
  void push(ptr<Token> token);

  /// Get (consume) the next token in the input stream.
  ptr<Token> pop();

 private:
  friend class Parser;

  bool _read(unsigned offset);

  bool _consume_line_comment();
  bool _consume_block_comment();
  void _consume_number(std::stringstream& ss, unsigned base);

  ptr<Token> _scan_numeric();
  ptr<Token> _scan_symbol();
  ptr<Token> _scan_identifier();
  ptr<Token> _scan_string();

  std::deque<ptr<Token>> _queue;
  std::vector<std::function<ptr<Token>()>> _scanners;
  File _file;
  std::string _filename;
};

}  // namespace arrow

#endif  // ARROW_TOKENIZER_H
