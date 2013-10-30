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

bool SudokuSolver::isBoardValid()
{
  // First check the rows
  for(int r = 0; r < board_.getBoardSize(); ++r)
  {
    // The vector values will be reset to 0 upon creation
    vector<bool> values(board_.getBoardSize(), false);
    for(int c = 0; c < board_.getBoardSize(); ++c)
    {
      int value = board_.getValue(r, c);
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
  for(int c = 0; c < board_.getBoardSize(); ++c)
  {
    // The vector values will be reset to 0 upon creation
    vector<bool> values(board_.getBoardSize(), false);
    for(int r = 0; r < board_.getBoardSize(); ++r)
    {
      int value = board_.getValue(r, c);
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
  for(int rowGroup = 0; rowGroup < board_.getSquareSize(); ++rowGroup)
  {
    for(int colGroup = 0; colGroup < board_.getSquareSize(); ++colGroup)
    {
      // The vector values will be reset to 0 upon creation
      vector<bool> values(board_.getBoardSize(), false);

      // Iterate the square rows: sr
      for(int sr = rowGroup*board_.getSquareSize(); sr < (rowGroup*board_.getSquareSize())+board_.getSquareSize(); ++sr)
      {
        // Iterate the square columns: sc
        for(int sc = colGroup*board_.getSquareSize(); sc < (colGroup*board_.getSquareSize())+board_.getSquareSize(); ++sc)
        {
          int value = board_.getValue(sr, sc);
          if(value == 0)
          {
            // '0' is empty
            continue;
          }
          if(values[value])
          {
            cout << "Invalid Sudoku Board: value=" << value
                 << " in position [" << sr << ", " << sc
                 << "] has already been set in this square" << endl;
            return false;
          }
          values[value] = true;
        }
      }
    }
  }

  return true;
}

// Orchestrates the recursion
bool SudokuSolver::solve()
{
  return solveRecursive(0, 0);
}

// Recursively solve the Sudoku
bool SudokuSolver::solveRecursive(int row, int col)
{
  // Check if we're at the end of a row, or if we've completed the Sudoku
  if(col == board_.getBoardSize())
  {
    // If we're at the end of a row, start at the next row
    col = 0;
    if(row == board_.getBoardSize())
    {
      // Then we've finished and a solution has been found
      return true;
    }
    else
    {
      ++row;
    }
  }

  // Skip empty elements
  if(board_.getValue(row, col) == 0)
  {
    return solveRecursive(row, col+1);
  }

  for(int value = 1; value < board_.getBoardSize(); ++value)
  {
    if(valueIsValid(row, col, value))
    {
        board_.setValue(row, col, value);
        return solveRecursive(row, col++);
    }
    else
    {
      return false;
    }
  }

  // TODO finish this

  return false;
}

bool SudokuSolver::valueIsValid(int row, int col, int value)
{
  if(rowHasValue(row, value))
  {
    return false;
  }

  if(colHasValue(col, value))
  {
    return false;
  }

  if(!squareHasValue(row, col, value))
  {
    return false;
  }

  return true;
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

