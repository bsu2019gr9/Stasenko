#include<iostream>
#include<fstream>
#include<time.h>
#include "QuadraticEquation/QuadraticEquation.h"
using namespace std;

typedef  QuadraticEquation T;
T* createArray(const size_t size) {
	try {
		return new T[size];
	}
	catch (...) {
		cout << "No memory";
	}
}
void freeMemory(T arrQE[]) {

	if (arrQE)delete[] arrQE;
}
void sort(T arrQE[],const size_t size) {
	for(size_t i=1;i<size;i++)
		for (size_t j = i;j > 0 && arrQE[j] < arrQE[j - 1];j--) {
			swap(arrQE[j],arrQE[j - 1]);
		}
}
T max(T arrQE[], const size_t size) {

	T max = arrQE[0];
	for (size_t i = 0;i < size;i++)
		if (max < arrQE[i])max = arrQE[i];
	return max;
}
T min(T arrQE[], const size_t size) {

	QuadraticEquation min = arrQE[0];
	for (size_t i = 0;i < size;i++)
		if (min > arrQE[i])min = arrQE[i];
	return min;
}
T findIndexOf(T arrQE[], const size_t size, T qe) {

	for (size_t i = 0;i < size;i++)
		if (qe == arrQE[i])return i;
	return -1;
}
void inputArray(T arrQE[], const size_t size,istream& in=cin) {
	for (size_t i = 0;i < size;i++)
		in >> arrQE[i];

}
void outputArray(T arrQE[], const size_t size, ostream& out=cout) {
	for (size_t i = 0;i < size;i++)
		out << arrQE[i];

}
void initArray(T arrQE[], const size_t size,int A=-10, int B=10 )
{
	srand(time(NULL));
	if (A > B)swap(A, B);
	double k1 = (B - A) * 1.0 / (RAND_MAX);
	for (size_t i = 0; i < size; i++) {
		arrQE[i].setABC (k1 * rand() + A, k1 * rand() + A, k1 * rand() + A);
	}
}
size_t howManyQEhaveSolution(T arrQE[], const size_t size) {

	size_t count = 0;
	for (size_t i = 0; i < size; i++){
		if (arrQE[i].getNumberOfSolutions())count++;
	}
	return count;
}
QuadraticEquation countSum(T arrQE[], const size_t size) {
	QuadraticEquation sum;
	for (size_t i = 0; i < size; i++) {
		if (arrQE[i].getNumberOfSolutions())sum+=arrQE[i];
	}
	sum.setA(sum.getA() - 1);//по конструктор по умолчанию создает уравнение x^2 и при подсчете суммы получается лишний x^2
	return sum;
}
int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	const size_t size = 3;
	QuadraticEquation qe[size];
	inputArray(qe, size);
	outputArray(qe, size);
	inputArray(qe, size, fin);
	outputArray(qe, size, fout);
	cout << howManyQEhaveSolution(qe, size)<<"\n";
	cout << countSum(qe, size)<<"\n";//посчитать сумму для уравнений которые имеют решения
	sort(qe, size);//сортировка по старшей степени
	outputArray(qe, size);
	outputArray(qe, size,fout);
	QuadraticEquation* qe1 = createArray(size);
	initArray(qe1,size);
	outputArray(qe1, size);
	freeMemory(qe1);
	return 0;
}