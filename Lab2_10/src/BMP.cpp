#include <BMP.hpp>

namespace images
{

    BMP::BMP()
    {
    }

    BMP::BMP(int width, int height)
    {
        m_width = width;
        m_height = height;
        m_pixels = new Pixel * [m_height];
        for (int i = 0; i < m_height; i++)
            m_pixels[i] = new Pixel[m_width];

        m_coordinates = new Vec2d * [m_height];
        for (int i = 0; i < m_height; i++)
            m_coordinates[i] = new Vec2d[m_width];

        for (int i = 0; i < m_height; i++)
            for (int j = 0; j < m_width; j++)
                m_pixels[i][j] = { 0,0,0 };

        for (int i = 0; i < m_height; i++)
            for (int j = 0; j < m_width; j++)
            {
                m_coordinates[i][j].set(0, 0, j);
                m_coordinates[i][j].set(1, 0, i);
            }
    }

    // TODO
    BMP::BMP(const BMP& bmp)
    {
        if (m_pixels != nullptr)
        {
            for (int i = 0; i < m_height; i++)
                delete[] m_pixels[i];
            delete[] m_pixels;
        }

        m_width = bmp.m_width;
        m_height = bmp.m_height;

        m_pixels = new Pixel * [m_height];
        for (int i = 0; i < m_height; i++)
            m_pixels[i] = new Pixel[m_width];

        for (int i = 0; i < m_height; i++)
            for (int j = 0; j < m_width; j++)
                m_pixels[i][j] = bmp.m_pixels[i][j];
    }

    // TODO
    BMP& BMP::operator=(const BMP& bmp)
    {
        if (m_pixels != nullptr)
        {
            for (int i = 0; i < m_height; i++)
                delete[] m_pixels[i];
            delete[] m_pixels;
        }

        m_width = bmp.m_width;
        m_height = bmp.m_height;

        m_pixels = new Pixel * [m_height];
        for (int i = 0; i < m_height; i++)
            m_pixels[i] = new Pixel[m_width];

        for (int i = 0; i < m_height; i++)
            for (int j = 0; j < m_width; j++)
                m_pixels[i][j] = bmp.m_pixels[i][j];

        return *this;
    }

    BMP::~BMP()
    {
        for (int i = 0; i < m_height; i++)
            delete[] m_pixels[i];
        delete[] m_pixels;

        for (int i = 0; i < m_height; i++)
            delete[] m_coordinates[i];
        delete[] m_coordinates;
    }

    void BMP::Fill(Pixel pixel)
    {
        for (int i = 0; i < m_height; i++)
            for (int j = 0; j < m_width; j++)
                m_pixels[i][j] = pixel;
    }

    // TODO
    void BMP::Open(const std::string& filename)
    {
        //  
        std::ifstream in(filename, std::ios::binary); //     

        BMPHEADER bmpHeader;
        //  14      BMPHEADER
        in.read(reinterpret_cast<char*>(&bmpHeader), sizeof(BMPHEADER));

        BMPINFO bmpInfo;
        in.read(reinterpret_cast<char*>(&bmpInfo), sizeof(BMPINFO));

        if (m_pixels != nullptr)
        {
            for (int i = 0; i < m_height; i++)
                delete[] m_pixels[i];
            delete[] m_pixels;
        }

        m_width = bmpInfo.Width;
        m_height = bmpInfo.Height;

        m_pixels = new Pixel * [m_height];
        for (int i = 0; i < m_height; i++)
            m_pixels[i] = new Pixel[m_width];
        m_coordinates = new Vec2d * [m_height];
        for (int i = 0; i < m_height; i++)
            m_coordinates[i] = new Vec2d[m_width];

        for (int i = 0; i < bmpInfo.Height; i++)
        {
            for (int j = 0; j < bmpInfo.Width; j++)
                in.read(reinterpret_cast<char*>(&m_pixels[i][j]), sizeof(Pixel));

            if ((3 * bmpInfo.Width) % 4 != 0)
                for (int j = 0; j < 4 - (3 * bmpInfo.Width) % 4; j++)
                {
                    char c;
                    in.read(&c, 1);
                }
        }
        for (int i = 0; i < m_height; i++)
            for (int j = 0; j < m_width; j++)
            {
                m_coordinates[i][j].set(0, 0, j);
                m_coordinates[i][j].set(1, 0, i);
            }
    }

    void BMP::Save(const std::string& filename)
    {
        if (m_width == 0 || m_height == 0)
            throw std::exception("Zero height or width");

        //  
        std::ofstream out(filename, std::ios::binary);

        //  
        BMPHEADER bmpHeader_new;
        bmpHeader_new.Type = 0x4D42; //   BMP
        bmpHeader_new.Size = 14 + 40 + (3 * m_width * m_height);
        if (m_width % 4 != 0)
            bmpHeader_new.Size += (4 - (3 * m_width) % 4) * m_height;
        bmpHeader_new.OffBits = 54;
        bmpHeader_new.Reserved1 = 0;
        bmpHeader_new.Reserved2 = 0;

        out.write(reinterpret_cast<char*>(&bmpHeader_new), sizeof(BMPHEADER));

        //    
        BMPINFO bmpInfo_new;
        bmpInfo_new.BitCount = 24;
        bmpInfo_new.ClrImportant = 0;
        bmpInfo_new.ClrUsed = 0;
        bmpInfo_new.Compression = 0;
        bmpInfo_new.Height = m_height;
        bmpInfo_new.Planes = 1;
        bmpInfo_new.Size = 40;
        bmpInfo_new.SizeImage = bmpHeader_new.Size - 54;
        bmpInfo_new.Width = m_width;
        bmpInfo_new.XPelsPerMeter = 0;
        bmpInfo_new.YPelsPerMeter = 0;

        out.write(reinterpret_cast<char*>(&bmpInfo_new), sizeof(BMPINFO));

        //  
        for (int i = 0; i < bmpInfo_new.Height; i++)
        {
            for (int j = 0; j < bmpInfo_new.Width; j++)
                out.write(reinterpret_cast<char*>(&m_pixels[i][j]), sizeof(Pixel));

            if ((3 * bmpInfo_new.Width) % 4 != 0)
                for (int j = 0; j < 4 - (3 * bmpInfo_new.Width) % 4; j++)
                {
                    char c = 0;
                    out.write(&c, 1);
                }
        }
    }
    void BMP::Rotate(double angle)
    {
        // 1.   
        angle = angle * acos(-1) / 180;
        Vec2d T({ {
            {(double)(m_width / 2)},
            {(double)(m_height / 2)}
        } });

        for (int i = 0; i < m_height; i++)
            for (int j = 0; j < m_width; j++)
                m_coordinates[i][j] = m_coordinates[i][j] - T;

        // 2. 
        Mat22d R({ {
            {cos(angle), sin(angle)},
            {-sin(angle), cos(angle)}
        } });

        for (int i = 0; i < m_height; i++)
            for (int j = 0; j < m_width; j++)
            {
                m_coordinates[i][j] = R * m_coordinates[i][j];
                //std::cout << m_coordinates[i][j] << std::endl;
            }

        // 3.      
        int maxX = INT_MIN;
        int minX = INT_MAX;
        int maxY = INT_MIN;
        int minY = INT_MAX;
        for (int i = 0; i < m_height; i++)
            for (int j = 0; j < m_width; j++)
            {
                if (maxX < m_coordinates[i][j].get(0, 0))
                    maxX = m_coordinates[i][j].get(0, 0);
                if (minX > m_coordinates[i][j].get(0, 0))
                    minX = m_coordinates[i][j].get(0, 0);
                if (maxY < m_coordinates[i][j].get(1, 0))
                    maxY = m_coordinates[i][j].get(1, 0);
                if (minY > m_coordinates[i][j].get(1, 0))
                    minY = m_coordinates[i][j].get(1, 0);
            }

        //       -  
        maxX++;
        minX--;
        maxY++;
        minY--;

        int width = maxX - minX;
        int height = maxY - minY;

        //     
        Vec2d shift({ {
            {(double)(width / 2)},
            {(double)(height / 2)}
        } });
        Vec2d test({ {
            {(double)(-1)},
            {(double)(-1)}
        } });
        for (int i = 0; i < m_height; i++)
            for (int j = 0; j < m_width; j++)
                m_coordinates[i][j] = m_coordinates[i][j] + shift;

        //   
        Pixel** new_pixels = new Pixel * [height];
        for (int i = 0; i < height; i++)
            new_pixels[i] = new Pixel[width];

        Vec2d** new_coordinates = new Vec2d * [height];
        for (int i = 0; i < height; i++)
            new_coordinates[i] = new Vec2d[width];
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                new_coordinates[i][j] = test;
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                new_pixels[i][j] = {0,0,0};



        //  
        for (int i = 0; i < m_height; i++)
            for (int j = 0; j < m_width; j++)
            {
                if (m_coordinates[i][j].get(0, 0) >= 0)
                {
                    int x = (int)(m_coordinates[i][j].get(0, 0));
                    int y = (int)(m_coordinates[i][j].get(1, 0));
                    new_pixels[y][x] = m_pixels[i][j];

                    new_coordinates[y][x].set(0, 0, (int)(m_coordinates[i][j].get(0, 0)));
                    new_coordinates[y][x].set(1, 0, (int)(m_coordinates[i][j].get(1, 0)));
                }
            }

        for (int i = 0; i < m_height; i++)
            delete[] m_pixels[i];
        delete[] m_pixels;

        for (int i = 0; i < m_height; i++)
            delete[] m_coordinates[i];
        delete[] m_coordinates;

        m_pixels = new_pixels;
        m_coordinates = new_coordinates;

        m_width = width;
        m_height = height;
    }
    void BMP::Repair()
    {
        for (int i = 0; i < m_height - 1; i++)
            for (int j = 0; j < m_width - 1; j++)
            {
                int summ_g = 0;
                int summ_b = 0;
                int summ_r = 0;
                int k = 0;
                if (m_coordinates[i][j].get(0, 0) == -1)
                {
                    if (i + 1 <= m_height)
                    {
                        summ_b += (int)m_pixels[i + 1][j].b;
                        summ_g += (int)m_pixels[i + 1][j].g;
                        summ_r += (int)m_pixels[i + 1][j].r;
                        k += 1;

                    }
                    if (i - 1 >= 0)
                    {
                        summ_b += (int)m_pixels[i - 1][j].b;
                        summ_r += (int)m_pixels[i - 1][j].r;
                        summ_g += (int)m_pixels[i - 1][j].g;
                        k += 1;
                    }
                    if (j + 1 <= m_width)
                    {
                        summ_b += (int)m_pixels[i][j + 1].b;
                        summ_r += (int)m_pixels[i][j + 1].r;
                        summ_g += (int)m_pixels[i][j + 1].g;
                        k += 1;
                    }
                    if (j - 1 >= 0)
                    {
                        summ_b += (int)m_pixels[i][j - 1].b;
                        summ_r += (int)m_pixels[i][j - 1].r;
                        summ_g += (int)m_pixels[i][j - 1].g;
                        k += 1;
                    }
                    if ((i + 1 <= m_height) && (j + 1 <= m_width))
                    {
                        summ_b += (int)m_pixels[i + 1][j + 1].b;
                        summ_r += (int)m_pixels[i + 1][j + 1].r;
                        summ_g += (int)m_pixels[i + 1][j + 1].g;
                        k += 1;
                    }
                    if ((i - 1 >= 0) && (j + 1 <= m_width))
                    {
                        summ_b += (int)m_pixels[i - 1][j + 1].b;
                        summ_r += (int)m_pixels[i - 1][j + 1].r;
                        summ_g += (int)m_pixels[i - 1][j + 1].g;
                        k += 1;
                    }
                    if ((i + 1 <= m_height) && (j - 1 >= 0))
                    {
                        summ_b += (int)m_pixels[i + 1][j - 1].b;
                        summ_r += (int)m_pixels[i + 1][j - 1].r;
                        summ_g += (int)m_pixels[i + 1][j - 1].g;
                        k += 1;
                    }
                    if ((i - 1 >= 0) && (j - 1 >= 0))
                    {
                        summ_b += (int)m_pixels[i - 1][j - 1].b;
                        summ_r += (int)m_pixels[i - 1][j - 1].r;
                        summ_g += (int)m_pixels[i - 1][j - 1].g;
                        k += 1;
                    }

                    m_pixels[i][j].b = unsigned char(summ_b / k);
                    m_pixels[i][j].r = unsigned char(summ_r / k);
                    m_pixels[i][j].g = unsigned char(summ_g / k);
                }
            }
    }

}
