#include <Windows.h>
#include "Classes.h"
#include <deque>
#include <map>
#include <memory>

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//Создаём объекты cake
	cake obj1("A", 1, 10), obj2("B", 2, 20), obj3("C", 3, 30), obj4("D", 4, 40);
	cake obj5("I", 5, 50), obj6("F", 6, 60), obj7("G", 7, 70), obj8("H", 8, 80);
	//Создание контейнеров multimap
	unique_ptr< multimap<string, cake> > First(new multimap<string, cake>);
	unique_ptr< multimap<string, cake> > Second(new multimap<string, cake>({ { "Sfirst", obj5 },{ "Ssecond", obj6 },{ "Sthird", obj7 },{ "Sfourth", obj8 } }));
	//Инициализация
	First->insert(pair<string, cake>("Ffirst", obj1));
	First->insert(pair<string, cake>("Fsecond", obj2));
	First->insert(pair<string, cake>("Fthird", obj3));
	First->insert(pair<string, cake>("Ffourth", obj4));
	//Просмотр содержимого
	cout << "Просмотр содержимого First: " << endl;
	int i = 1;
	if (First->empty())
		cout << "---------\nПУСТО\n---------" << endl;
	else
	{
		for (auto it = First->begin(); it != First->end(); ++it, i++)
			cout << i << ")" << it->first << ":" << it->second << endl;
		i = 1;
	}
	//Удаление элементов
	First->clear();
	//Просмотр содержимого после удаления
	cout << "\nПросмотр содержимого First после удаления: " << endl;
	if (First->empty())
		cout << "---------\nПУСТО\n---------" << endl;
	else
	{
		for (auto it = First->begin(); it != First->end(); ++it, i++)
			cout << i << ")" << it->first << ":" << it->second << endl;
		i = 1;
	}
	//Присваиваем новые элементы
	for (auto it = Second->begin(); it != Second->end(); ++it)
		First->insert(pair<string, cake>(it->first, it->second));
	//Просматриваем содержимое после присваивания
	cout << "\nПросмотр содержимого после присваивания: " << endl;
	if (First->empty())
		cout << "---------\nПУСТО\n---------" << endl;
	else
	{
		for (auto it = First->begin(); it != First->end(); ++it, i++)
			cout << i << ")" << it->first << ":" << it->second << endl;
		i = 1;
	}
	//Просмотр содержимого используя reverse-итераторы
	cout << "\nПросмотр содержимого используя reverse-итераторы: " << endl;
	if (First->empty())
		cout << "---------\nПУСТО\n---------" << endl;
	else
	{
		for (auto it = First->crbegin(); it != First->crend(); it++, i++)
			cout << i << ")" << it->first << ":" << it->second << endl;
		i = 1;
	}
	//Создаём контейнер типа deque
	shared_ptr< deque<cake> > Deq(new deque<cake>);
	Deq->push_front(obj1);
	Deq->push_back(obj2);
	Deq->push_front(obj3);
	//Изменяем multimap::First: удаляем n элементов после заданного и добавляем элементы из deque::Deq
	auto itb = ++First->begin(); ///Итератор на начальное значение диапазона
	auto ite = itb;
	for (; i < 4; i++, ++ite); ///Итератор на конечное значение диапазона
	i = 1;
	First->erase(itb, ite); ///Удаляем 3 элемента
						   //Просмотр содержимого First после удаления 3 элементов
	cout << "\nПросмотр содержимого First после удаления 3 элементов" << endl;
	if (First->empty())
		cout << "---------\nПУСТО\n---------" << endl;
	else
	{
		for (auto it = First->crbegin(); it != First->crend(); it++, i++)
			cout << i << ")" << it->first << ":" << it->second << endl;
		i = 1;
	}
	//Присваивание элементов Deq в First
	i = 0;
	char t = 'a';
	for (string str = ""; i < Deq->size(); i++, t++, str = "")
		First->insert(pair<string, cake>(str + t, *(Deq->begin() + i)));
	i = 1;
	//Просмотр содержимого First после манипуляций с Deq
	cout << "\nПросмотр содержимого First после манипуляций с Deq" << endl;
	if (First->empty())
		cout << "---------\nПУСТО\n---------" << endl;
	else
	{
		for (auto it = First->begin(); it != First->end(); it++, i++)
			cout << i << ")" << it->first << ":" << it->second << endl;
		i = 1;
	}
	weak_ptr<int> G;
	shared_ptr<int> D(new int(6));
	G = D; // Теперь G отслеживает объект, на который указывает D
	// D = G /// Не сработает, так же как и с другими видами интеллектуальных указателей
}