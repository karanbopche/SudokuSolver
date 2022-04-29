#include <iostream>
#include <fstream>
#include "SudokuSolver.h"
#include "SudokuGenerator.h"

constexpr int width = 9;
constexpr int height = 9;

void LoadBoard(int *board){
    std::fstream input("input.txt");
    for(int r=0;r<height*width;r++){
        input>>board[r];
    }
}

int main(){
    SudokuGenerator sudokuGenerator("database.txt");
    SudokuSolver sudokuSolver(sudokuGenerator.GetBoard(0));
    sudokuSolver.Display();
 
    if(sudokuSolver.Solve())    std::cout<<"solved\n";
    else                        std::cout<<"unable to solve\n";
 
    sudokuSolver.Display();
    return 0;
}