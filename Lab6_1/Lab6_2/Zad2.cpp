#include <Windows.h>
#include <iostream>
#include "Deque.h"
#include"Stack.h"
#include"Queue.h"

using namespace std;
// Вариант 2. Приложение, моделирующее жизнь посуды на кухне:

// Грязная посуда это стек: берем из начала и ложим тоже в начало

// Стопки посуды в машине это очереди: вначале снимают чистую, в конец ложат грязную

// Посуда на полке это дэк: можно ставить и в начало и в конец

int main()
{
	setlocale(LC_ALL, "");
	Stack DirtyDishes;
	Queue Dishwasher1, Dishwasher2;
	Deque CleanDishes;
/* Возможные действия : 
	1 - Переложить грязную посуду в посудомоечную машину
	2 - Чистую посуду переложить из посудомоечной машины в стопку чистой посуды на столе
	3 - Перевести посуду из чистой полки в статус грязной */
	// Заполняем структуры данных
	for (int i = 0; i < 10; i++)
	{
		DirtyDishes.add(1);
		Dishwasher1.add(1);
		Dishwasher2.add(1);
		CleanDishes.add_to_begin(1);
	}
	int choise;
	int dish = 1; // выбор одной из двух стопок в посудом. машине(будет посменной чередоваться)
	int randch = 1; // выбор с какой стороны взять или положить чистую посуду 
	bool b1=true, b2 = true, b3=true;
	while (true)
	{
		if (DirtyDishes.isEmpty())								// вначале идет проверка на пустоту.
		{														// если какая-то из стопок с посудой пустая то мы не можем
																// забрать из нее тарелку.
			b1 = false;											// поэтому нельзя допустить выпадения числа, при котором невозможно будет взять 
																// тарелку из стопки
		}
		if (Dishwasher1.isEmpty() || Dishwasher2.isEmpty())
		{
			b2 = false;
		}
		if (CleanDishes.isEmpty())
		{
			b3 = false;
		}
		while (true) { // цикл проверки и выбора числа
			choise = rand() % 3 + 1;
			if (b1 && b2 && b3)
			{
				break;
			}
			else
			{
				if (b1 == false && choise != 1) break;				
				if (b2 == false && choise != 2) break;
				if (b3 == false && choise != 3) break;
			}
		}
		b1 = true; b2 = true; b3 = true;
		switch (choise)
		{
		case 1:
		{
			cout << "Положили грязную тарелку в посудомоечную машину\n";
			DirtyDishes.del();
			if (dish == 1)
			{
				Dishwasher1.add(1);
				dish = 2;
			}
			else
			{
				Dishwasher1.add(1);
				dish = 1;
			}
			break;
		}
		case 2:
		{
			cout << "Положили чистую посуду из машины в стопку\n";
			if (Dishwasher1.isEmpty())      // если одна очередь пустая, то берем тарелку из другой очереди
			{
				Dishwasher2.del();
				dish = 2;
			}
			else if (Dishwasher2.isEmpty())
			{
				Dishwasher1.del();
				dish = 1;
			}
			else {
				if (dish == 1)
				{
					Dishwasher2.del();
					dish = 2;
				}
				else
				{
					Dishwasher1.del();
					dish = 1;
				}
			}
			randch = rand() % 2 + 1;
			if (randch == 1) {
				CleanDishes.add_to_end(1);
			}
			else {
				CleanDishes.add_to_begin(1);
			}

			break;
		}
		case 3:
		{
			cout << "Перевели чистую посуду в статус грязной\n";
			randch = rand() % 2 + 1;
			if (randch == 1) {
				CleanDishes.del_in_begin();
			}
			else {
				CleanDishes.del_in_end();
			}
			DirtyDishes.add(1);
			break;
		}
		}
		Sleep(2000); // интервал 2 секунды
	}
	system("pause");
	return 0;
}