#include "Classes.h"

void cake::set()
{
	cout << "������� ��������: "; cin >> name;
	cout << "������� ���: "; cin >> weight;
	cout << "������� ����: "; cin >> price;
}
void cake::set(string Name)
{
	name = Name;
}
void cake::set(int Price)
{
	price = Price;
}
void cake::set(int Weight, int Price)
{
	weight = Weight;
	price = Price;
}
void cake::set(string Name, int Weight, int Price)
{
	name = Name;
	weight = Weight;
	price = Price;
}
void cake::get()
{
	cout << "1)" << name << endl;
	cout << "2)��� " << weight << endl;
	cout << "3)���� " << price << endl;
}
ostream& operator<<(ostream& os, cake obj)
{
	os << "\n\t1." << obj.name << "\n\t2." << obj.weight << "\n\t3." << obj.price << endl;
	return os;
}