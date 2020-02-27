//В массиве А(N,M) переставить столбцы так, чтобы столбец с максимальной 
//суммой элементов стал первым,
//а остальные столбцы расположить в порядке возрастания элементов первой строки.
#include <iostream>
#include <iomanip>
#include "2D-Arrays.h"
using namespace std;
int findColumnWithMaxSumOfELement(int** arr, int rows, int cols);
void sortByFirstRow(int** arr, int rows, int cols);

int main() {

	srand(time(NULL));
	int rows, cols;
	cout << "Enter rows,cols\n";
	cin >> rows >> cols;
	int** arr = createArray(cols, rows);
	initArray(arr, cols, rows);
	printArrayByColumns(arr, cols, rows);
	int col;//столбец с максимальной суммой элементов;
	col = findColumnWithMaxSumOfELement(arr, cols, rows);
	swap(arr[col], arr[0]);
	printArrayByColumns(arr, cols, rows);
	sortByFirstRow(arr, rows, cols);
	printArrayByColumns(arr, cols, rows);
	freeMemory(arr, cols);
}

int findColumnWithMaxSumOfELement(int** arr,int rows,int cols) {

	int sum=0;
	int col=0;
	int max_sum=0;
	for (int i = 0;i < cols;++i) {
		for (int j = 0;j < rows;++j)
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
void sortByFirstRow(int** arr, int cols, int rows)
{
	for (int i = 2;i < cols;++i) 
		for (int j = i;j > 1 && arr[j][0] < arr[j-1][0];--j)
		{
			swap(arr[j],arr[j-1]);
		}
}