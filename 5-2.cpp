#include<iostream>
#include<fstream>
#include<time.h>
using namespace std;
class QuadraticEquation
{
private:
	double a;
	double b;
	double c;
	size_t size;
	double solution[2];
	void solveEquation();
public:
	QuadraticEquation();
	QuadraticEquation(double arg_a, double arg_b = 0, double arg_c = 0);
	QuadraticEquation(const QuadraticEquation& qe);
	QuadraticEquation& operator=(const QuadraticEquation& qe);
	~QuadraticEquation();
	friend ostream& operator<<(ostream& out, const QuadraticEquation& qe) {
		out << qe.a << "x^2+" << qe.b << "x+" << qe.c << "\n";
		return out;
	}
	friend istream& operator>>(istream& in, QuadraticEquation& qe) {
		in >> qe.a >> qe.b >> qe.c;
		qe.solveEquation();
		return in;
	}
	QuadraticEquation operator+(const QuadraticEquation& qe) const;
	QuadraticEquation operator-(const QuadraticEquation& qe) const;
	QuadraticEquation operator*(const double number) const;
	QuadraticEquation operator/(const double number) const;
	void operator+=(const QuadraticEquation& qe);
	void operator-=(const QuadraticEquation& qe);
	void operator*=(const double number);
	void operator/=(const double number);
	void setA(double a);
	void setB(double b);
	void setC(double c);
	double getA() const;
	double getB() const;
	double getC() const;
	double* getSolution();
	size_t getNumberOfSolutions() const;
	bool operator==(const QuadraticEquation& qe) const;
	bool operator!=(const QuadraticEquation& qe) const;
	friend bool operator>(const QuadraticEquation& qe1, const QuadraticEquation& qe2);
	friend bool operator>=(const QuadraticEquation& qe1, const QuadraticEquation& qe2);
	friend bool operator<(const QuadraticEquation& qe1, const QuadraticEquation& qe2);
	friend bool operator<=(const QuadraticEquation& qe1, const QuadraticEquation& qe2);
	friend void swap(const QuadraticEquation& qe1, const QuadraticEquation& qe2);

};
typedef  QuadraticEquation T;
void sort(T arrQE[],const size_t size) {
	for(size_t i=1;i<size;i++)
		for (size_t j = i;j > 0 && arrQE[j] < arrQE[j - 1];j--) {
			swap(arrQE[j], arrQE[j - 1]);
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
void initArray(T arrQE[], const size_t size,const int A=-10,const int B=10 )
{
	srand(time(NULL));
	if (A > B)swap(A, B);
	double k1 = (B - A) * 1.0 / (RAND_MAX);
	for (size_t i=0; i < size; i++)
		arrQE[i] = k1 * rand() + A;

}
size_t howManyQEhaveSolution(T arrQE[], const size_t size) {

	size_t count = 0;
	for (size_t i = 0; i < size; i++){
		if (arrQE[i].getNumberOfSolutions)count++;
	}

}
QuadraticEquation getSum(T arrQE[], const size_t size) {
	QuadraticEquation sum;
	for (size_t i = 0; i < size; i++) {
		if (arrQE[i].getNumberOfSolutions)sum+=arrQE[i];
	}

}
int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	const size_t size = 10;
	QuadraticEquation qe[size];
	inputArray(qe, size);
	outputArray(qe, size);
	inputArray(qe, size, fin);
	outputArray(qe, size, fout);
	cout << howManyQEhaveSolution(qe, size);
	cout << getSum(qe, size);
	sort(qe, size);
	outputArray(qe, size);
	outputArray(qe, size,fout);

	return 0;
}