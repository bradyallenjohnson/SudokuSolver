
#include "SudokuBoard.hh"

int main(int argc, char **argv)
{
  SudokuBoard board(9);
  board.printBoard();

  // 'x' means its empty
  //
  // Sample input                Answer
  // 0 1 2 | 3 4 5 | 6 7 8
  // ---------------------
  // 5 3 x | x 7 x | x x x       5 3 4 | 6 7 8 | 9 1 2
  // 6 x x | 1 9 5 | x x x       6 7 2 | 1 9 5 | 3 4 8
  // x 9 8 | x x x | x 6 x       1 9 8 | 3 4 2 | 5 6 7
  // ------+-------+------       ------+-------+------
  // 8 x x | x 6 x | x x 3       8 5 9 | 7 6 1 | 4 2 3
  // 4 x x | 8 x 3 | x x 1       4 2 6 | 8 5 3 | 7 9 1
  // 7 x x | x 2 x | x x 6       7 1 3 | 9 2 4 | 8 5 6
  // ------+-------+------       ------+-------+------
  // x 6 x | x x x | 2 8 x       9 6 1 | 5 3 7 | 2 8 4
  // x x x | 4 1 9 | x x 5       2 8 7 | 4 1 9 | 6 3 5
  // x x x | x 8 x | x 7 9       3 4 5 | 2 8 6 | 1 7 9
  //


}
