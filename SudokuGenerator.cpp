#include "SudokuGenerator.h"
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>

SudokuGenerator::SudokuGenerator(const char* databaseFile){
    std::fstream input(databaseFile);
    std::string line;
    std::getline(input, line);  // first line contain header.
    while(std::getline(input, line)){
        size_t offset = line.find(',');
        std::string inputString = line.substr(0, offset);
        std::string solutionString = line.substr(offset+1, line.find(','));
        Board board;
        for(int i=0;i<inputString.length();i++){
            if(inputString[i] == '.'){
                board.board[i] = -1;
            }
            else{
                board.board[i] = inputString[i] - '0';
            }
        }
        for(int i=0;i<solutionString.length();i++){
            board.solution[i] = solutionString[i] - '0';
        }   
        boards.push_back(board);
    }
}

Board SudokuGenerator::GetBoard(int index){
    return this->boards[index];
}

Board SudokuGenerator::GenerateBoard(){
    srand(time(0));
    int index = rand()%boards.size();
    return boards[index];
}