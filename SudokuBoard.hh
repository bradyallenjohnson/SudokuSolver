
#include <vector>

#define DEFAULT_ROWS 9

class SudokuBoard
{
public:
  // Once the SudokuBoard size has been set, it cant be changed
  SudokuBoard(int rows = DEFAULT_ROWS);

  // Get the value at the position specifed
  // A value of 0 means the position is not set
  // A negative value means an error occurred, most likely invalid row or col
  // A valid value will be [1..Rows]
  int getPosition(int row, int col) const;
  void setPosition(int row, int col, int value);

  inline int getNumRows() const { return numRows_; }

  void resetBoard();

private:
  int numRows_;

  bool isRangeValid(int row, int col) const;

  typedef std::vector<int> RowT;
  std::vector<std::vector<int> > board_;
};
