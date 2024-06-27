#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	int a[100][100];
	int n, m;
	in >> n >> m;
	int sum = 0;
	int maxsum;
	int nom = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			in >> a[i][j];
		}	
	}
		
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		for (int j = 0; j < m; j++)
		{
			sum += a[i][j];

		}
		if (i == 0)
		{
			nom = i;
			maxsum = sum;
		}
		else if (sum > maxsum)
		{
			nom = i;
			maxsum = sum;
		}
	}
	for (int j = 0; j < m; j++)
	{
		a[nom][j] = a[nom][j] + 1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			out << a[i][j] << " ";
		}
	}
	out << endl;
}