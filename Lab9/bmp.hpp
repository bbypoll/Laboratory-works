#pragma once
#include <iostream>
#include <fstream>
using namespace std;

#pragma pack(1) //  
struct BMPHEADER
{
	unsigned short    Type;
	unsigned int      Size;
	unsigned short    Reserved1;
	unsigned short    Reserved2;
	unsigned int      OffBits;
};
#pragma pack()

#pragma pack(1)
struct BMPINFO
{
	unsigned int    Size;
	int             Width;
	int             Height;
	unsigned short  Planes;
	unsigned short  BitCount;
	unsigned int    Compression;
	unsigned int    SizeImage;
	int             XPelsPerMeter;
	int             YPelsPerMeter;
	unsigned int    ClrUsed;
	unsigned int    ClrImportant;
};
#pragma pack()
#pragma pack(1)
struct Pixel
{
	unsigned char b;
	unsigned char g;
	unsigned char r;
};
#pragma pack()
void Filter(BMPINFO bmpInfo, Pixel** pixels)
{
	for (int i = 0; i < bmpInfo.Height; i++)
	{
		for (int j = 0; j < bmpInfo.Width; j++)
		{
			if (pixels[i][j].b + 40 < 256)
				pixels[i][j].b += 40;
			if (pixels[i][j].g + 10 < 256)
				pixels[i][j].g += 10;

			if (pixels[i][j].r + 20 < 256)
				pixels[i][j].r += 20;
		}
	}
}

void PrintFile(BMPINFO bmpInfo, Pixel** pixels)
{
	std::ofstream out("out.bmp", std::ios::binary);
	int width = bmpInfo.Width;
	int height = bmpInfo.Height;

	BMPHEADER bmpheader_new;

	bmpheader_new.Type = 0x4D42;
	bmpheader_new.Size = 14 + 40 + 3 * (height * width);
	if (width % 4 != 0)
		bmpheader_new.Size += (4 - (3 * width) % 4) * height;
	bmpheader_new.OffBits = 54;
	bmpheader_new.Reserved1 = 0;
	bmpheader_new.Reserved2 = 0;

	out.write(reinterpret_cast<char*>(&bmpheader_new), sizeof(BMPHEADER));

	BMPINFO bmpinfo_new;
	bmpinfo_new.BitCount = 24;
	bmpinfo_new.ClrImportant = 0;
	bmpinfo_new.ClrUsed = 0;
	bmpinfo_new.Compression = 0;
	bmpinfo_new.Height = height;
	bmpinfo_new.Planes = 1;
	bmpinfo_new.Size = 40;
	bmpinfo_new.SizeImage = bmpheader_new.Size - 54;
	bmpinfo_new.Width = width;
	bmpinfo_new.XPelsPerMeter = 0;
	bmpinfo_new.YPelsPerMeter = 0;

	out.write(reinterpret_cast<char*>(&bmpinfo_new), sizeof(BMPINFO));

	for (int i = 0; i < bmpinfo_new.Height; i++)
	{
		for (int j = 0; j < bmpinfo_new.Width; j++)
			out.write(reinterpret_cast<char*>(&pixels[i][j]), sizeof(Pixel));
		if ((3 * bmpinfo_new.Width) % 4 != 0)
		{
			for (int j = 0; j < 4 - (3 * bmpinfo_new.Width) % 4; j++)
			{
				char c = 0;
				out.write(&c, 1);
			}
		}
	}
}