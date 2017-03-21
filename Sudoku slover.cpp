// Sudoku slover.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include "Sudoku.h"

void NineBlock::PrintRow(int row)
{
	std::cout << "| ";
	for (int j = 0; j < this->length; j++)
	{
		std::cout << this->matrix[row][j] << " | ";
	}
}
void NineBlock::copyNineBlock(const NineBlock& block)
{
	for (int i = 0; i < this->length; i++)
	{
		for (int j = 0; j < this->length; j++)
		{
			this->matrix[i][j] = block.GetElementFromMatrix(i, j);
		}
	}
}
int const NineBlock::GetElementFromMatrix(int row, int col) const
{
	return this->matrix[row][col];
}
void NineBlock::SetElementToMatrix(int row , int col,int element)
{
	this->matrix[row][col] = element;
}
NineBlock::NineBlock(const NineBlock& block)
{
	copyNineBlock(block);
}
NineBlock::~NineBlock()
{
	for (int i = 0; i < length; i++)
	{
		delete[] this->matrix[i];
	}
	delete[] this->matrix;
}
NineBlock& NineBlock::operator=(const NineBlock& block)
{
	if (this!=&block)
	{
		for (int i = 0; i < this->length; i++)
		{
			delete[] this->matrix[i];
		}
		delete[] this->matrix;

		this->matrix = new int*[this->length];
		for (int i = 0; i < this->length; i++)
		{
			this->matrix[i] = new int[this->length];
		}
		this->copyNineBlock(block);


	}
		return *this;
}
bool NineBlock::operator==(const NineBlock& block)
{
	for (int i = 0; i < this->length; i++)
	{
		for (int j = 0; j < this->length; j++)
		{
			if (this->matrix[i][j] != block.GetElementFromMatrix(i, j))
			{
				return false;
			}
		}
	}
	return true;
}
bool NineBlock::IsCorrect()
{
	for (int i = 0; i < this->length; i++)
	{
		for (int j = 0; j < this->length; j++)
		{
			int num = this->matrix[i][j];
			if (num!=0)
			{
				for (int p = i; p < this->length; p++)
				{
					if (p == i)
					{
						for (int k = j + 1; k < this->length; k++)
						{
							if (num == this->matrix[p][k])
							{
								return false;
							}
						}
					}
					else
					{
						for (int k = 0; k < this->length; k++)
						{
							if (num == this->matrix[p][k])
							{
								return false;
							}
						}
					}

				}
			}
			

		}

	}
	return true;
}
int** NineBlock::copyMatrix(int** matrix)
{
	for (int i = 0; i < this->length; i++)
	{
		for (int j = 0; j < this->length; j++)
		{
			this->matrix[i][j] = matrix[i][j];
		}
	}
	return this->matrix;
}
NineBlock::NineBlock(int** matrix)
{
	this->matrix = new int*[this->length];
	for (int i = 0; i < this->length; i++)
	{
		this->matrix[i] = new int[this->length];
	}
	this->SetMatrix(matrix);
}
NineBlock::NineBlock(int* arr)
{
	this->matrix = new int*[this->length];
	for (int i = 0; i < this->length; i++)
	{
		this->matrix[i] = new int[this->length];
	}
	int count = 0;
	for (int i = 0; i < this->length; i++)
	{
		for (int j = 0; j < this->length; j++)
		{
			this->matrix[i][j] = arr[count];
			count++;
		}
	}
}
void NineBlock::SetMatrix(int** matrix)
{
	this->copyMatrix(matrix);
}
int** const NineBlock::GetMatrix() const
{
	return this->matrix;
}
//Need reconsideration
int* NineBlock::GetColume(int colume)
{
	int* columeForReturn = new int[this->length];
	for (int i = 0; i < this->length; i++)
	{
		columeForReturn[i] = this->matrix[i][colume];
	}
	return columeForReturn;
}
int* NineBlock::GetRow(int row)
{
	return this->matrix[row];
}
void NineBlock::Print()
{
	std::cout << "_____________ \n";
	for (int i = 0; i < this->length; i++)
	{
		std::cout << "| ";
		for (int j = 0; j < this->length; j++)
		{
			std::cout << this->matrix[i][j] << " | ";
		}
		std::cout << "\n";
	}
}
NineBlock::NineBlock()
{
	this->matrix = new int*[this->length];
	for (int i = 0; i < this->length; i++)
	{
		this->matrix[i] = new int[this->length];
	}
	for (int i = 0; i < this->length; i++)
	{
		for (int j = 0; j < this->length; j++)
		{
			this->matrix[i][j] = 0;
		}
	}
}



Sudoku::Sudoku()
{
	this->matrix = new NineBlock*[this->length];
	for (int i = 0; i < this->length; i++)
	{
		this->matrix[i] = new NineBlock[this->length];
	}
	for (int i = 0; i < this->length; i++)
	{
		for (int j = 0; j < this->length; j++)
		{
			this->matrix[i][j] = NineBlock();
		}
	}
}
void Sudoku::Print()
{
	for (int i = 0; i < this->length; i++)
	{
		std::cout << " ___________   ___________   ___________ \n";
		for (int j = 0; j < this->length; j++)
		{
			for (int k = 0; k < this->length; k++)
			{
				this->matrix[i][k].PrintRow(j);
			}
			std::cout << "\n";
		}
		
	}
}
Sudoku::Sudoku(NineBlock* arr)
{
	this->matrix = new NineBlock*[this->length];
	for (int i = 0; i < this->length; i++)
	{
		this->matrix[i] = new NineBlock[this->length];
	}
	int count = 0;
	for (int i = 0; i < this->length; i++)
	{
		for (int j = 0; j < this->length; j++)
		{
			this->matrix[i][j] = arr[count];
		}
	}
}
Sudoku::Sudoku(NineBlock** matrix)
{
	this->matrix = new NineBlock*[this->length];
	for (int i = 0; i < this->length; i++)
	{
		this->matrix[i] = new NineBlock[this->length];
	}
	// set matrix 
}
Sudoku::~Sudoku()
{
	for (int i = 0; i < this->length; i++)
	{
		delete[] this->matrix[i];
	}
	delete[] matrix;
}
void Sudoku::CopySudoku(NineBlock** matrix)
{
	for (int i = 0; i < this->length; i++)
	{
		for (int j = 0; j < this->length; j++)
		{
			this->matrix[i][j] = matrix[i][j];
		}
	}
}
void Sudoku::SetSudoku(NineBlock** matrix)
{
	this->CopySudoku(matrix);
}
NineBlock** const Sudoku::GetSudoku() const
{
	return this->matrix;
}
void Sudoku::SetBlock(int row,int col,const NineBlock& block)
{
	this->matrix[row][col] = block;
}
// did I need to delete that arr? And if needed how ? And when ? And why... :D 
int* Sudoku::GetRow(int block,int row)
{
	int* arr = new int[9];
	int count = 0;
	for (int i = 0; i < this->length; i++)
	{
		for (int j = 0; j < this->length; j++)
		{
			arr[count]=this->matrix[block][i].GetRow(row)[j];
			count++;
		}
		
	}
	return arr;
}
// same question here
int* Sudoku::GetCol(int block,int col)
{
	int* arr = new int[9];
	int count = 0;
	for (int i = 0; i < this->length; i++)
	{
		for (int j = 0; j < this->length; j++)
		{
			arr[count] = this->matrix[i][block].GetColume(col)[j];
			count++;
		}

	}
	return arr;

}
//Do not use me more!!!!!
bool Sudoku::CheckForOccInArr(int* arr,int checkForMe)
{
	int occ = 0;
	for (int i = 0; i < 9; i++)
	{
			if (checkForMe == arr[i])
			{
				occ++;
				if (occ>1)
				{
					return true;
				}
							
			}
	}
	return false;
}
void PrintArr(int* arr)
{
	for (int i = 0; i < 9; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";

}
//returning false for OK
bool Sudoku::CheckForOccInArrOneTime(int* arr, int checkForMe)
{
	for (int i = 0; i < 9; i++)
	{
		if (checkForMe == arr[i])
		{			
				return true;
		}
	}
	return false;
}
bool Sudoku::CheckForOcc(int X,int Y, int blockX, int blockY,int checkForMe)
{
	this->SetValue(X, Y, blockX, blockY, checkForMe);
	bool firstCheck = this->matrix[Y][X].IsCorrect(); // true for OK
	this->SetValue(X, Y, blockX, blockY, 0);
	int* arr = this->GetRow(Y, blockY);
	bool secondCheck = this->CheckForOccInArrOneTime(arr,checkForMe);  // false for OK
	int* arr2 = this->GetCol(X, blockX);
	bool thirdCheck = this->CheckForOccInArrOneTime(arr2, checkForMe); // false for OK
	delete[] arr;
	delete[] arr2;
	arr = NULL;
	arr2 = NULL;
	if (firstCheck && (secondCheck==false) && (thirdCheck==false))
	{
		return false;
	}
	return true;
}
bool Sudoku::IsCorrect()
{
	//checking all blocks
	for (int i = 0; i < this->length; i++)
	{
		for (int j = 0; j < this->length; j++)
		{
			if (!(this->matrix[i][j].IsCorrect()))
			{
				return false;
			}
		}
	}

	//checking all rows
	for (int k = 1; k < 10; k++)
	{

		for (int i = 0; i < this->length; i++)
		{
			for (int j = 0; j < this->length; j++)
			{
				int* arr = new int[9];
				arr = this->GetRow(i, j);
				if (this->CheckForOccInArr(arr,k))
				{
					
						delete[] arr;
						//arr = NULL;
						return false;
				
					
				}
				delete[] arr;
				//arr = NULL;
			}
		}
	}
	//checking for columes
	for (int k = 1; k < 10; k++)
	{

		for (int i = 0; i < this->length; i++)
		{
		
			for (int j = 0; j < this->length; j++)
			{
				int* arr = new int[9];
				arr = this->GetCol(i, j);
				if (this->CheckForOccInArr(arr,k))
				{
					
						delete[] arr;
						return false;
					
						
				}
				delete[] arr;
			}
		}
	}
	//if pass every test then it's correct
	return true;
}
int Sudoku::GetValue(int X, int Y, int blockX, int blockY)
{
	return this->matrix[Y][X].GetElementFromMatrix(blockY, blockX);
}
void Sudoku::SetValue(int X, int Y, int blockX, int blockY,int value)
{
	this->matrix[Y][X].SetElementToMatrix(blockY,blockX,value);
}
bool Sudoku::IsFilled()
{
	for (int i = 0; i < this->length; i++)
	{
		for (int j = 0; j < this->length; j++)
		{
			for (int k = 0; k < this->length; k++)
			{
				for (int p = 0; p < this->length; p++)
				{
					if (this->GetValue(i,j,k,p)==0)
					{
						return false;

					}
				}
			}
		}
	}
	return true;
}
void Sudoku::SolveSudoku(int X,int Y,int blockX,int blockY)
{
	if (this->IsCorrect() && this->IsFilled())
	{
		this->Print();
		return;
	}
	else
	{
		if (this->GetValue(X,Y,blockX,blockY) == 0)
		{
			int len = 0;
			for (int i = 1; i < 10; i++) 
			{
				if ((this->CheckForOcc(X, Y, blockX, blockY, i)) == false)
				{
					len++;
				}
			}
			if (len>0)
			{
				int* arr = new int[len];
				int count = 0;
				for (int i = 1; i < 10; i++)
				{
					if ((this->CheckForOcc(X, Y, blockX, blockY, i)) == false)
					{
						arr[count] = i;
						count++;
					}
				}
				count = 0;
				for (int i = 0; i < len; i++)
				{
					
					int tempX = X;
					int tempY = Y;
					int tempBlockX = blockX;
					int tempBlockY = blockY;
					this->SetValue(X, Y, blockX, blockY, arr[i]);
					if (this->IsCorrect())
					{
						if (tempBlockX == 2)
						{
							tempBlockX = -1;
							if (tempX == 2)
							{
								tempX = 0;
								if (tempBlockY == 2)
								{
									tempBlockY = 0;
									tempY++;

								}
								else
								{
									tempBlockY++;
								}
							}
							else
							{
								tempX++;
							}
						}
						this->SolveSudoku(tempX, tempY, tempBlockX + 1, tempBlockY);
						if (this->IsCorrect() && this->IsFilled())
						{
							return;
						}
					}
				}
				SetValue(X, Y, blockX, blockY, 0);
				delete[] arr;
				//arr = NULL;
			}
			else
			{
				return;
			}
		}
		else
		{
			if (blockX == 2)
			{
				blockX = -1;
				if (X == 2)
				{
					X = 0;
					if (blockY == 2)
					{
						blockY = 0;
						Y++;
					}
					else
					{
						blockY++;
					}
				}
				else
				{
					X++;
				}
			}
			this->SolveSudoku(X, Y, blockX + 1, blockY);
			if (this->IsCorrect() && this->IsFilled())
			{
				return;
			}
		}
		
	}
}


//time to builc a system to easy filing sudoku

int main()
{
	
	Sudoku empty;
	empty.SetValue(0, 0, 0, 0, 2);
	empty.SetValue(1, 1, 2, 0, 3);
	empty.SetValue(2, 2, 2, 2, 9);
	empty.SolveSudoku(0,0,0,0);
	//empty.SolveSudoku(0, 0, 0, 0);


    return 0;
}
