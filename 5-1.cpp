#pragma once
#include <iostream>
#include <cmath>
using namespace std;
class QuadraticEquation
{
private:
	double a;
	double b;
	double c;
	double* solution;
	size_t numOfSolution;
public:
	QuadraticEquation(double arg_a = 0, double arg_b = 0, double arg_c = 0);
	QuadraticEquation(const QuadraticEquation& qe);
	void operator=(const QuadraticEquation& qe);
	~QuadraticEquation();
	friend ostream& operator<<(ostream& out, const QuadraticEquation& qe) {
		out << qe.a << "x^2+" << qe.b << "x+" << qe.c<<"\n";
		return out;
	}
	friend istream& operator>>(istream& in,  QuadraticEquation& qe) {
		in >> qe.a >> qe.b >> qe.c;
		return in;
	}
	QuadraticEquation operator+(const QuadraticEquation& qe);
	QuadraticEquation operator-(const QuadraticEquation& qe);
	void setA(double a);
	void setB(double b);
	void setC(double c);
	double getA();
	double getB();
	double getC();
	double* getSolution();
	size_t getNumberOfSolutions();
	bool operator==(QuadraticEquation& qe);
	bool operator!=(QuadraticEquation& qe);

};


QuadraticEquation::QuadraticEquation(double arg_a, double arg_b, double arg_c) :
	a(arg_a), b(arg_b), c(arg_c), solution(nullptr), numOfSolution(0)
{
	double D = b * b - 4 * a * c;
	if (D > 0) {
		solution = new double[2];
		solution[0] = (-b + sqrt(D)) / (2 * a);
		solution[1] = (-b - sqrt(D)) / (2 * a);
		numOfSolution = 2;

	}
	else if (D == 0) {
		solution = new double;
		*solution = -b / (2 * a);
		numOfSolution = 1;
	}
}
QuadraticEquation::QuadraticEquation(const QuadraticEquation & qe) {
	*this = qe;
}
void QuadraticEquation::operator=(const QuadraticEquation & qe) {
	a = qe.a;
	b = qe.b;
	c = qe.c;
	solution = new double[qe.numOfSolution];
	numOfSolution = qe.numOfSolution;
	if (numOfSolution == 2) {
		solution[0] = qe.solution[0];
		solution[1] = qe.solution[1];
	}
	else if (numOfSolution == 1)
	{
		*solution = *qe.solution;
	}
	else solution = nullptr;
	
}
QuadraticEquation::~QuadraticEquation() {
	if (solution)delete[] solution;
	solution = nullptr;
}
QuadraticEquation QuadraticEquation::operator+(const QuadraticEquation & qe) {
	return QuadraticEquation(a + qe.a, b + qe.b, c + qe.c);
}
QuadraticEquation QuadraticEquation::operator-(const QuadraticEquation & qe) {
	return QuadraticEquation(a - qe.a, b - qe.b, c - qe.c);
}
void QuadraticEquation::setA(double a) {
	this->a = a;
}
void QuadraticEquation::setB(double b) {
	this->b = b;
}
void QuadraticEquation::setC(double c) {
	this->c = c;
}
double QuadraticEquation::getA() {
	return a;
}
double QuadraticEquation::getB() {
	return b;
}
double QuadraticEquation::getC() {
	return c;
}
double* QuadraticEquation::getSolution() {
	return solution;
}
size_t QuadraticEquation::getNumberOfSolutions() {
	return numOfSolution;
}
bool QuadraticEquation::operator==(QuadraticEquation& qe) {
	return a == qe.a && b == qe.b && c == qe.c;
}
bool QuadraticEquation::operator!=(QuadraticEquation& qe) {
	return !(qe == *this);
}

QuadraticEquation fff1(QuadraticEquation qe) {
	return qe;
}
QuadraticEquation* fff2(QuadraticEquation* qe) {
	return qe;
}
QuadraticEquation fff3(QuadraticEquation& qe) {
	return qe;
}
int main() {

	QuadraticEquation qe1(1,4,-5);
	QuadraticEquation qe2(1,4,4);
	QuadraticEquation arrQE[10];
	QuadraticEquation* qe3 = new QuadraticEquation(1, -6, 9);
	QuadraticEquation* qe4 = new QuadraticEquation(qe1);
	QuadraticEquation* qe5=&qe2;
	QuadraticEquation qe6(1,1,1);
	cout << (qe1 + qe2);
	cout << (*qe3 - qe6);
	qe2 = qe1;
	double* sol = qe1.getSolution();
	int n = qe1.getNumberOfSolutions();
	for (int i = 0;i < n;i++)
			cout << sol[i];
	sol = qe6.getSolution();
	cin >> qe1;
	cout << fff1(qe1);
	cout << fff2(qe3);
	cout << fff3(qe6);


}
