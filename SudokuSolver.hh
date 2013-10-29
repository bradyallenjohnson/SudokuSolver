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
  SudokuSolver()  {}
  ~SudokuSolver() {}

  // Checks that no values are repeated in the rows, columns, and squares
  bool isBoardValid(SudokuBoard &board);
  bool solve(SudokuBoard &board);

private:
  bool solveRecursive(SudokuBoard &board);

  void boardDataToHash(std::vector<int> &data, std::vector<bool> &hash);
  bool rowHasValue(int row, int value);
  bool colHasValue(int col, int value);
  bool squareHasValue(int row, int col, int value);
};

#endif /* SUDOKUSOLVER_HH_ */
