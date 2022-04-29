#pragma once

#include "Board.h"

class SudokuSolver
{
public:
    SudokuSolver(Board board);
    SudokuSolver(int *array);
    bool Solve();
    void Display();

private:
    bool boardSolver(int row, int col);
    bool isEditable(int row, int col);
    inline int index(int row, int col) { return row * board.Height + col; }
    Board board;
};
