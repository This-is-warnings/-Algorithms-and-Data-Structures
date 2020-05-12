#pragma once
#include <Windows.h>
#include<list>
using namespace std;
class Stack
{
private:
	list<int> list;
public:
	void add(int value)
	{
		list.push_back(value);
	}
	int ret()
	{
		if (list.empty()) {
			cout << "Стэк пустой.\n";
			system("pause");

			return -1;
		}
		else {
			return list.back();
		}
	}
	bool del()
	{
		if (list.empty()) {
			return false;
		}
		else { list.pop_back(); return true; }
	}
	bool isEmpty()
	{
		return list.empty();
	}
};
