#include "Board.h"

void Board::Display()
{
    for (int row = 0; row < Height; row++)
    {
        std::cout << "-------------------------------------------------------------------------------\n";
        for (int col = 0; col < Width; col++)
        {
            if (board[index(row, col)] > 0)
                std::cout << "|" << board[index(row, col)] << "|\t";
            else
                std::cout << "|"
                          << " "
                          << "|\t";
        }
        std::cout << "\n";
    }
    std::cout << "-------------------------------------------------------------------------------\n";
}

bool Board::isSafe(int row, int col, int num)
{
    // check row
    for (int i = 0; i < Height; i++)
    {
        if (board[index(i, col)] == num)
        {
            return false;
        }
    }
    // check column..
    for (int i = 0; i < Width; i++)
    {
        if (board[index(row, i)] == num)
        {
            return false;
        }
    }
    // check box...
    int centerRow = (row / 3) * 3 + 1;
    int centerCol = (col / 3) * 3 + 1;
    for (int offsetRow = -1; offsetRow <= 1; offsetRow++)
    {
        for (int offsetCol = -1; offsetCol <= 1; offsetCol++)
        {
            if (board[index(centerRow + offsetRow, centerCol + offsetCol)] == num)
                return false;
        }
    }
    return true;
}