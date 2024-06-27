#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "Введите количество чисел: " << endl;
	cin >> n;
	if ((n <= 1000) & (n >= 1))
	{
		int* arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			cout << i + 1 << " ";
			int t;
			cin >> t;
			arr[i] = t;
		}
		for (int j = 0; j < n; j++)
		{
			for (int i = j + 1; i < n - 1; i++)
			{
				int sumj = 0, sumi = 0;
				int aj = arr[j], ai = arr[i];
				while ((aj > 0) & (ai > 0))
				{
					sumj += abs(aj % 10);
					sumi += abs(ai % 10);
					aj /= 10;
					ai /= 10;
				}
				if (sumj > sumi)
				{
					swap(arr[j], arr[i]);
				}

				int maxj = 0, maxi = 0;
				int aj1 = arr[j], ai1 = arr[i];
				if (sumj == sumi)
				{
					while ((aj1 > 0) & (ai1 > 0))
					{
						if (aj % 10 > maxj)
						{
							maxj = abs(aj % 10);
							aj /= 10;
						}
						if (ai % 10 > maxi)
						{
							maxi = abs(ai % 10);
							ai /= 10;
						}
					}
					if (maxj > maxi)
					{
						swap(arr[j], arr[i]);
					}
				}
				if ((sumj == sumi) & (maxj == maxi))
				{
					if (arr[j] > arr[i])
					{
						swap(arr[j], arr[i]);
					}
				}
			}
		}
		for (int k = 0; k < n; k++)
		{
			cout << arr[k] << " ";
		}
		delete[] arr;
	}
	else
	{
		cout << "Мимо!!! Попробуйте ввести число от 1 до 1000";
	}
	return 0;
}

	
