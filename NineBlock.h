#pragma once
class NineBlock
{
private:
	int** copyMatrix(int** matrix);
	void copyNineBlock(const NineBlock& block);
	int** matrix;
	const int length = 3;
public:
	NineBlock();
	NineBlock(int** matrix);
	NineBlock(int* arr);
	NineBlock(const NineBlock& block);
	~NineBlock();
	int const GetElementFromMatrix(int row, int col) const ;
	void SetElementToMatrix(int row, int col,int element);
    int** const GetMatrix() const;
	void SetMatrix(int** matrix);
	int* GetColume(int colume);
	int* GetRow(int row);
	bool IsCorrect();
	void Print();
	NineBlock& operator=(const NineBlock& block);
	bool operator==(const NineBlock& block);

};