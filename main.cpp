#include "SudokuSolver.h"
#include "SudokuGenerator.h"
#include <iostream>
#include <fstream>

int main(){
    SudokuGenerator sudokuGenerator("database.txt");
    SudokuSolver sudokuSolver(sudokuGenerator.GenerateBoard());
    sudokuSolver.Display();
 
    if(sudokuSolver.Solve())    std::cout<<"solved\n";
    else                        std::cout<<"unable to solve\n";
 
    sudokuSolver.Display();
    return 0;
}