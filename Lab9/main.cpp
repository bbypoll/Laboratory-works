#include "bmp.hpp"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream in("in.bmp", ios::binary);

	BMPHEADER bmpheader;
	in.read(reinterpret_cast<char*>(&bmpheader), sizeof(BMPHEADER));

	BMPINFO bmpinfo;

	in.read(reinterpret_cast<char*>(&bmpinfo), sizeof(BMPINFO));

	Pixel** pixels = new Pixel * [bmpinfo.Height];
	for (int i = 0; i < bmpinfo.Height; i++)
		pixels[i] = new Pixel[bmpinfo.Width];

	for (int i = 0; i < bmpinfo.Height; i++)
	{
		for (int j = 0; j < bmpinfo.Width; j++)
			in.read(reinterpret_cast<char*>(&pixels[i][j]), sizeof(Pixel));
		if ((3 * bmpinfo.Width) % 4 != 0)
		{
			for (int j = 0; j < 4 - (3 * bmpinfo.Width) % 4; j++)
			{
				char c;
				in.read(&c, 1);
			}
		}
	}
	Filter(bmpinfo, pixels);
	PrintFile(bmpinfo, pixels);
	for (int i = 0; i < bmpinfo.Height; i++)
		delete[] pixels[i];
	delete[] pixels;

		

}