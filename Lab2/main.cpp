#include <iostream>
#include <chrono>
#include "inc/timer.h"

/*Реализуйте алгоритм быстрой сортировки по его псевдокоду. Реализуйте алгоритм сортировки пузырьком из лекции 1.
Исследуйте при помощи класса Timer время выполнения на разных объемах входных данных (n = 10, n = 100, n = 100 000, n = 1 000 000).*/

using namespace std;

void QuickSort(int a, int b, int* mas)
{
    if (a >= b) return;
    int l = a - 1;
    int r = b + 1;
    int k = mas[(l + r) / 2];

    while (1)
    {
        do
        {
            l++;
        } while (mas[l] < k);
        do
        {
            r--;
        } while (mas[r] > k);

        if (l >= r) break;
        swap(mas[l], mas[r]);
    }
    r = l;
    l = l - 1;
    QuickSort(a, l, mas);
    QuickSort(r, b, mas);
}


void BubbleSort(int* mas, int n)
{
    bool flag;
    for (int i = 0; i < n; i++)
    {
        flag = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (mas[j] > mas[j + 1])
            {
                swap(mas[j], mas[j + 1]);
                flag = true;
            }
        }
        if (!flag)
        {
            break;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    int* mas1 = new int[n];
    int* mas2 = new int[n];

    for (int i = 0; i < n; i++)
    {
        mas1[i] = rand() % 10 + 1;
        mas2[i] = mas1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << mas1[i] << ' ';
    }

    Timer a;
    QuickSort(0, n - 1, mas1);
    std::cout << "Time elapsed (quick) : " << a.elapsed() << std::endl;

    Timer b;
    BubbleSort(mas2, n);
    std::cout << "Time elapsed (bubble) : " << b.elapsed() << std::endl;

    for (int i = 0; i < n; i++)
    {
        std::cout << mas1[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << mas2[i] << " ";
    }
    return 0;

    delete[] mas1;
    delete[] mas2;

    return 0;
}


/*
Псевдокод
начало
ввод количества элементов массива
ввод данных в массив
быстрая сортировка
вывод времени
вывод полученного массива
сортировка пузырьком
вывод времени
вывод полученного массива*/