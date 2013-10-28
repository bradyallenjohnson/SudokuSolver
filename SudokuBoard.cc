
/*
 * SudokuBoard.cc
 *
 *  Created on: Oct 26, 2013
 *      Author: Brady
 */

#include <iostream>
#include <algorithm>

#include "SudokuBoard.hh"

using namespace std;

SudokuBoard::SudokuBoard(int rows /*= DEFAULT_ROWS*/) :
    numRows_(rows)
{
  if(rows%3 != 0)
  {
    cout << "Invalid row specified, must be a factor of 3" << endl;
    // TODO how to handle the error??
  }

  board_.resize(rows);
  for(int r = 0; r < rows; ++r)
  {
    RowT &boardRow = board_[r];
    boardRow.resize(rows);
  }

  resetBoard();
}

bool SudokuBoard::isRangeValid(int row, int col) const
{
  if(row > numRows_ || row < 0)
  {
    cout << "ERROR, out of range board row access: [0.." << numRows_
         << "] for row=" << row
         << endl;

    // TODO consider an exception instead
    return false;
  }

  if(col > numRows_ || col < 0)
  {
    cout << "ERROR, out of range board column access: [0.." << numRows_
         << "] for col=" << col
         << endl;

    // TODO consider an exception instead
    return false;
  }

  return true;
}

int SudokuBoard::getValue(int row, int col) const
{
  if(!isRangeValid(row, col))
  {
      return -1;
  }

  const RowT &boardRow = board_[row];

  return boardRow[col];
}

void SudokuBoard::setValue(int row, int col, int value)
{
  if(!isRangeValid(row, col))
  {
    return;
  }

  if(value > numRows_ || value < 0)
  {
    cout << "Invalid value: " << value << endl;
    return;
  }

  RowT &boardRow = board_[row];
  boardRow[col] = value;
}

void SudokuBoard::resetBoard()
{
  for(int row = 0; row < numRows_; ++row)
  {
    RowT &boardRow = board_[row];
    for(int col = 0; col < numRows_; ++col)
    {
      boardRow[col] = 0;
    }
  }
}

void SudokuBoard::getRowData(int row, std::vector<int> &rowData) const
{
  if(!isRangeValid(row, 0))
  {
    return;
  }

  const RowT &row = board_[row];
  copy(row.begin(), row.end(), rowData.begin());
}

void SudokuBoard::getColData(int col, std::vector<int> &colData) const
{
  if(!isRangeValid(0, col))
  {
    return;
  }

  for(int row = 0; row < numRows_; ++row)
  {
    colData[row] = getValue(row, col);
  }
}

// Given any position in a square, return the square
// data in the given vector, one row at a time
void SudokuBoard::getSquareData(int row, int col, std::vector<int> &squareData) const
{
  if(!isRangeValid(row, col))
  {
    return;
  }


  // TODO for now assuming 9x9 board

  int rowStart(0);
  if(row < 3)      { rowStart = 0; }
  else if(row < 6) { rowStart = 3; }
  else             { rowStart = 6; }

  int colStart(0);
  if(col < 3)      { colStart = 0; }
  else if(col < 6) { colStart = 3; }
  else             { colStart = 6; }

  int index(0);
  for(int r = rowStart; r < rowStart+3; ++r)
  {
    for(int c = colStart; c < colStart+3; ++c)
    {
      squareData[row] = getValue(row, col);
    }
  }
}

void SudokuBoard::printBoard() const
{
  cout << endl;

  for(int row = 0; row < numRows_; ++row)
  {
    const RowT &boardRow = board_[row];
    for(int col = 0; col < numRows_; ++col)
    {
      cout << boardRow[col] << " ";
      if(col == 2 || col == 5)
      {
    	  cout << "| ";
      }
    }
    if(row == 2 || row == 5)
    {
      cout << "\n------+-------+------";
    }
    cout << endl;
  }

  cout << endl;
}
