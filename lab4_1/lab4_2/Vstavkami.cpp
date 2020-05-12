#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	
	const int array_size = 1000;
	int temp;
	int compare = 0;
	int swap1 = 0;
	int array1[array_size];
	for (int counter = 0; counter < array_size; counter++)
	{
		//array1[counter] = counter * (-10);
		array1[counter] = rand() % 10000 - rand() % 10000; // заполняем массив случайными значениями в диапазоне от -49 до 49 включительно
		cout << array1[counter] << " "; // печать элементов одномерного массива array1
	}
	unsigned int start_time = clock();
	for (int i = 1; i < array_size; i++)// сортируем с самого начала и ищем место
		for (int j = i; j > 0; j--) {// пока j>0 и элемент j-1 > j, x-массив int
			compare++;
			if (array1[j - 1] > array1[j]) {
				//swap(array1[j - 1], array1[j]);
				temp = array1[j - 1];
				array1[j - 1] = array1[j];
				array1[j] = temp;
				swap1++;
			}
			else break;// меняем местами элементы j и j-1
		}
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << endl << "runtime " << search_time;
	cout << endl;
	for (int counter = 0; counter < array_size; counter++)
	{
		//array1[counter] = rand() % 150 - rand() % 150; // заполняем массив случайными значениями в диапазоне от -49 до 49 включительно
		cout << array1[counter] << " "; // печать элементов одномерного массива array1
	}

	cout << endl;
	cout << "compare: " << compare << " swap: " << swap1 << endl;
	//cout << "runtime = " << clock() / 1000.0 << endl; // время работы программы                  
	system("pause");
	return 0;
}