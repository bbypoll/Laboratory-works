#include <iostream>
#include "inc/timer.h"

#define N 100
#define M 10

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int* mas = new int[N];                 
	int k;
	cout << "¬ведите число:" << endl;
	cin >> k;

	for (int i = 0; i < N; i++)
		mas[i] = (rand() % 10);

	for (int i = 0; i < N; i++)
		cout << mas[i] << " ";
	cout << "====" << endl;

	int n = N;
	int j = 0;
	Timer t;
	for (int i = 0; i < n; i++)
	{
		if (mas[i] != k)
		{
			mas[j] = mas[i];
			j++;
		}

	}
	n = j;
	cout << "Time elapsed: " << t.elapsed() << '\n';


	for (int i = 0; i < n; i++)
		cout << mas[i] << " ";
	cout << "====" << endl;

	int m = M;
	int d = 0;
	for (int i = 0; i < m; i++)
	{
		if (mas[i] != (rand() % 10))
		{
			mas[d] = mas[i];
			d++;
		}

	}
	n = d;
	for (int i = 0; i < n; i++)
		cout << mas[i] << " ";
	cout << endl;

	delete[] mas;
	return 0;
}
