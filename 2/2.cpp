// 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int A, B, C;
    cout << "Введите A ";
    cin >> A;
    cout << "Введите B ";
    cin >> B;
    cout << "Введите C ";
    cin >> C;
    if (((A % B == 0) && (B > C)) || ((A % B == 0) && (B < C )))
    {
        if ((A % B == 0) && (B > C))
        {
            int D = (A / B + C);
            cout << "A/B+C = " << D;
        }
        if ((A % B == 0) && (B < C))
        {
            int D = (A / B -C);
            cout << "A/B-C = " << D;
        }
    }
    else
    {
        int D= ((A + B)* C);
        cout << "(A+B)*C = " << D;
    }
    return 0;
}

