#include <iostream>
#include <chrono>
#include "inc/timer.h"
#define N 11
#define M 4

using namespace std;

/* 1.	���������� �������� ��������� ������, � ������� ��� ���� �� ������. 
������ ������ ���������� M (0<M<10000) ��������� �������� ��� �������� �� N (0<N<100000) ���������, ��������� ������ �� ������� ������ � �������� �����. 
�������� ����� ������ ���� ���� ��������*/

int BinarySearch(int* mass, int l, int r, int k)
{
	if (k < mass[l])
		return -1;
	if (k == mass[l])
		return 0;
	if (k > mass[r])
		return -1;

	int a = l;
	int b = r;

	while (a + 1 < b)
	{
		int c = (a + b) / 2;
		if (k > mass[c])
			a = c;
		else
			b = c;
	}
	if (mass[b] == k)
		return b;
	else
		return -1;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(0));

	int* mass = new int[N];
	

	for (int i = 0; i < N; i++)
		mass[i] = i + 1;

	Timer B;
	cout << " " << '\n';
	for (int i = 0; i < M; i++)
	{
		int kk = rand() % N + 1; 
		cout << "-/" << kk << " " << BinarySearch(mass, 0, N - 1, kk) << '\n';
	}
	cout << " �������� ����� = " << B.elapsed() << '\n';

	/*Timer C;
	cout << "" << '\n';
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			if (mass[j] == kk)
			{
				//cout << "" << kk << " " << j << '\n';
				break;
			}
	cout << " ������ �� ������� ������  = " << C.elapsed() << '\n';*/

	delete[] mass;
}

