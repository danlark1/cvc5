/******************************************************************************
 * Top contributors (to current version):
 *   Andrew Reynolds, Gereon Kremer, Aina Niemetz
 *
 * This file is part of the cvc5 project.
 *
 * Copyright (c) 2009-2023 by the authors listed in the file AUTHORS
 * in the top-level source directory and their institutional affiliations.
 * All rights reserved.  See the file COPYING in the top-level source
 * directory for licensing information.
 * ****************************************************************************
 *
 * Arithmetic theory state.
 */

#include "cvc5_private.h"

#ifndef CVC5__THEORY__ARITH__ARITH_STATE_H
#define CVC5__THEORY__ARITH__ARITH_STATE_H

#include "theory/theory_state.h"

namespace cvc5::internal {
namespace theory {
namespace arith {

namespace linear {
class TheoryArithPrivate;
}

/**
 * The arithmetic state.
 *
 * Note this object is intended to use TheoryArithPrivate
 * as a black box, and moreover the internals of TheoryArithPrivate will not
 * be refactored to use this state. Instead, the main theory solver TheoryArith
 * will be refactored to be a standard layer on top of TheoryArithPrivate,
 * which will include using this state in the standard way.
 */
class ArithState : public TheoryState
{
 public:
  ArithState(Env& env,
             Valuation val);
  ~ArithState() {}
  /** Are we currently in conflict? */
  bool isInConflict() const override;
  /** Set parent */
  void setParent(linear::TheoryArithPrivate* p);

 private:
  /** reference to parent */
  linear::TheoryArithPrivate* d_parent;
};

}  // namespace arith
}  // namespace theory
}  // namespace cvc5::internal

#endif
