all:
	g++  -g --std=c++14 main.cpp SudokuSolver.cpp SudokuGenerator.cpp board.cpp -o sudokuSolver.exe
