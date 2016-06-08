// Copyright (c) 2014-2015 Ryan Leckey, All Rights Reserved.

// Distributed under the MIT License
// See accompanying file LICENSE

// HACK: llvm.hpp must be included BEFORE mach7.hpp because of madness
#include "llvm.hpp"

#ifndef ARROW_MACH7_H
#define ARROW_MACH7_H

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wvla"

#include "mach7/type_switchN-patterns-xtl.hpp"
#include "mach7/patterns/constructor.hpp"

#pragma GCC diagnostic pop

#endif  // ARROW_MACH7_H
