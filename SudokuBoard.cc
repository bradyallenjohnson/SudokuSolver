
/*
 * SudokuBoard.cc
 *
 *  Created on: Oct 26, 2013
 *      Author: Brady
 */

#include <iostream>
#include <algorithm>
#include <cmath>

#include "SudokuBoard.hh"

using namespace std;

SudokuBoard::SudokuBoard(int boardSize /*= DEFAULT_BOARD_SIZE*/) :
    boardSize_(boardSize)
{
  squareSize_ = (int) sqrt((double) boardSize);
  if(squareSize_*squareSize_ != boardSize)
  {
    cout << "Invalid row size specified" << endl;
    // TODO consider throwing an exception
  }

  board_.resize(boardSize_);
  for(int r = 0; r < boardSize_; ++r)
  {
    RowT &boardRow = board_[r];
    boardRow.resize(boardSize_);
  }

  resetBoard();
}

bool SudokuBoard::isRangeValid(int row, int col) const
{
  if(row > boardSize_ || row < 0)
  {
    cout << "ERROR, out of range board row access: [0.." << boardSize_
         << "] for row=" << row
         << endl;

    // TODO consider an exception instead
    return false;
  }

  if(col > boardSize_ || col < 0)
  {
    cout << "ERROR, out of range board column access: [0.." << boardSize_
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

  if(value > boardSize_ || value < 0)
  {
    cout << "Invalid value: " << value << endl;
    return;
  }

  RowT &boardRow = board_[row];
  boardRow[col] = value;
}

void SudokuBoard::resetBoard()
{
  for(int row = 0; row < boardSize_; ++row)
  {
    RowT &boardRow = board_[row];
    for(int col = 0; col < boardSize_; ++col)
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

  const RowT &rowValues = board_[row];
  copy(rowValues.begin(), rowValues.end(), rowData.begin());
}

void SudokuBoard::getColData(int col, std::vector<int> &colData) const
{
  if(!isRangeValid(0, col))
  {
    return;
  }

  for(int row = 0; row < boardSize_; ++row)
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

  int rowStart;
  for(int r = squareSize_; r <= boardSize_; r += squareSize_)
  {
    if(row < r)
    {
      rowStart = r;
      break;
    }
  }

  int colStart;
  for(int c = squareSize_; c <= boardSize_; c += squareSize_)
  {
    if(col < c)
    {
      colStart = c;
      break;
    }
  }

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

  for(int row = 0; row < boardSize_; ++row)
  {
    const RowT &boardRow = board_[row];
    for(int col = 0; col < boardSize_; ++col)
    {
      cout << boardRow[col] << " ";
      if((col+1)%squareSize_ == 0 && (col+1) < boardSize_)
      {
    	  cout << "| ";
      }
    }

    if((row+1)%squareSize_ == 0 && (row+1) < boardSize_)
    {
      cout << "\n------+-------+------";
    }
    cout << endl;
  }

  cout << endl;
}
