
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

void SudokuBoard::printBoard() const
{
  cout << endl;

  //cout << "(\'0\' is an empty position)" << endl;

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
      cout << endl;
      for(int i = 0; i < boardSize_/squareSize_; ++i)
      {
        for(int j = 0; j < squareSize_; ++j)
        {
          cout << "--";
        }
        if(i != boardSize_/squareSize_-1)
        {
          cout << "+";
        }
      }
    }
    cout << endl;
  }

  cout << endl;
}
