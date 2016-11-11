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
IMPL(Path)
IMPL(Name)
IMPL(Tuple)

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
IMPL(BitLeftShift)
IMPL(BitRightShift)

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

IMPL(AssignAdd)
IMPL(AssignSub)
IMPL(AssignMul)
IMPL(AssignDiv)
IMPL(AssignMod)
IMPL(AssignBitAnd)
IMPL(AssignBitXor)
IMPL(AssignBitOr)
IMPL(AssignBitLeftShift)
IMPL(AssignBitRightShift)

IMPL(Type)
IMPL(TypeName)
IMPL(TypePath)
IMPL(TypePointer)
IMPL(TypeAlias)
IMPL(TypeUnit)
IMPL(TypeFunction)
IMPL(TypeTuple)

IMPL(Function)
IMPL(ExternFunction)
IMPL(ExternVariable)
IMPL(Parameter)
IMPL(TypeParameter)
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

IMPL(Transmute)
