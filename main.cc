
/*
 * main.cc
 *
 *  Created on: Oct 26, 2013
 *      Author: Brady
 */

#include <iostream>
#include <list>

#include "SudokuBoard.hh"
#include "SudokuSolver.hh"

using namespace std;

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

  SudokuBoard board9(9);

  board9.setValue(0, 0, 5);
  board9.setValue(0, 1, 3);
  board9.setValue(0, 4, 7);

  board9.setValue(1, 0, 6);
  board9.setValue(1, 3, 1);
  board9.setValue(1, 4, 9);
  board9.setValue(1, 5, 5);

  board9.setValue(2, 1, 9);
  board9.setValue(2, 2, 8);
  board9.setValue(2, 7, 6);

  board9.setValue(3, 0, 8);
  board9.setValue(3, 4, 6);
  board9.setValue(3, 8, 3);

  board9.setValue(4, 0, 4);
  board9.setValue(4, 3, 8);
  board9.setValue(4, 5, 3);
  board9.setValue(4, 8, 1);

  board9.setValue(5, 0, 7);
  board9.setValue(5, 4, 2);
  board9.setValue(5, 8, 6);

  board9.setValue(6, 1, 6);
  board9.setValue(6, 6, 2);
  board9.setValue(6, 7, 8);

  board9.setValue(7, 3, 4);
  board9.setValue(7, 4, 1);
  board9.setValue(7, 5, 9);
  board9.setValue(7, 8, 5);

  board9.setValue(8, 4, 8);
  board9.setValue(8, 7, 7);
  board9.setValue(8, 8, 9);

  // 'x' means its empty
  //
  // Sample input        Answer
  //     0 1 | 2 3
  //   +-----------
  // 0 | 1 2 | x 4       1 2 | 3 4
  // 1 | 3 x | 1 2       3 4 | 1 2
  //   +-----+-----     -----+-----
  // 2 | x 1 | x x       2 1 | 4 3
  // 3 | 4 x | x 1       4 3 | 2 1

  SudokuBoard board4(4);

  board4.setValue(0, 0, 1);
  board4.setValue(0, 1, 2);
  board4.setValue(0, 3, 4);

  board4.setValue(1, 0, 3);
  board4.setValue(1, 2, 1);
  board4.setValue(1, 3, 2);

  board4.setValue(2, 1, 1);

  board4.setValue(3, 0, 4);
  board4.setValue(3, 3, 1);


  list<SudokuBoard> boards;
  boards.push_back(board9);
  boards.push_back(board4);

  for(list<SudokuBoard>::iterator iter = boards.begin();
      iter != boards.end();
      ++iter)
  {
    cout << "Sudoku input" << endl;
    iter->printBoard();

    SudokuSolver solver(*iter);

    // check if the input is valid
    if(solver.isBoardValid())
    {
      cout << "The input board is valid" << endl;
    }
    else
    {
      cout << "Invalid input board" << endl;
      return 1;
    }

    // Now try to solve it
    if(solver.solve())
    {
        cout << "The input board has been solved" << endl;
        iter->printBoard();
    }
    else
    {
        cout << "Its not possible to solve the input board" << endl;
    }
  }
}
