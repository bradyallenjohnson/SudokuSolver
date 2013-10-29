
/*
 * SudokuBoard.hh
 *
 *  Created on: Oct 26, 2013
 *      Author: Brady
 */

#ifndef SUDOKUBOARD_HH_
#define SUDOKUBOARD_HH_

#include <vector>

#define DEFAULT_ROWS 3

class SudokuBoard
{
public:
  // Once the SudokuBoard size has been set, it cant be changed
  // The number of rows is squareSize*squareSize
  // The number of squares is numRows
  SudokuBoard(int numRows = DEFAULT_ROWS);

  // Get the value at the position specified
  // A value of 0 means the position is not set
  // A negative value means an error occurred, most likely invalid row or col
  // A valid value will be [1..Rows]
  int getValue(int row, int col) const;

  // Set the value at the position specified
  void setValue(int row, int col, int value);

  // Given the position, return the entire row, col, or square in a vector
  void getRowData(int row, std::vector<int> &rowData) const;
  void getColData(int col, std::vector<int> &colData) const;
  // Given any position in a square, return the square data
  void getSquareData(int row, int col, std::vector<int> &squareData) const;

  // Get the number of rows, which will always be
  // the same as the number of columns
  inline int getNumRows() const { return numRows_; }
  inline int getSquareSize() const { return squareSize_; }

  // Reset the entire board, setting all positions to 0
  // This method is called by the constructor
  void resetBoard();

  // Print the board to stdout, '0' is an empty position
  void printBoard() const;

private:
  int numRows_;
  int squareSize_;

  bool isRangeValid(int row, int col) const;

  typedef std::vector<int> RowT;
  std::vector<std::vector<int> > board_;
};

#endif // SUDOKUBOARD_HH_
