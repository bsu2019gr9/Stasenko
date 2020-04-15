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
	void solveEquation(double a, double b, double c);
public:
	QuadraticEquation(double arg_a , double arg_b = 0, double arg_c = 0);
	QuadraticEquation(const QuadraticEquation& qe);
	QuadraticEquation& operator=(const QuadraticEquation& qe);
	~QuadraticEquation();
	friend ostream& operator<<(ostream& out, const QuadraticEquation& qe) {
		out << qe.a << "x^2+" << qe.b << "x+" << qe.c<<"\n";
		return out;
	}
	friend istream& operator>>(istream& in,  QuadraticEquation& qe) {
		in >> qe.a >> qe.b >> qe.c;
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
	

};

void QuadraticEquation::solveEquation(double a, double b, double c) {
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
QuadraticEquation::QuadraticEquation(double arg_a, double arg_b, double arg_c) :
	a(arg_a), b(arg_b), c(arg_c), size(0)
{
	if (!a)throw "Invalid argument";
	solveEquation(a,b,c);
}
QuadraticEquation::QuadraticEquation(const QuadraticEquation & qe) {
	*this = qe;
}
QuadraticEquation& QuadraticEquation::operator=(const QuadraticEquation & qe) {
	a = qe.a;
	b = qe.b;
	c = qe.c;
	size = qe.size;
	solution[0] = qe.solution[0];
	solution[1] = qe.solution[1];
}
QuadraticEquation::~QuadraticEquation() {}
QuadraticEquation QuadraticEquation::operator+(const QuadraticEquation & qe) const {
	if (!(a + qe.a)) throw "Sum of quadratic equation is not quadratic equation";
	return QuadraticEquation(a + qe.a, b + qe.b, c + qe.c);
}
QuadraticEquation QuadraticEquation::operator-(const QuadraticEquation & qe) const {
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
	if (a)this->a = a;
	else throw "Invalid argument";
	solveEquation(this->a, b, c);

}
void QuadraticEquation::setB(double b) {
	this->b = b;
	solveEquation(a, this->b, c);
}
void QuadraticEquation::setC(double c) {
	this->c = c;
	solveEquation(a, b, this->c);
}
double QuadraticEquation::getA() const {
	return a;
}
double QuadraticEquation::getB() const{
	return b;
}
double QuadraticEquation::getC() const {
	return c;
}
double* QuadraticEquation::getSolution()  {
	if (size == 2) 
		return solution;
	else if (size == 1)
		return &solution[0];
	else return nullptr;
}
size_t QuadraticEquation::getNumberOfSolutions() const{
	return size;
}
bool QuadraticEquation::operator==(const QuadraticEquation& qe) const {
	return a == qe.a && b == qe.b && c == qe.c;
}
bool QuadraticEquation::operator!=(const QuadraticEquation& qe) const{
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
			cout << sol[i];  //вот это бы в функцию fff
	sol = qe6.getSolution();
	cin >> qe1;
	cout << fff1(qe1);
	cout << fff2(qe3);
	cout << fff3(qe6);


}
