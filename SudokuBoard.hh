
#include <vector>

#define DEFAULT_ROWS 9

class SudokuBoard
{
public:
  // Once the SudokuBoard size has been set, it cant be changed
  SudokuBoard(int rows = DEFAULT_ROWS);

  // Get the value at the position specified
  // A value of 0 means the position is not set
  // A negative value means an error occurred, most likely invalid row or col
  // A valid value will be [1..Rows]
  int getPosition(int row, int col) const;

  // Set the value at the position specified
  void setPosition(int row, int col, int value);

  // Get the number of rows, which will always be
  // the same as the number of columns
  inline int getNumRows() const { return numRows_; }

  // Reset the entire board, setting all positions to 0
  // This method is called by the constructor
  void resetBoard();

  // Print the board to stdout, '0' is an empty position
  void printBoard() const;

private:
  int numRows_;

  bool isRangeValid(int row, int col) const;

  typedef std::vector<int> RowT;
  std::vector<std::vector<int> > board_;
};
