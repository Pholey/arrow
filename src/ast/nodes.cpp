// Copyright © 2014-2016 Ryan Leckey, All Rights Reserved.

// Distributed under the MIT License
// See accompanying file LICENSE

#include "arrow/ast/nodes.hpp"

#define IMPL(N) \
  N::~N() noexcept { }

using namespace arrow::ast;

IMPL(Node)
IMPL(Unary)
IMPL(Binary)

IMPL(Statement)
IMPL(Module)
IMPL(Variable)
IMPL(ExpressionStatement)
IMPL(Block)

IMPL(Expression)
IMPL(Integer)
IMPL(Real)
IMPL(Boolean)
IMPL(String)
IMPL(Unit)
IMPL(Identifier)

IMPL(Identity)
IMPL(Negate)

IMPL(BitNot)

IMPL(Not)

IMPL(Add)
IMPL(Sub)
IMPL(Mul)
IMPL(Div)
IMPL(Mod)

IMPL(BitOr)
IMPL(BitXor)
IMPL(BitAnd)

IMPL(Indirect)
IMPL(AddressOf)

IMPL(EqualTo)
IMPL(NotEqualTo)
IMPL(GreaterThanOrEqualTo)
IMPL(GreaterThan)
IMPL(LessThanOrEqualTo)
IMPL(LessThan)

IMPL(And)
IMPL(Or)

IMPL(Assign)

IMPL(Type)
IMPL(TypeName)
IMPL(TypePointer)
IMPL(TypeAlias)
IMPL(TypeUnit)

IMPL(Function)
IMPL(ExternFunction)
IMPL(Parameter)
IMPL(Call)
IMPL(Argument)
IMPL(Return)
IMPL(Import)

IMPL(CInclude)

IMPL(Conditional)
IMPL(Branch)
IMPL(Repeat)
IMPL(Break)
IMPL(Continue)
