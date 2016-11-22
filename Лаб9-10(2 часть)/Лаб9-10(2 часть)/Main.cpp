#include <Windows.h>
#include "Classes.h"
#include <deque>
#include <map>
#include <memory>

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//������ ������� cake
	cake obj1("A", 1, 10), obj2("B", 2, 20), obj3("C", 3, 30), obj4("D", 4, 40);
	cake obj5("I", 5, 50), obj6("F", 6, 60), obj7("G", 7, 70), obj8("H", 8, 80);
	//�������� ����������� multimap
	unique_ptr< multimap<string, cake> > First(new multimap<string, cake>);
	unique_ptr< multimap<string, cake> > Second(new multimap<string, cake>({ { "Sfirst", obj5 },{ "Ssecond", obj6 },{ "Sthird", obj7 },{ "Sfourth", obj8 } }));
	//�������������
	First->insert(pair<string, cake>("Ffirst", obj1));
	First->insert(pair<string, cake>("Fsecond", obj2));
	First->insert(pair<string, cake>("Fthird", obj3));
	First->insert(pair<string, cake>("Ffourth", obj4));
	//�������� �����������
	cout << "�������� ����������� First: " << endl;
	int i = 1;
	if (First->empty())
		cout << "---------\n�����\n---------" << endl;
	else
	{
		for (auto it = First->begin(); it != First->end(); ++it, i++)
			cout << i << ")" << it->first << ":" << it->second << endl;
		i = 1;
	}
	//�������� ���������
	First->clear();
	//�������� ����������� ����� ��������
	cout << "\n�������� ����������� First ����� ��������: " << endl;
	if (First->empty())
		cout << "---------\n�����\n---------" << endl;
	else
	{
		for (auto it = First->begin(); it != First->end(); ++it, i++)
			cout << i << ")" << it->first << ":" << it->second << endl;
		i = 1;
	}
	//����������� ����� ��������
	for (auto it = Second->begin(); it != Second->end(); ++it)
		First->insert(pair<string, cake>(it->first, it->second));
	//������������� ���������� ����� ������������
	cout << "\n�������� ����������� ����� ������������: " << endl;
	if (First->empty())
		cout << "---------\n�����\n---------" << endl;
	else
	{
		for (auto it = First->begin(); it != First->end(); ++it, i++)
			cout << i << ")" << it->first << ":" << it->second << endl;
		i = 1;
	}
	//�������� ����������� ��������� reverse-���������
	cout << "\n�������� ����������� ��������� reverse-���������: " << endl;
	if (First->empty())
		cout << "---------\n�����\n---------" << endl;
	else
	{
		for (auto it = First->crbegin(); it != First->crend(); it++, i++)
			cout << i << ")" << it->first << ":" << it->second << endl;
		i = 1;
	}
	//������ ��������� ���� deque
	shared_ptr< deque<cake> > Deq(new deque<cake>);
	Deq->push_front(obj1);
	Deq->push_back(obj2);
	Deq->push_front(obj3);
	//�������� multimap::First: ������� n ��������� ����� ��������� � ��������� �������� �� deque::Deq
	auto itb = ++First->begin(); ///�������� �� ��������� �������� ���������
	auto ite = itb;
	for (; i < 4; i++, ++ite); ///�������� �� �������� �������� ���������
	i = 1;
	First->erase(itb, ite); ///������� 3 ��������
						   //�������� ����������� First ����� �������� 3 ���������
	cout << "\n�������� ����������� First ����� �������� 3 ���������" << endl;
	if (First->empty())
		cout << "---------\n�����\n---------" << endl;
	else
	{
		for (auto it = First->crbegin(); it != First->crend(); it++, i++)
			cout << i << ")" << it->first << ":" << it->second << endl;
		i = 1;
	}
	//������������ ��������� Deq � First
	i = 0;
	char t = 'a';
	for (string str = ""; i < Deq->size(); i++, t++, str = "")
		First->insert(pair<string, cake>(str + t, *(Deq->begin() + i)));
	i = 1;
	//�������� ����������� First ����� ����������� � Deq
	cout << "\n�������� ����������� First ����� ����������� � Deq" << endl;
	if (First->empty())
		cout << "---------\n�����\n---------" << endl;
	else
	{
		for (auto it = First->begin(); it != First->end(); it++, i++)
			cout << i << ")" << it->first << ":" << it->second << endl;
		i = 1;
	}
	weak_ptr<int> G;
	shared_ptr<int> D(new int(6));
	G = D; // ������ G ����������� ������, �� ������� ��������� D
	// D = G /// �� ���������, ��� �� ��� � � ������� ������ ���������������� ����������
}