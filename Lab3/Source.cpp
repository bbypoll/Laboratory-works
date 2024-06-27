#include <iostream>
#include <chrono>
#include "inc/timer.h"
#define N 11
#define M 4

using namespace std;

/* 1.	Реализуйте алгоритм бинарного поиска, о котором шла речь на лекции. 
Решите задачу выполнения M (0<M<10000) поисковых запросов над массивом из N (0<N<100000) элементов, используя проход по массиву циклом и бинарный поиск. 
Сравните время работы этих двух подходов*/

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
	cout << " Бинарный поиск = " << B.elapsed() << '\n';

	/*Timer C;
	cout << "" << '\n';
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			if (mass[j] == kk)
			{
				//cout << "" << kk << " " << j << '\n';
				break;
			}
	cout << " Проход по массиву циклом  = " << C.elapsed() << '\n';*/

	delete[] mass;
}

