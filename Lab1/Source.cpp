#include <iostream>
#include<iomanip>
#include<cmath>
#include <cstdlib>
#include "inc/timer.h"

using namespace std;

/*Вариант 7.
Дана матрица N х N.Найдите наибольшую сумму элементов столбца.*/

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));

    int b = rand();
    int N, maxsum, sum;
    cout << "Введите размеры массива:" << endl;
    cout << "N = ";
    cin >> N;
  
    int** a = new int* [N];
    for (int i = 0; i < N; i++)
    {
        a[i] = new int[N];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            a[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << a[i][j] << " ";
        }
    }
 //поиск максимальной суммы столбца 
    maxsum = INT_MIN;
    Timer t;
    for (int j = 0; j < N; j++)
    {
      sum = 0;
      for (int i = 0; i < N; i++)
      {
          sum += a[i][j];
             
      }
      if (sum > maxsum)
      {
          maxsum = sum;
      }
    }
    cout << "Time taken: "<< t.elapsed() << '\n';
    cout << "Максимальная сумма столбца: " << maxsum << endl;
    
    for (int i = 0; i < N; i++)
    {
        delete[] a[i];
    }
    delete[] a;

	return 0;
}