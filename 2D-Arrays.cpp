#include "2D-Arrays.h"
void inputArray(int** arr, const int rows, const int cols) {
	for (size_t i(0);i < rows;++i)
	{
		for (size_t j(0); j < cols; ++j)cin >> arr[i][j];cout << '\n';
	}
}
void initArrayByconst(int** arr, const int rows, const int cols,const int cons) {
	
	for (size_t i(0);i < rows;++i)
	{for (size_t j(0); j < cols; ++j)arr[i][j]=cons;cout << '\n';}
}
void initArray(int** arr, const int rows, const int cols, const int A,const int B) {
	double k = (B - A) *1.0/ RAND_MAX;
	for (size_t i(0);i < rows;++i)
	{for (size_t j(0); j < cols; ++j)arr[i][j]=A+(rand())*k;}
}
void printArray(int** arr, const int rows, const int cols ) {
	for (size_t i(0);i < rows;++i)
	{for (size_t j(0);j < cols;++j)cout << setw(5) << arr[i][j];cout << '\n';}
	cout << "\n____________________\n";
}
void printArrayByColumns(int** arr, const int rows, const int cols) {
	for (size_t i(0);i < rows;++i)
	{
		for (size_t j(0);j < cols;++j)cout << setw(5) << arr[j][i];cout << '\n';
	}
	cout << "\n____________________\n";
}
int countSumOfElementsOfMainDiagonal(int** arr, const int rows, const int cols ) {
	if (rows != cols)throw "num of rows isn't equal num of cols";
	int sum (0);
	for (size_t i(0), j(0);i < rows && j<cols;++i,++j)
		sum += arr[i][j];
	return sum;

}
int countSumOfElementsOfBottominTriangle(int** arr, const int rows, const int cols) {
	if (rows != cols)throw "num of rows isn't equal num of cols";
	int sum (0);
	for (size_t i(0);i < rows;++i)
		for (size_t j(0); j<=i; ++j)
			sum+=arr[i][j];
	return sum;
}
void transpose(int** arr, const int rows, const int cols) {
	for (size_t i(0);i < rows;++i)
		for (size_t j(i); j < cols; ++j)
			swap(arr[i][j],arr[j][i]);
}
void findSaddlePoint(int** arr, const int rows, const int cols,int& i0,int& j0) {
	
	j0=0, i0=0;
	int i(0);
	bool flag ;
	do {

		flag = false;
        for (size_t j(0);j < cols;++j)
		{if(arr[i0][j0] >arr[i0][j])
			j0=j;}
		for (;i < rows;++i)
		{
			if (arr[i0][j0] < arr[i][j0]) { flag = true;break; }
		}
		
	} while (flag && ++i0<rows);
	if (i0 == rows) { i0 = -1;j0 = -1; }
}
void initRightToLeft(int** arr, const int rows, const int cols) {
	for (size_t i(0);i<rows;++i)
		for (int j(cols - 1);j >= 0;--j)
			arr[i][j] = i*rows+cols-j;
}
void initSnakebyColumns(int** arr, const int rows, const int cols ) {
	int d = 1,i=0;
	for(size_t j=0;j<cols;++j)
	{for (size_t k = 0;k < rows ;++k)
		{arr[i][j] = j * cols + k;i += d;}
	d = -d;i += d;}
}
void initSnakebyRows(int** arr, const int rows, const int cols ) {
	int d = 1, j=0;
	for (size_t i = 0;i < rows;++i)
	{
		for (size_t k = 0;k < cols;++k)
		{ arr[i][j] = i * rows + k;j += d;}
		d = -d;j += d;
	}
}
int** createArray(const int rows, const int cols) {
	try {
		int** arr = new int* [rows];
		for (size_t i = 0;i < cols;++i)
			arr[i] = new int[cols];
		return arr;
	}
	catch (bad_alloc) { cout << "\n No memory";exit(1); }

}
void freeMemory(int**& arr, const int cols) {
	try {
		for (size_t i = 0;i < cols;++i)
		{
			delete[] arr[i];arr[i] = nullptr;
		}
		delete[]arr;arr = nullptr;
	}
	catch (out_of_range) { cout << "\nArray is empty!";exit(1); }
}
void initbyDiagonals(int** arr,const int rows,const int cols ) {
	int i = 0, j = 0, d = 1, i0, j0, k = 0;
	while (i < rows && j < cols)
	{
		arr[i][j] = ++k;
		if ((i == 0 || i == rows - 1) && j != cols - 1)j++;
		else if (j == 0 || j == cols - 1)i++;
		i0 = j;j0 = i;
		while (i0 != i && j0 != j && i < rows && j < cols)
		{
			arr[i][j] = ++k;
			j -= d;i += d;
		}
		d = -d;
	}
}
void initSpiral(int** arr, const int rows, const int cols)
{

	int i = 0, j = -1,k=0,step=rows, d = 1, h=step;
	while (h--)
	{j += d;arr[i][j] = ++k;}
	--step;
	while (step)
	{

		h = step;
		while(h--)
		{i += d;arr[i][j] = ++k;}
		h = step;
		d = -d;
		while (h--)
		{j += d;arr[i][j] = ++k;}
		--step;
	}

}