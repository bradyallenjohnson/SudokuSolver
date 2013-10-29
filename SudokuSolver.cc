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
      int value = board.getValue(r, c);
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
      int value = board.getValue(r, c);
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

  // And finally in the squares
  int squareSize = board.getNumRows()/3;
  for(int rowGroup = 0; rowGroup < squareSize; ++rowGroup)
  {
    for(int colGroup = 0; colGroup < squareSize; ++colGroup)
    {
      // The vector values will be reset to 0 upon creation
      vector<bool> values(board.getNumRows(), false);

      // Iterate the square rows: sr
      for(int sr = rowGroup*3; sr < (rowGroup*3)+3; ++sr)
      {
        // Iterate the square columns: sc
        for(int sc = colGroup*3; sc < (colGroup*3)+3; ++sc)
        {
          int value = board.getValue(sr, sc);
          if(value == 0)
          {
            // '0' is empty
            continue;
          }
          if(values[value])
          {
            cout << "Invalid Sudoku Board: value=" << value
                   << " in position [" << sr << ", " << sc
                   << "] has already been set in this column" << endl;
            return false;
          }
          values[value] = true;
        }
      }
    }
  }

  return true;
}

bool SudokuSolver::solve(SudokuBoard &board)
{
  vector<int> rowValues(board.getNumRows(), 0);
  vector<vector<int> > colValues(board.getNumRows());
  vector<vector<int> > squareValues(board.getNumRows());

  vector<bool> rowValuesHash(board.getNumRows(), false);
  vector<vector<bool> > colValuesHash(board.getNumRows());
  vector<vector<bool> > squareValuesHash(board.getNumRows());

  return solveRecursive(board);
}

bool SudokuSolver::solveRecursive(SudokuBoard &board)
{
  for(int row = 0; row < board.getNumRows(); ++row)
  {
/*
    board.getRowData(row, rowValues);
    boardDataToHash(rowValues, rowValuesHash);
*/
    // TODO finish this
  }

  return false;
}

void SudokuSolver::boardDataToHash(vector<int> &rowValues, vector<bool> &rowValuesHash)
{
  for(int i = 0; i < rowValues.size(); ++i)
  {
    if(rowValues[i] != 0)
    {
      rowValuesHash[rowValues[i]] = true;
    }
  }
}

bool SudokuSolver::rowHasValue(int row, int value)
{
  return false;
}

bool SudokuSolver::colHasValue(int col, int value)
{
  return false;
}

bool SudokuSolver::squareHasValue(int row, int col, int value)
{
  return false;
}

