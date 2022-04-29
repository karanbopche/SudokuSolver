#pragma once
#include <array>
#include <vector>
#include "Board.h"

class SudokuGenerator{
public:
    SudokuGenerator(const char* databaseFile);
    Board GenerateBoard();
    Board GetBoard(int idx);
private:
    std::vector<Board> boards;
};