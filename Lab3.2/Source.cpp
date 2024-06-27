/* 2.	Найдите корень уравнения x - 10 = 0 на отрезке [0; +беск] с точностью до 10^-4 с помощью бисекции.*/
#include <iostream>

using namespace std;

const double precision = 0.2;

double f(double x)
{
	return x - 12;
}

int main()
{
	double a = 0;
	double b = 14;
	double c = (a + b) / 2;

	while (abs(f(c)) - 0 > precision)
	{
		c = (a + b) / 2;
		if (signbit(f(c)) == signbit(f(b)))
		{
			b = c;
		}
		else
		{
			a = c;
		}
		cout << "a: " << a << "b:" << b << endl;
	}

	cout << "Answer: " << c << endl;
	return 0;
}
