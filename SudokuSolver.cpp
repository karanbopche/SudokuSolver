#include "SudokuSolver.h"
#include <iostream>

SudokuSolver::SudokuSolver(int *array)
{
    for (int i = 0; i < board.board.size(); i++)
    {
        this->board.board[i] = array[i];
    }
}

SudokuSolver::SudokuSolver(Board board)
{
    this->board = std::move(board);
}

bool SudokuSolver::Solve()
{
    return this->boardSolver(0, 0);
}

bool SudokuSolver::boardSolver(int row, int col)
{
    if (board.isSolved())
        return true;
    while (board.isEditable(row, col) == false)
    {
        col++;
        row += col / 9;
        col = col % 9;
        if (row > 8)
            return true;
    }
    for (int num = 1; num <= 9; num++)
    {
        if (board.isSafe(row, col, num))
        {
            this->board.board[index(row, col)] = num;
            if (boardSolver(row, col))
            {
                return true;
            }
            this->board.board[index(row, col)] = -1;
        }
    }
    return false;
}

void SudokuSolver::Display()
{
    this->board.Display();
}
