#include <iostream>
#include<time.h>
#include "Arrays/1D-Arrays.h"
using namespace std;

int Task1(int*, int*);//подсчитать количество элементов, встречающихся более одного раза.     
int Task2(int*, int*);//пределить максимальную длину последовательности равных элементов.

int main() {
 
	int size;
	cout << "Enter size of Array:\n";
	cin >> size;
	int* arr = createArray(size);
	initArray(arr,arr+size);
	printArray(arr, arr + size);
	cout << *findFirstMax(arr,arr+size);
	cout << *findFirstMin(arr, arr + size);
	cout<<Task1(arr, arr + size)<<"\n";
	initArray(arr, arr + size,-20,10);
	printArray(arr, arr + size);
	cout<<Task2(arr, arr + size);
	freeMemory(arr);
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


