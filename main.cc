
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

int main(int argc, char **argv)
{
  SudokuBoard board(9);

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

  board.setPosition(0, 0, 5);
  board.setPosition(0, 1, 3);
  board.setPosition(0, 4, 7);

  board.setPosition(1, 0, 6);
  board.setPosition(1, 3, 1);
  board.setPosition(1, 4, 9);
  board.setPosition(1, 5, 5);

  board.setPosition(2, 1, 9);
  board.setPosition(2, 2, 8);
  board.setPosition(2, 7, 6);

  board.setPosition(3, 0, 8);
  board.setPosition(3, 4, 6);
  board.setPosition(3, 8, 3);

  board.setPosition(4, 0, 4);
  board.setPosition(4, 3, 8);
  board.setPosition(4, 5, 3);
  board.setPosition(4, 8, 1);

  board.setPosition(5, 0, 7);
  board.setPosition(5, 4, 2);
  board.setPosition(5, 8, 6);

  board.setPosition(6, 1, 6);
  board.setPosition(6, 6, 2);
  board.setPosition(6, 7, 8);

  board.setPosition(7, 3, 4);
  board.setPosition(7, 4, 1);
  board.setPosition(7, 5, 9);
  board.setPosition(7, 8, 5);

  board.setPosition(8, 4, 8);
  board.setPosition(8, 7, 7);
  board.setPosition(8, 8, 9);

  cout << "Sudoku input" << endl;
  board.printBoard();

  SudokuSolver solver;
  if(solver.isBoardValid(board))
  {
    cout << "The input board is valid" << endl;
  }
  else
  {
    cout << "Invalid input board" << endl;
    return 1;
  }

  solver.solve(board);
}
