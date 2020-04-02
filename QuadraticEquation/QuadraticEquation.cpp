#include "QuadraticEquation.h"
#include <cmath>
QuadraticEquation::QuadraticEquation(double arg_a , double arg_b , double arg_c ):
	a(arg_a),b(arg_b),c(arg_c),solution(nullptr),numOfSolution(0)
{
	double D = b * b - 4 * a * c;
	if (D > 0) {
		solution = new double[2];
		solution[0] = (-b + sqrt(D)) / (2*a);
		solution[1] = (-b - sqrt(D)) / (2*a);
		numOfSolution = 2;
		
	}
	else if (D == 0){
		solution = new double;
		*solution = -b / (2*a);
		numOfSolution = 1;
	} 
}
QuadraticEquation::QuadraticEquation(const QuadraticEquation& qe) {
	*this = qe;
}
void QuadraticEquation::operator=(const QuadraticEquation& qe) {
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
	if(solution)delete[] solution;
	solution = nullptr;
}
QuadraticEquation QuadraticEquation::operator+(const QuadraticEquation& qe) {
	return QuadraticEquation(a + qe.a, b + qe.b, c + qe.c);
}
QuadraticEquation QuadraticEquation::operator-(const QuadraticEquation& qe) {
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