
#include <iostream>

#include "SudokuBoard.hh"

using namespace std;

SudokuBoard::SudokuBoard(int rows /*= DEFAULT_ROWS*/) :
    numRows_(rows)
{
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
  if(row > numRows_ || col > numRows_)
  {
    cout << "ERROR, out of range retrieval:"
         << " max row: " << numRows_
	 << ", row: " << row
         << ", col: " << col
	 << endl;

    // TODO consider an exception instead
    return false;
  }

  return true;
}

int SudokuBoard::getPosition(int row, int col) const
{
  if(!isRangeValid(row, col))
  {
      return -1;
  }

  const RowT &boardRow = board_[row];

  return boardRow[col];
}

void SudokuBoard::setPosition(int row, int col, int value)
{
  if(!isRangeValid(row, col))
  {
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

void SudokuBoard::printBoard() const
{
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

}
