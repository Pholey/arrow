// Copyright © 2014-2016 Ryan Leckey, All Rights Reserved.

// Distributed under the MIT License
// See accompanying file LICENSE

#include <boost/filesystem.hpp>

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include "arrow/parser.hpp"
#include "arrow/log.hpp"

using arrow::Parser;
namespace fs = boost::filesystem;

Parser::Parser(
  std::shared_ptr<std::istream> is, const std::string& filename
) : _t(is, filename) {
}

auto Parser::parse() -> std::shared_ptr<ast::Node> {
  // Declare the top-level, automatic module
  // The name of the module is built from the name of the given file
  auto stem = fs::path(_t._filename).stem().string();
  auto mod = std::make_shared<ast::Module>(Span(_t._filename), stem);

  // Attempt to match statements until the end of the stream
  while (!_t.empty()) {
    // Parse a statement (try)
    auto statement = parse_statement();
    if (statement) {
      // Add it to the module
      mod->statements.push_back(statement);
    }
  }

  return mod;
}

auto Parser::expect(token::Type type) -> std::shared_ptr<token::Token> {
  return expect({type});
}

auto Parser::expect(
  std::initializer_list<token::Type> types
) -> std::shared_ptr<token::Token> {
  std::vector<token::Type> types_v(types);
  auto tok = _t.pop();

  if (std::find(types_v.begin(), types_v.end(), tok->type) == types_v.end()) {
    if (types_v.size() == 1) {
      Log::get().error("expected {}, found {}", types_v[0], tok->type);
    } else {
      std::stringstream msg;
      msg << "expected one of ";

      unsigned index = 0;
      for (auto& type : types_v) {
        msg << type;
        if (index != 0) {
          msg << ", ";
        }

        index += 1;
      }

      msg << "; found " << tok->type;
      Log::get().error(msg.str().c_str());
    }


    return nullptr;
  }

  return tok;
}
