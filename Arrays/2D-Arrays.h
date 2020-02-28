#pragma once
#include <iostream>
#include<time.h>
#include<iomanip>
using namespace std;



void freeMemory(int**& arr, const int cols);
int** createArray(const int rows, const int cols);
void initSnakebyRows(int** arr, const int rows, const int cols);
void initSnakebyColumns(int** arr, const int rows, const int cols);
void initRightToLeft(int** arr, const int rows, const int cols);
void findSaddlePoint(int** arr, const int rows, const int cols, int& i0, int& j0);
void transpose(int** arr, const int rows, const int cols);
void initbyDiagonals(int** arr, const int rows, const int cols);
int countSumOfElementsOfBottominTriangle(int** arr, const int rows, const int cols);
int countSumOfElementsOfMainDiagonal(int** arr, const int rows, const int cols);
void printArray(int** arr, const int rows, const int cols);
void printArrayByColumns(int** arr, const int rows, const int cols);
void initArray(int** arr, const int rows, const int cols, const int A = -10, const int B = 10);
void initArrayByconst(int** arr, const int rows, const int cols, const int cons);
void inputArray(int** arr, const int rows, const int cols);
void initSpiral(int** arr, const int rows, const int cols);


