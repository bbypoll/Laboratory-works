// 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    short unsigned int N;
    cout << "Введите N: ";
    cin >> N;
    switch (N)
    {
    case 1:
    {
        cout << "Это понедельник." << endl;
        break;
    }
    case 2:
    {
        cout << "Это вторник." << endl;
        break;
    }
    case 3:
    {
        cout << "Это среда." << endl;
        break;
    }
    case 4:
    {
        cout << "Это четверг." << endl;
        break;
    }
    case 5:
    {
        cout << "Это пятница." << endl;
        break;
    }
    case 6:
    {
        cout << "Это суббота." << endl;
        break;
    }
    case 7:
    {
        cout << "Это воскресенье." << endl;
        break;
    }
    default:
    {
        cout << "В неделе 7 дней." << endl;
        break;
    }
    return 0;
    }
}

