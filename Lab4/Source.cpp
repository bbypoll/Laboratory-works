/*Вариант 7.
Создайте односвязный список из 10000 целых чисел и реализуйте в нем операцию удаления элемента k. 
Если элементов, равных k несколько, удалите их все.
Выполните M = 1000 запросов на удаление.
*/
 
#include <iostream>
#include "inc/timer.h"

#define N 100
#define M 10

using namespace std;

struct El_List
{
	El_List* next;
	int num;
};

void Add(El_List* head, int num)
{
	El_List* p = new El_List;
	p->num = num;

	p->next = head->next;
	head->next = p;
}

void Print(El_List* head)
{
	El_List* p = head->next;
	while (p != nullptr)
	{
		cout << p->num << " ";
		p = p->next;
	}
}

void Clear(El_List* head)
{
	El_List* tmp;
	El_List* p = head->next;
	while (p != nullptr)
	{
		tmp = p;
		p = p->next;
		delete tmp;
	}

}
void Del(El_List* head, int a)
{
	for (int i = 0; i < M; i++)
	{
		El_List* tmp;
		El_List* p = head;
		while (p->next != nullptr)
		{
			if (p->next->num == a)
			{
				tmp = p->next;
				p->next = p->next->next;
				delete tmp;
			}
			else
				p = p->next;
		}

	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	El_List* head = new El_List;
	head->next = nullptr;
	int k;
	cout << "Введите число:" << endl;
	cin >> k;

	for (int i = 0; i < N; i++)
		Add(head, (rand() % 10));

	Print(head);
	cout << "====" << endl;

	Timer t;
	for (int i = 0; i < M; i++)
	{
		Del(head, k);
	}

	cout << "Time elapsed: " << t.elapsed() << '\n';

	Print(head);

	Clear(head);
	
	delete head;

	return 0;
}
