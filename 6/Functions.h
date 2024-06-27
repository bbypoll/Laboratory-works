#pragma once
namespace fc
{
	void Read(int& n, int& m, int mass[100][100]);

	int maxzn(int n, int m, int mass[100][100], int K);

	void diagonal1(int n, int m, int mass[100][100]);

	void diagonal2(int n, int m, int mass[100][100]);

	void proverka(int n, int m, int mass[100][100]);

	void Out(int n, int m, int mass[100][100]);
}