// Sudoku slover.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include "NineBlock.h"

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

int main()
{
	int count = 0;
	int** arr = new int*[3];
	for (int i = 0; i < 3; i++)
	{
		arr[i] = new int[3];
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			count++;
			arr[i][j] = count;
		}
	}
	int* arr2 = new int[9]{ 0,1,0,0,1,0,0,0,0 };
	NineBlock firstBlock(arr);
	NineBlock secondBlock(arr2);
	firstBlock.Print();
	secondBlock.Print();
	std::cout<<firstBlock.IsCorrect()<<std::endl;
	std::cout<<secondBlock.IsCorrect()<<std::endl;
    return 0;
}
