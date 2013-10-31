
/*
 * main.cc
 *
 *  Created on: Oct 26, 2013
 *      Author: Brady
 */

#include <iostream>

#include "SudokuBoard.hh"
#include "SudokuSolver.hh"

using namespace std;

class SudokuSolverTest : public SudokuSolver
{
public:
  SudokuSolverTest(SudokuBoard &board) : SudokuSolver(board) {}
  inline bool test_valueIsValid(int row, int col, int value) { return valueIsValid(row, col, value); }
  inline bool test_rowHasValue(int row, int value) { return rowHasValue(row, value); }
  inline bool test_colHasValue(int col, int value) { return colHasValue(col, value); }
  inline bool test_squareHasValue(int row, int col, int value) { return squareHasValue(row, col, value); }
};

#define ASSERT_TRUE(boolVal)   if(!boolVal) {cout << "ASSERTION failed: " << __FILE__ << ":" << __LINE__ << endl; }
#define ASSERT_FALSE(boolVal)  if(boolVal)  {cout << "ASSERTION failed: " << __FILE__ << ":" << __LINE__ << endl; }
#define ASSERT_FALSE_ERR_EXPECTED(boolVal) cout << "Expecting error message\n\t"; ASSERT_FALSE(boolVal);

//
// For now, just testing the square validation checking
//

int main(int argc, char **argv)
{
  // 'x' means its empty
  //
  // Sample input                    Answer
  //     0 1 2 | 3 4 5 | 6 7 8
  //   +----------------------
  // 0 | 5 3 x | x 7 x | x x x       5 3 4 | 6 7 8 | 9 1 2
  // 1 | 6 x x | 1 9 5 | x x x       6 7 2 | 1 9 5 | 3 4 8
  // 2 | x 9 8 | x x x | x 6 x       1 9 8 | 3 4 2 | 5 6 7
  //   | ------+-------+------       ------+-------+------
  // 3 | 8 x x | x 6 x | x x 3       8 5 9 | 7 6 1 | 4 2 3
  // 4 | 4 x x | 8 x 3 | x x 1       4 2 6 | 8 5 3 | 7 9 1
  // 5 | 7 x x | x 2 x | x x 6       7 1 3 | 9 2 4 | 8 5 6
  //   | ------+-------+------       ------+-------+------
  // 6 | x 6 x | x x x | 2 8 x       9 6 1 | 5 3 7 | 2 8 4
  // 7 | x x x | 4 1 9 | x x 5       2 8 7 | 4 1 9 | 6 3 5
  // 8 | x x x | x 8 x | x 7 9       3 4 5 | 2 8 6 | 1 7 9
  //   +----------------------
  //     0 1 2 | 3 4 5 | 6 7 8
  //

  SudokuBoard board(9);

  board.setValue(0, 0, 5);
  board.setValue(0, 1, 3);
  board.setValue(0, 4, 7);

  board.setValue(1, 0, 6);
  board.setValue(1, 3, 1);
  board.setValue(1, 4, 9);
  board.setValue(1, 5, 5);

  board.setValue(2, 1, 9);
  board.setValue(2, 2, 8);
  board.setValue(2, 7, 6);

  board.setValue(3, 0, 8);
  board.setValue(3, 4, 6);
  board.setValue(3, 8, 3);

  board.setValue(4, 0, 4);
  board.setValue(4, 3, 8);
  board.setValue(4, 5, 3);
  board.setValue(4, 8, 1);

  board.setValue(5, 0, 7);
  board.setValue(5, 4, 2);
  board.setValue(5, 8, 6);

  board.setValue(6, 1, 6);
  board.setValue(6, 6, 2);
  board.setValue(6, 7, 8);

  board.setValue(7, 3, 4);
  board.setValue(7, 4, 1);
  board.setValue(7, 5, 9);
  board.setValue(7, 8, 5);

  board.setValue(8, 4, 8);
  board.setValue(8, 7, 7);
  board.setValue(8, 8, 9);

  SudokuSolverTest tester(board);
  ASSERT_TRUE(tester.isBoardValid());

  // Test the board ranges
  ASSERT_TRUE(board.isRangeValid(5, 5));
  ASSERT_FALSE_ERR_EXPECTED(board.isRangeValid(1, 10));
  ASSERT_FALSE_ERR_EXPECTED(board.isRangeValid(10, 1));

  // Test the following square [3,3] -> [5, 5]

  // Test all values that already exist in the square
  // each with a different position in the square
  ASSERT_TRUE(tester.test_squareHasValue(3, 3, 2));
  ASSERT_TRUE(tester.test_squareHasValue(3, 4, 3));
  ASSERT_TRUE(tester.test_squareHasValue(3, 5, 6));
  ASSERT_TRUE(tester.test_squareHasValue(4, 3, 8));

  // Test all values that do NOT exists in the square
  // each with a different position in the square
  ASSERT_FALSE(tester.test_squareHasValue(4, 4, 1));
  ASSERT_FALSE(tester.test_squareHasValue(4, 5, 4));
  ASSERT_FALSE(tester.test_squareHasValue(5, 3, 5));
  ASSERT_FALSE(tester.test_squareHasValue(5, 4, 7));
  ASSERT_FALSE(tester.test_squareHasValue(5, 5, 9));

  // 8 already exists, so value is NOT valid
  ASSERT_FALSE(tester.test_valueIsValid(5, 3, 8));

  // 1 does not exist, so value IS valid
  ASSERT_TRUE(tester.test_valueIsValid(5, 5, 1));




  cout << "All tests completed" << endl;
}
