#pragma once
#include <iostream>
#include <string>

using namespace std;

class cake
{
private:
	string name;
	int weight;
	int price;
public:
	~cake()
	{
		name = "Не определён";
		weight = NULL;
		price = NULL;
	}
	cake() : name("Не определён"), weight(NULL), price(NULL)
	{}
	cake(string Name, int Weight, int Price) : weight(Weight), price(Price), name(Name)
	{}
	void set();
	void set(string Name);
	void set(int Price);
	void set(int Weight, int Price);
	void set(string Name, int Weight, int Price);
	void get();
	friend ostream& operator<<(ostream& os, cake obj);
};