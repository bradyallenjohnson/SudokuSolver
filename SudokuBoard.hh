
/*
 * SudokuBoard.hh
 *
 *  Created on: Oct 26, 2013
 *      Author: Brady
 */

#ifndef SUDOKUBOARD_HH_
#define SUDOKUBOARD_HH_

#include <vector>

#define DEFAULT_BOARD_SIZE 3

class SudokuBoard
{
public:
  // Once the SudokuBoard size has been set, it cant be changed
  // The number of rows = numCols = squareSize*squareSize
  // The number of squares = boardSize
  SudokuBoard(int boardSize = DEFAULT_BOARD_SIZE);

  // Get the value at the position specified
  // A value of 0 means the position is not set
  // A negative value means an error occurred, most likely invalid row or col
  // A valid value will be [1..Rows]
  int getValue(int row, int col) const;

  // Set the value at the position specified
  void setValue(int row, int col, int value);

  // Get the number of rows, which will always be
  // the same as the number of columns
  inline int getBoardSize() const { return boardSize_; }
  inline int getSquareSize() const { return squareSize_; }

  // Reset the entire board, setting all positions to 0
  // This method is called by the constructor
  void resetBoard();

  // Print the board to stdout, '0' is an empty position
  void printBoard() const;

private:
  int boardSize_;
  int squareSize_;

  bool isRangeValid(int row, int col) const;

  typedef std::vector<int> RowT;
  std::vector<std::vector<int> > board_;
};

#endif // SUDOKUBOARD_HH_
