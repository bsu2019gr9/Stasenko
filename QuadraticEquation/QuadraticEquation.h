#pragma once
#include <iostream>
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
	friend ostream& operator<<(ostream& out, const QuadraticEquation& qe);
	friend istream& operator>>(istream& in, QuadraticEquation& qe);
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
	void setABC(double a, double b, double c);
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
	friend void swap(QuadraticEquation& qe1, QuadraticEquation& qe2);
};

