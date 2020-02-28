//В массиве А(N,M) переставить столбцы так, чтобы столбец с максимальной 
//суммой элементов стал первым,
//а остальные столбцы расположить в порядке возрастания элементов первой строки.
#include <iostream>
#include <iomanip>
#include "Arrays/2D-Arrays.h"
using namespace std;
int findColumnWithMaxSumOfELement(int** arr, int rows, int cols);
void sortByFirstRow(int** arr, int rows);

int main() {

	srand(time(NULL));
	int rows, cols;
	cout << "Enter rows,cols\n";
	cin >> rows >> cols;
	swap(rows, cols);
	int** arr = createArray(rows, cols);
	initArray(arr, rows, cols);
	printArrayByColumns(arr, cols,rows);
	int col;//столбец с максимальной суммой элементов;
	col = findColumnWithMaxSumOfELement(arr,rows, cols);
	if(col)swap(arr[col], arr[0]);
	sortByFirstRow(arr, rows);
	printArrayByColumns(arr, cols, rows);
	freeMemory(arr, rows);
}

int findColumnWithMaxSumOfELement(int** arr,int rows,int cols) {

	int sum=0;
	int col=0;
	int max_sum=0;
	for (int i = 0;i < rows;++i) {
		for (int j = 0;j < cols;++j)
		{
			sum += arr[i][j];

		}
		if (max_sum < sum)
		{
			col = i;
			max_sum = sum;
		}
		sum = 0;
	}

	return col;
}
void sortByFirstRow(int** arr, int rows)
{
	for (int i = 2;i < rows;++i) 
		for (int j = i;j > 1 && arr[j][0] < arr[j-1][0];--j)
		{
			swap(arr[j],arr[j-1]);
		}
}