#pragma once
#include <iostream>
#include <array>

struct Board
{
    static constexpr int Height = 9;
    static constexpr int Width = 9;
    std::array<int, Height * Width> board;
    std::array<int, Height * Width> solution;
    inline int index(int row, int col) { return row * Height + col; }
    inline bool isSolved() { return board == solution; };
    inline bool isCorrectValue(int row, int col, int value) { return solution[row * 9 + col] == value; }
    inline bool isEditable(int row, int col) { return board[index(row, col)] == -1; }
    bool isSafe(int row, int col, int num);
    void Display();
};