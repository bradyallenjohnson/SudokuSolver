/*
 * SudokuSolver.hh
 *
 *  Created on: Oct 26, 2013
 *      Author: Brady
 */

#ifndef SUDOKUSOLVER_HH_
#define SUDOKUSOLVER_HH_

#include "SudokuBoard.hh"

class SudokuSolver
{
public:
  SudokuSolver()  {}
  ~SudokuSolver() {}

  // Checks that no values are repeated in the rows, columns, and squares
  bool isBoardValid(SudokuBoard &board);
  bool solve(SudokuBoard &board);
};

#endif /* SUDOKUSOLVER_HH_ */
