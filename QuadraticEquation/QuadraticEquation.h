#pragma once
#include <iostream>
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
	QuadraticEquation( double arg_a=0, double arg_b=0, double arg_c=0);
	QuadraticEquation(const QuadraticEquation& qe);
	void operator=(const QuadraticEquation& qe);
	~QuadraticEquation();
	friend ostream& operator<<(ostream& out, const QuadraticEquation& qe) {
		out << qe.a << "x^2+" << qe.b << "x+" << qe.c;
		return out;
	}
	friend istream& operator>>(istream& in, QuadraticEquation& qe) {
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

