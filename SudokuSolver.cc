/*
 * SudokuSolver.cc
 *
 *  Created on: Oct 26, 2013
 *      Author: Brady
 */

#include <vector>
#include <iostream>

#include "SudokuBoard.hh"
#include "SudokuSolver.hh"

using namespace std;

bool SudokuSolver::isBoardValid(SudokuBoard &board)
{


  // First check the rows
  for(int r = 0; r < board.getNumRows(); ++r)
  {
	  // The vector values will be reset to 0 upon creation
	  vector<bool> values(board.getNumRows(), false);
	  for(int c = 0; c < board.getNumRows(); ++c)
	  {
		  int value = board.getPosition(r, c);
		  if(value == 0)
		  {
            // '0' is empty
            continue;
		  }
		  if(values[value])
		  {
			  cout << "Invalid Sudoku Board: value=" << value
                   << " in position [" << r << ", " << c
                   << "] has already been set in this row" << endl;
			  return false;
		  }
		  values[value] = true;
	  }
  }

  // Now check the columns
  for(int c = 0; c < board.getNumRows(); ++c)
  {
	  // The vector values will be reset to 0 upon creation
	  vector<bool> values(board.getNumRows(), false);
	  for(int r = 0; r < board.getNumRows(); ++r)
	  {
		  int value = board.getPosition(r, c);
		  if(value == 0)
		  {
            // '0' is empty
            continue;
		  }
		  if(values[value])
		  {
			  cout << "Invalid Sudoku Board: value=" << value
                   << " in position [" << r << ", " << c
                   << "] has already been set in this column" << endl;
			  return false;
		  }
		  values[value] = true;
	  }
  }

  // And finally in the square
  // TODO finish this

  return true;
}

bool SudokuSolver::solve(SudokuBoard &board)
{
  return false;
}

