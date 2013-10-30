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
  cout << "solveRecursive [" << row << ", " << col << "]" << endl;

  // Check if we're at the end of a row, or if we've completed the Sudoku
  if(col == board_.getBoardSize())
  {
    // If we're at the end of a row, start at the next row
    col = 0;
    if(row == board_.getBoardSize()-1)
    {
      // Then we've finished and a solution has been found
      cout << "solveRecursive Board finished" << endl;
      return true;
    }
    else
    {
      ++row;
    }
    cout << "solveRecursive end of row, reset coords [" << row << ", " << col << "]" << endl;
  }

  // Skip already filled-in elements
  if(board_.getValue(row, col) != 0)
  {
    cout << "solveRecursive [" << row << ", " << col << "] skipping filled-in value" << endl;

    return solveRecursive(row, col+1);
  }

  for(int value = 1; value <= board_.getBoardSize(); ++value)
  {
    if(valueIsValid(row, col, value))
    {
      cout << "solveRecursive [" << row << ", " << col << "] valid value " << value << endl;

      board_.setValue(row, col, value);

      // If the value is valid, recurse down, else loop to the next value
      if(solveRecursive(row, col+1))
      {
        return true;
      }

      board_.setValue(row, col, 0);
    }
  }

  cout << "solveRecursive end [" << row << ", " << col << "]" << endl;
  board_.setValue(row, col, 0);
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

  if(squareHasValue(row, col, value))
  {
    return false;
  }

  return true;
}

bool SudokuSolver::rowHasValue(int row, int value)
{
  for(int i = 0; i < board_.getBoardSize(); ++i)
  {
    if(board_.getValue(row, i) == value)
    {
      return true;
    }
  }

  return false;
}

bool SudokuSolver::colHasValue(int col, int value)
{
  for(int i = 0; i < board_.getBoardSize(); ++i)
  {
    if(board_.getValue(i, col) == value)
    {
      return true;
    }
  }

  return false;
}

bool SudokuSolver::squareHasValue(int row, int col, int value)
{
  // TODO consider storing the rowStart and colStart in a hash table
  //      where the offset will return the rowStart

  int rowStart;
  for(int r = board_.getSquareSize(); r <= board_.getBoardSize(); r += board_.getSquareSize())
  {
    if(row < r)
    {
      rowStart = r;
      break;
    }
  }

  int colStart;
  for(int c = board_.getSquareSize(); c <= board_.getBoardSize(); c += board_.getSquareSize())
  {
    if(col < c)
    {
      colStart = c;
      break;
    }
  }

  for(int r = rowStart; r < rowStart+board_.getSquareSize(); ++r)
  {
    for(int c = colStart; c < colStart+board_.getSquareSize(); ++c)
    {
      if(board_.getValue(row, col) == value)
      {
        return true;
      }
    }
  }

  return false;
}

