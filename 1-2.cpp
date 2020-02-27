//В массиве А(N,M) переставить столбцы так, чтобы столбец с максимальной 
//суммой элементов стал первым,
//а остальные столбцы расположить в порядке возрастания элементов первой строки.
#include <iostream>
#include <iomanip>
using namespace std;
int findColumnWithMaxSumOfELement(int** arr, int rows, int cols);
void sortByFirstRow(int** arr, int rows, int cols);
void initArray(int* arr[], const int rows, const int cols, const int A=-10, const int B=10);
void printArray(int* arr[], const int rows, const int cols);
int** createArray(const int rows, const int cols);
void freeMemory(int**& arr, const int cols);
int main() {

	srand(time(NULL));
	int rows, cols;
	cout << "Enter rows,cols\n";
	cin >> rows >> cols;
	int** arr = createArray(rows, cols);
	initArray(arr, rows, cols);
	printArray(arr, rows, cols);
	int col;//столбец с максимальной суммой элементов;
	col = findColumnWithMaxSumOfELement(arr, rows, cols);
	swapColumns(arr,rows,0, col);
	sortByFirstRow(arr, rows, cols);
	printArray(arr, rows, cols);
	freeMemory(arr, rows);
}
void initArray(int* arr[], const int rows, const int cols, const int A, const int B) {
	double k = (B - A) * 1.0 / RAND_MAX;
	for (size_t i(0);i < rows;++i)
	{
		for (size_t j(0); j < cols; ++j)arr[i][j] = A + (rand()) * k;
	}
}
void printArray(int* arr[], const int rows, const int cols) {
	for (size_t i(0);i < rows;++i)
	{
		for (size_t j(0);j < cols;++j)cout << setw(5) << arr[i][j];cout << '\n';
	}
	cout << "\n____________________\n";
}
int** createArray(const int rows, const int cols) {
	try {
		int** arr = new int * [rows];
		for (size_t i = 0;i < rows;++i)
			arr[i] = new int[cols];
		return arr;
	}
	catch (bad_alloc) { cout << "\n No memory";exit(1); }

}
void freeMemory(int**& arr, const int rows) {
	try {
		for (size_t i = 0;i < rows;++i)
		{
			delete[] arr[i];arr[i] = nullptr;
		}
		delete[]arr;arr = nullptr;
	}
	catch (out_of_range) { cout << "\nArray is empty!";exit(1); }
}
int findColumnWithMaxSumOfELement(int** arr,int rows,int cols) {

	int sum=0;
	int col=0;
	int max_sum=0;
	for (int i = 0;i < cols;++i) {
		for (int j = 0;j < rows;++j)
		{
			sum += arr[j][i];

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
void swapColumns(int** arr, int rows, int col1,int col2) {

	for (int i = 0;i < rows;++i)
		swap(arr[i][col1], arr[i][col2]);

}
void sortByFirstRow(int** arr, int rows, int cols)
{
	for (int i = 2;i < cols;++i) 
		for (int j = i;j > 1 && arr[0][j] < arr[0][j - 1];--j)
		{
			swapColumns(arr, rows,j, j - 1);
		}
}