#pragma once
int* createArray(const int n = 10);
void freeMemory(int*& arr);
int* findFirstMin(int* begin, int* end);
int* findFirstMax(int* begin, int* end);
void printArray(int* begin, int* end);
void inputArray(int* begin, int* end);
void findMaxMin(int* begin, int* end, int*& min, int*& max);
int findSum(int* begin, int* end);
void initArray(int* begin, int* end, int A = -10, int B = 10);
void howManyMaxMin(int* begin, int* end, int& nmax, int& nmin);
int howMuch(int* begin, int* end, int n);
void reverse(int* begin, int* end);
int* findLastMin(int* begin, int* end);
int* findFirstMax(int* begin, int* end);
void sortBubble(int* begin, int* end);
void sortbyInsertion(int* begin, int* end);
void QuickSort(int* begin, int* end);