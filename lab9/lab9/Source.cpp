#include <iostream>
#include <list>
#include <string>
#include "Header.h"
using namespace std;



int main() {
	setlocale(0, "");
	list<Heap*> heap;
	Heap tm;
	int num = 1;
	while (num != 0) {
		system("cls");
		cout << "1.Добавить.\n2.Удаление минимального элемента.\n3.Вывод биномиального дерева.\n0-Выйти.\n";
		cin >> num;
		switch (num) {
		case 1: {
			int val;
			string value;
			while (true) {
				system("cls");
				cout << "Введите значение (для выхода нажмите - q): ";
				cin >> value;
				if (value == "q") {
					break;
				}
				val = stoi(value);
				heap = tm.insert(heap, val);
			}
			break;
		}
		case 2: {
			heap = tm.deleteMaxPriority(heap);
			break;
		}
		case 3:
		{
			system("cls");
			list<Heap*>::iterator it;
			for (it = heap.begin(); it != heap.end(); it++) {
				tm.Print_Binomial_Heap("", *it, false, false, 1);
				cout << endl << endl << endl;
			}

			break;
			}
		}
		system("pause");
	}
	system("pause");
	return 0;
}