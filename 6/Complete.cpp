#include<iostream>
#include "Functions.h"

int main()
{
	int mass[100][100];
	int n, m;

	fc:: Read(n, m, mass); //������� ������

	fc::diagonal1(n, m, mass);

	fc::diagonal2(n, m, mass);

	fc::proverka(n, m, mass);

	fc::Out(n, m, mass); // ������� ������

	return 0;
}