#pragma once
#include <array>
#include <vector>
#include "Boards.h"

class SudokuGenerator{
public:
    SudokuGenerator(const char* databaseFile);
    Board GenerateBoard();
    Board GetBoard(int idx);
private:
    std::vector<Board> boards;
};