//Класс квадратные уравнения. Хранить коэффициенты и корни.
#include <iostream>
#include <cmath>
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
void QuadraticEquation::solveEquation() {
	double D = b * b - 4 * a * c;
	if (D > 0) {
		solution[0] = (-b + sqrt(D)) / (2 * a);
		solution[1] = (-b - sqrt(D)) / (2 * a);
		size = 2;

	}
	else if (D == 0) {
		solution[0] = -b / (2 * a);
		size = 1;
	}
	else size = 0;
}
QuadraticEquation::QuadraticEquation() :a(1), b(0), c(0) {
	solveEquation();
}
QuadraticEquation::QuadraticEquation(double arg_a, double arg_b, double arg_c) :
	a(arg_a), b(arg_b), c(arg_c), size(0)
{
	if (!a)throw "Invalid argument";
	solveEquation();
}
QuadraticEquation::QuadraticEquation(const QuadraticEquation& qe) {
	*this = qe;
}
QuadraticEquation& QuadraticEquation::operator=(const QuadraticEquation& qe) {
	a = qe.a;
	b = qe.b;
	c = qe.c;
	size = qe.size;
	solution[0] = qe.solution[0];
	solution[1] = qe.solution[1];
	return *this;
}
QuadraticEquation::~QuadraticEquation() {}
QuadraticEquation QuadraticEquation::operator+(const QuadraticEquation& qe) const {
	if (!(a + qe.a)) throw "Sum of quadratic equation is not quadratic equation";
	return QuadraticEquation(a + qe.a, b + qe.b, c + qe.c);
}
QuadraticEquation QuadraticEquation::operator-(const QuadraticEquation& qe) const {
	if (!(a - qe.a)) throw "Difference of quadratic equation is not quadratic equation";
	return QuadraticEquation(a - qe.a, b - qe.b, c - qe.c);
}
QuadraticEquation QuadraticEquation::operator*(const double number) const {
	if (!a)throw "Invalid argument";
	return QuadraticEquation(a * number, b * number, c * number);
};
QuadraticEquation QuadraticEquation::operator/(const double number) const {
	if (!a)throw "Invalid argument";
	return QuadraticEquation(a / number, b / number, c / number);
};
void QuadraticEquation::operator+=(const QuadraticEquation& qe) {
	*this = *this + qe;
};
void QuadraticEquation::operator-=(const QuadraticEquation& qe) {
	*this = *this - qe;
};
void QuadraticEquation::operator*=(const double number) {
	*this = *this * number;
};
void QuadraticEquation::operator/=(const double number) {
	*this = *this / number;
};
void QuadraticEquation::setA(double a) {
	if (!a)throw "Invalid argument";
	this->a = a;
	solveEquation();

}
void QuadraticEquation::setB(double b) {
	this->b = b;
	solveEquation();
}
void QuadraticEquation::setC(double c) {
	this->c = c;
	solveEquation();
}
void QuadraticEquation::setABC(double a, double b, double c) {
	if (!a)throw "Invalid argument";
	this->a = a;
	this->b = b;
	this->c = c;
	solveEquation();
}

double QuadraticEquation::getA() const {
	return a;
}
double QuadraticEquation::getB() const {
	return b;
}
double QuadraticEquation::getC() const {
	return c;
}
double* QuadraticEquation::getSolution() {
	if (size == 2)
		return solution;
	else if (size == 1)
		return &solution[0];
	else return nullptr;
}
size_t QuadraticEquation::getNumberOfSolutions() const {
	return size;
}
bool QuadraticEquation::operator==(const QuadraticEquation& qe) const {
	return a == qe.a && b == qe.b && c == qe.c;
}
bool QuadraticEquation::operator!=(const QuadraticEquation& qe) const {
	return !(qe == *this);
}
ostream& operator<<(ostream& out, const QuadraticEquation& qe)
{
	out << qe.a << "x^2+" << qe.b << "x+" << qe.c << "\n";
	return out;
}

istream& operator>>(istream& in, QuadraticEquation& qe)
{
	in >> qe.a >> qe.b >> qe.c;
	qe.solveEquation();
	return in;
}

bool operator>(const QuadraticEquation& qe1, const QuadraticEquation& qe2)
{
	return qe1.a > qe2.a;
}

bool operator>=(const QuadraticEquation& qe1, const QuadraticEquation& qe2)
{
		return qe1.a >= qe2.a ;
}

bool operator<(const QuadraticEquation& qe1, const QuadraticEquation& qe2)
{
		return !(qe1 >= qe2);
}

bool operator<=(const QuadraticEquation& qe1, const QuadraticEquation& qe2){
		return !(qe1 > qe2);
}

void swap(QuadraticEquation& qe1, QuadraticEquation& qe2)
{
	swap(qe1.a, qe2.a);
	swap(qe1.b, qe2.b);
	swap(qe1.c, qe2.c);
	swap(qe1.solution, qe2.solution);
	swap(qe1.size, qe2.size);
}

int main() {

	QuadraticEquation qe1(1,4,-5);
	QuadraticEquation qe2(1,4,4);

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
			cout << ffd(sol[i]); 
	sol = qe6.getSolution();
	cin >> qe1;
	cout << fff1(qe1);
	cout << fff2(qe3);
	cout << fff3(qe6);


}


