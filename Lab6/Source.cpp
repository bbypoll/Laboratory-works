#include <iostream>

using namespace std;

/*¬ариант 7.
ѕодобрать структуру дл€ хранени€ данных, над которой преимущественно будут осуществл€тьс€ операции удалени€ и дублировани€.
ћинимально Ц поиск.
*/


struct El_list
{
	El_list* next;
	int num;
};

void Add(El_list* head, int num)
{
	El_list* p = new El_list;
	p->num = num;

	p->next = head->next;
	head->next = p;
}

void Print(El_list* head)
{
	El_list* p = head->next;
	while (p != nullptr)
	{
		cout << p->num << endl;
		p = p->next;
	}
}


void Del(El_list* head, int a)
{
	El_list* tmp;
	El_list* p = head;
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




void Duplicate(El_list* head)
{
	El_list* p = head->next;
	while (p != nullptr)
	{
		if (p->num % 2 == 1)
		{
			El_list* q = new El_list;
			q->next = p->next;
			p->next = q;
			q->num = p->num;
			p = p->next;
		}
		p = p->next;
	}
}


void Search(El_list* head, int k)
{
	El_list* p = head->next;
	while (p != nullptr)
	{
		if (p->num == k)
		{
			cout << p->num << endl;
			p = p->next;
		}
		else
			p = p->next;
	}
}


int main()
{
	El_list* head = new El_list;
	head->next = nullptr;

	Add(head, 2);
	Add(head, 5);
	Add(head, 7);
	Add(head, 3);
	Add(head, 9);

	Print(head);
	cout << "====" << endl;

	Del(head, 2);

	Print(head);
	cout << "====" << endl;

	Search(head, 7);

	cout << "====" << endl;

	Duplicate(head);

	Print(head);
	cout << "====" << endl;

	delete head;

	return 0;
}

