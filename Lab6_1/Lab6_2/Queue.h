#pragma once
#include <Windows.h>
#include<list>
using namespace std;
class Queue {
	list<int> list;
public:
	void add(int value)
	{
		list.push_back(value);
	}
	int ret_first()
	{
		if (list.empty()) {
			cout << "Очрердь пустая.\n";
			system("pause");

			return -1;
		}
		else {
			return list.front();
		}
	}
	int ret_last()
	{
		if (list.empty()) {
			cout << "Очередь пустая.\n";
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
		else { list.pop_front(); return true; }
	}
	bool isEmpty()
	{
		return list.empty();
	}
};