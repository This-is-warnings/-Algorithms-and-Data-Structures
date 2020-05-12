#pragma once
#include <Windows.h>
#include<list>
using namespace std;
class Deque
{
private:
	list<int> list;
public:
	void add_to_begin(int value)
	{
		list.push_front(value);
	}
	void add_to_end(int value)
	{
		list.push_back(value);
	}
	int ret_first()
	{
		if (list.empty()) {
			cout << "Дек пустой.\n";
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
			cout << "Дек пустой.\n";
			system("pause");

			return -1;
		}
		else {
			return list.back();
		}
	}
	bool del_in_begin()
	{
		if (list.empty()) {
			return false;
		}
		else { list.pop_front(); return true; }
	}
	bool del_in_end()
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
