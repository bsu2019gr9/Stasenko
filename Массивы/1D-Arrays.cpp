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
int* findMin(int *begin, int *end) {
	int *min = begin;
	for (int* p = begin; p < end; ++p)if (*p < *min)min = p;
	return min;
}
int* findMax(int* begin, int* end) {
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
void findMaxMin(int* begin, int* end, int& min, int& max) {

	for (int* p = begin; p < end; ++p) { 
	if (*p < min)min = *p; 
	if (*p > max)max = *p; 
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
void getPositiveNegativeArray(int* begin, int* end, int& neg, int& pos) {

	neg = pos = 0;
	for (int* p = begin; p < end; ++p) {
		if (*p > 0)++pos;
		if (*p < 0)++neg;
	}

}
void halfArray(int* begin, int* end, int B[], int C[])
{
	int i = 0;
	int r = (end-begin) / 2;
	for (int* p = begin; p < begin+r; ++p) { B[i] = *p;++i; }
	i = 0;
	for (int* p = begin + r; p < end; ++p) C[i] = *p;

}
void divArray(int* begin, int* end, int B[], int C[])
{

	for (int k = 0, j = 0,*p=begin; p < end; ++p) {
		if (*p > 0) { B[j] =*p, j++; }
		if (*p < 0) { C[k] =*p, k++; }
	}

}

bool changeArray1(int* begin, int* end) {
	bool flag = false;
	const int k = 999;
	for (int* p = begin; p < end - 1; ++p) {
		if (*p) {*(p+1) = 999; flag = true; break; }
	}
	return flag;
}
bool changeArray2(int* begin, int* end) {
	int* min = findMin(begin, end);
	if (min + 1 < end - 1) {
		*(min + 1) = 999; return true;
	}
	return false;
}
bool changeArray3(int* begin, int* end) {
	int* max = findMax(begin, end);
	if (max - 1 >= begin) {
		*(max-1) = 999; return true;
	}
	return false;
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
int* findIdLastMin(int* begin, int* end) {
	int* min = begin;
	for (int* p = begin; p < end ; ++p)if (*p <= *min)min = p;
	return min;
}
int* findIdFirstMax(int* begin, int* end) {
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
void sortbyInsertion(int* begin, int* end) {
	for (int* ip = begin+1;ip < end;++ip)
		for (int* jp = ip;jp>begin && *jp >*(jp-1);++jp)
		{
			swap(*(jp-1), *jp);
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
