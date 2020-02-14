/*вычисление интегальных сумм
f(x)=e^(x+2)sin(2x)
eps=0.0001
a=-1,b=1;
h=0.2
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double Exp(double x,double eps) {

	double total_exp=1, curr=1;
	size_t i = 1;
	while (fabs(curr) > eps)
	{
		curr *= x / i;
		total_exp += curr;
		++i;
	}
	return total_exp;
}

double Sin(double x, double eps) {
	double total_exp = x, curr = x;
	size_t i = 2;
	while(fabs(curr) > eps)
	{
		curr *= -x*x / (i*(i+1));
		total_exp += curr;
		i += 2;
	}
	return total_exp;
}

int main() {

	double a = -1, b = 1, eps = 0.0001, h = 0.2;
	for (double x = a;x <= b;x += h) {
		cout << "x="<<setw(4)<<x;
		cout << "\t\tf(x)="<<setw(6)<< Exp(x+2, eps)* Sin(2 * x, eps);
		cout << "\t\tF(x)="<<exp(x+2)*sin(2*x);
		cout << "\n";
	}

	return 0;

}