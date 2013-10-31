/*
 * SudokuSolver.hh
 *
 *  Created on: Oct 26, 2013
 *      Author: Brady
 */

#ifndef SUDOKUSOLVER_HH_
#define SUDOKUSOLVER_HH_

#include <vector>

#include "SudokuBoard.hh"

class SudokuSolver
{
public:
  SudokuSolver(SudokuBoard &board);
  ~SudokuSolver() {}

  // Checks that no values are repeated in the rows, columns, and squares
  bool isBoardValid();
  bool solve();

protected:
  SudokuSolver(); // explicitly disallowing the default ctor

  bool solveRecursive(int row, int col);

  bool valueIsValid(int row, int col, int value);
  bool rowHasValue(int row, int value);
  bool colHasValue(int col, int value);
  bool squareHasValue(int row, int col, int value);

  SudokuBoard &board_;
  std::vector<int> squarePositionHash_;
};

#endif /* SUDOKUSOLVER_HH_ */
