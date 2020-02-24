#include <iostream>
#include<time.h>
using namespace std;
int* createArray(const int);
void freeMemory(int*&);
void printArray(int*,int*);
void initArrayByConst(int*, int*,const int);
void initArrayRandom(int*, int*, const int A=-10, const int B=10);
void inputArray(int*, int*);
int* findFirstMax(int*, int*);
int* findFirstMin(int*, int*);
void reverse(int*, int*);
void sortByInsertion(int*, int*);
void QuickSort(int*,int*);
int Task1(int*, int*);//подсчитать количество элементов, встречающихся более одного раза.     
int Task2(int*, int*);//пределить максимальную длину последовательности равных элементов.

int main() {
 
	int size;
	cout << "Enter size of Array:\n";
	cin >> size;
	int* arr = createArray(size);
	initArrayRandom(arr,arr+size);
	printArray(arr, arr + size);
	cout << *findFirstMax(arr,arr+size);
	cout << *findFirstMin(arr, arr + size);
	cout<<Task1(arr, arr + size)<<"\n";
	initArrayRandom(arr, arr + size,-20);
	printArray(arr, arr + size);
	cout<<Task2(arr, arr + size);
	freeMemory(arr);
}
int* createArray(const int size) {
	
	int* arr=nullptr;
	try { arr = new int[size]; }
	catch (bad_alloc) { cout << "No Memory\n";exit(1); }
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
void printArray(int* begin, int* end) {
	while (begin < end) { cout << *begin << " ";++begin; }
	cout << '\n';
}
void initArrayByConst(int* begin, int* end, const int constant = 0) {
	for (int* p = begin;p < end;++p) {
		*p = constant;
	}
}
void initArrayRandom(int* begin, int* end, int A, int B)
{
	srand(time(NULL));
	if (A > B)swap(A, B);
	double k1 = (B - A) * 1.0 / (RAND_MAX);
	for (int* p = begin; p < end; ++p)
		*p = k1 * rand() + A;

}
void inputArray(int* begin, int* end) {
	for (int* p = begin;p < end;++p) {
		cin>>*p ;
	}
}
int* findFirstMin(int* begin, int* end) {
	int* min = begin;
	for (int* p = begin; p < end; ++p)if (*p < *min)min = p;
	return min;
}
int* findFirstMax(int* begin, int* end) {
	int* max = begin;
	for (int* p = begin; p < end; ++p)if (*p > * max)max = p;
	return max;
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
void sortByInsertion(int* begin, int* end) {
	for (int* ip = begin + 1;ip < end;++ip)
		for (int* jp = ip;jp > begin && *jp < *(jp - 1);--jp)
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
int Task1(int* begin, int* end) {
	//В массиве размера N, заполненного случ.числами от -10 до 10, 
	//подсчитать количество элементов, встречающихся более одного раза.
	QuickSort(begin, end);
	int res=0;
	int num_of_elem=0;
	int elem=*begin;
	for (int* p=begin;p<end;++p)
	{
		if (num_of_elem > 2 && elem == *p) { 
			continue; 
		}
		if (num_of_elem == 2)++res;
		if (elem != *p) {
				num_of_elem = 0;elem = *p;
		}
		++num_of_elem;

	}
	return res;
}
int Task2(int* begin, int* end) {
	//В массиве размера N, заполненного случ.числами от - 10 до 20,
	//определить максимальную длину последовательности равных элементов.
	int max_len = 1;
	int tmp_max_len = 1;
	int elem = *begin;
	for (int* p = begin + 1;p < end;++p) {
		if (*p == elem)tmp_max_len++;
		else {
			if (max_len < tmp_max_len) {
				max_len = tmp_max_len;
				tmp_max_len = 1;
			}
			elem = *p;
		}
	}
	return max_len;
}


