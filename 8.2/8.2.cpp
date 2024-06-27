#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream in("input.txt");//чтение файла
	ofstream out("output.txt");//вывод в файл
	int n;
	int m;
	in >> n;
	in >> m;

	if ((n > 0) & (n <= 100))
	{
		if ((m > 0) & (m <= 100))
		{
			int** a = new int* [n];
			for (int i = 0; i < n; i++)
			{
				a[i] = new int[m];
			}
			for (int i = 0; i < n; i++)

				for (int j = 0; j < m; j++)
				{
					in >> a[i][j];// чтение матрицы
				}
			int maxsum = INT_MIN, sum, nom = 0;

			for (int i = 0; i < n; i++) // вычисление суммы строки
				for (int j = 0; j < m; j++)
				{
					sum = 0;
					for (int j = 0; j < m; j++)
					{
						sum += a[i][j];
					}
					if (sum >= maxsum) //проверка на максимальную сумму
					{
						nom = i; // присваиваем nom номер строки с максимальной суммой
						maxsum = sum;
					}
				}
			for (int j = 0; j < m; j++)
			{
				a[nom][j] = a[nom][j] + 1; // увеличиваю строку с максимальной суммой на 1
			}
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					out << a[i][j] << "  "; // вывод новой матрицы в файл
				}
			}
			out << endl;
			for (int i = 0; i < n; i++)
			{
				delete[] a[i];
			}
			delete[] a;
		}
	}
}
	