/*вычисление интегальных сумм
f(x)=e^(x+2)sin(2x)
eps=0.0001
a=-1,b=1;
h=0.2
*/



#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

double Exp(double x,double eps) {

	double total_exp=1, curr=1;
	for (size_t i = 1;fabs(curr) > eps; i++)
	{
		curr *= x / i;
		total_exp += curr;
	}
	return total_exp;
}

double Sin(double x, double eps) {
	double total_exp = x, curr = x;
	for (size_t i = 2;fabs(curr) > eps; i+=2)
	{
		curr *= -x*x / (i*(i+1));
		total_exp += curr;
	}
	return total_exp;
}

int main() {

	const double exp_2 = M_E * M_E;
	double a = -1, b = 1, eps = 0.0001, h = 0.2;
	for (double x = a;x <= b;x += h) {
		cout << "x=";
		cout.width(2);
		cout << x;
		cout << "\t\tf(x)=";
		cout.width(6);
		cout << Exp(x,eps)*exp_2*Sin(2*x,eps);
		cout << "\t\tF(x)=";
		cout.width(6);
		cout << exp(x) * exp_2 * sin(2 * x);
		cout << "\n";
	}

	return 0;

}