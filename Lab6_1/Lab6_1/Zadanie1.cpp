#include <Windows.h>
#include <iostream>
#include "Deque.h"
#include"Stack.h"
#include"Queue.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	cout << "Проверка дееспособности структур данных.\n" << "Стэк: \n";
	Stack st;
	cout << " Добавили три элемента\n";
	for (int i = 1; i < 4; i++)
	{
		st.add(i);
	}
	cout << " Проверка на пустоту: ";
	if (st.isEmpty()) cout << "Стэк пустой\n";
	else cout << "Стэк не пустой\n";
	cout << " Последний элемент: " << st.ret() << endl;
	cout << " Удалим два элемента и проверим последний: ";
	st.del(); st.del();
	cout << st.ret() << endl;
	cout << " Удалим последний элемент и проверим на пустоту: ";
	st.del();
	if (st.isEmpty()) cout << "Стэк пустой\n";
	else cout << "Стэк не пустой\n";
	// ------------------------------------------------------------------------------
	cout << "Очередь: \n";
	Queue qu;
	cout << " Добавили четыре элемента\n";
	for (int i = 1; i <= 4; i++)
	{
		qu.add(i);
	}
	cout << " Проверка на пустоту: ";
	if (qu.isEmpty()) cout << "Очередь пустая\n";
	else cout << "Очередь не пустая\n";
	cout << " Последний элемент: " << qu.ret_last() << endl;
	cout << " Первый элемент: " << qu.ret_first() << endl;
	cout << " Удалим два элемента и проверим первый: ";
	qu.del(); qu.del();
	cout << qu.ret_first() << endl;
	cout << " Удалим последние два элемент и проверим на пустоту: ";
	qu.del(); qu.del();
	if (qu.isEmpty()) cout << "Очередь пустая\n";
	else cout << "Очередь не пустая\n";
	//----------------------------------------------------------
	cout << "Дек: \n";
	Deque de;
	cout << " Добавим два элемента: 2 и 3\n";
	de.add_to_begin(2); de.add_to_end(3);
	cout << " Проверим, первый элемент: " << de.ret_first() << " , последний элемент: " << de.ret_last() << endl;
	cout << " Добавим в начало 1, а в конец 4 и 5" << endl;
	de.add_to_begin(1); de.add_to_end(4); de.add_to_end(5);
	cout << " Проверим, первый элемент: " << de.ret_first() << " , последний элемент: " << de.ret_last() << endl;
	cout << " Удалим первый и последний\n";
	de.del_in_begin();
	de.del_in_end();
	cout << " Проверим, первый элемент: " << de.ret_first() << " , последний элемент: " << de.ret_last() << endl;
	cout << " Проверим на пустоту: ";
	if (de.isEmpty()) cout << "Дэк пустой\n";
	else cout << "Дэк не пустой\n";
	cout << " Удалим оставшиеся элементы\n";
	de.del_in_begin(); de.del_in_begin(); de.del_in_begin();
	cout << " Проверим на пустоту: ";
	if (de.isEmpty()) cout << "Дэк пустой\n";
	else cout << "Дэк не пустой\n";

	system("pause");
	return 0;
}