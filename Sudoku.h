#pragma once
#include "NineBlock.h"
class Sudoku
{
private:
	const int length = 3;
	NineBlock** matrix;
	void CopySudoku(NineBlock** matrix);
	bool CheckForOccInArr(int* arr,int checkForMe);
	bool CheckForOccInArrOneTime(int* arr, int checkForMe);
public:
	Sudoku();
	Sudoku(NineBlock* arr);
	Sudoku(NineBlock** matrix);
	~Sudoku();
	bool IsCorrect();
	void SolveSudoku(int X,int Y,int blockX,int blockY);
	bool IsFilled();
	int GetValue(int X, int Y, int blockX, int blockY);
	void SetValue(int X, int Y, int blockX, int blockY,int value);
	void SetSudoku(NineBlock** matrix);
    NineBlock** const  GetSudoku() const;
	int* GetRow(int block,int row);
	int* GetCol(int block, int col);
	void SetBlock(int row, int col,const NineBlock& block);
	bool CheckForOcc(int X, int Y, int blockX, int blockY, int checkForMe);
	void Print();

};