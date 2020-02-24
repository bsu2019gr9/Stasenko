#include <iostream>
#include <time.h>
using namespace std;
int* createArray(const int n=10) {
	int* arr;
	try { arr = new int[n]; }
	catch (bad_alloc) { cout << "No Memmory\n";exit(1); }
	arr = { 0 };
	return arr;
}
void freeMemory(int*& arr) {
	try {
		delete[] arr;
	}
	catch (...) {
		cout << "Invalid pointer\n";
		arr = nullptr;
		return;
	}
	arr = nullptr;

}
int* findFirstMin(int *begin, int *end) {
	int *min = begin;
	for (int* p = begin; p < end; ++p)if (*p < *min)min = p;
	return min;
}
int* findFirstMax(int* begin, int* end) {
	int* max = begin;
	for (int* p = begin; p < end; ++p)if (*p > *max)max = p;
	return max;
}
void printArray(int *begin, int *end) {
	while (begin < end) { cout << *begin << " ";++begin; }
	cout << '\n';
}
void inputArray(int* begin, int* end) {
	while (begin < end) {
		cin >> *begin;
		++begin;
	}
}
void findMaxMin(int* begin, int* end, int*& min, int*& max) {


	for (int* p = begin; p < end; ++p) { 
	if (*p < *min)min = p; 
	if (*p > *max)max = p; 
	}
}
int findSum(int* begin, int* end) {
	int s = 0;
	for (int* p = begin; p < end; ++p)
		s += *p;
	return s;
}
void initArray(int* begin, int* end, int A = -10, int B = 10)
{
	srand(time(NULL));
	if (A > B)swap(A, B);
	double k1 = (B - A) * 1.0 / (RAND_MAX);
	for (int* p = begin; p < end; ++p)
		*p = k1 * rand() + A;

}
void howManyMaxMin(int* begin, int* end, int& nmax, int& nmin) {

	nmax = nmin = 0;
	int min, max;
	min = max = *begin;
	for (int* p = begin; p < end; ++p)
	{
		if (*p < min) { min = *p; nmin = 1; }
		else if (*p == min)++nmin;
		if (*p > max) { max = *p; nmax = 1; }
		else if (*p == max)++nmax;
	}
};
int howMuch(int* begin, int* end, int n)
{
	int k = 0;
	for (int* p = begin; p < end; ++p) {
		if (*p == n)k++;
	}
	return k;
}
void reverse(int* begin, int* end)
{
	--end;
	while (begin < end)
	{
		swap(*begin, *end);
		++begin;--end;
	}
}
int* findLastMin(int* begin, int* end) {
	int* min = begin;
	for (int* p = begin; p < end ; ++p)if (*p <= *min)min = p;
	return min;
}
int* findLastMax(int* begin, int* end) {
	int* max = begin;
	for (int* p = begin+1; p < end; ++p)if (*p >= *max)max = p;
	return max;
}

void sortBubble(int* begin, int* end) {
	for (int* ip = begin;ip < end;++ip)
		for (int* jp = begin;jp < end;++jp)
		{
			if (*ip > * jp)swap(*ip, *jp);
		}
}
void sortByInsertion(int* begin, int* end) {
	for (int* ip = begin + 1;ip < end;++ip)
		for (int* jp = ip;jp > begin&&* jp < *(jp - 1);--jp)
		{
			swap(*(jp - 1), *jp);
		}
}
void QuickSort(int* begin, int* end) {
	if (end - begin <= 1)return;
	int* i = begin, * j = end - 1;
	int half_value = *(begin + (end - begin) / 2);
	while (i <= j) {
		while (*i < half_value)++i;
		while (*j > half_value)--j;
		if (i <= j)
		{
			swap(*i, *j);
			++i;--j;
		}
	}
	if (begin < j)QuickSort(begin, j + 1);
	if (end > i)QuickSort(i, end);
}
