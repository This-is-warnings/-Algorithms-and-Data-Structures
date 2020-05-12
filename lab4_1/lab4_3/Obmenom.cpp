#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;
// ¬ыбором
int main()
{
	srand(time(0));
	const int array_size = 10000;
	int compare = 0;
	int swap = 0;
	int array1[array_size];
	for (int counter = 0; counter < array_size; counter++)
	{
		array1[counter] = counter * 10;
		//array1[counter] = rand() % 1000 - rand() % 1000; // заполн€ем массив случайными значени€ми в диапазоне от -49 до 49 включительно
		cout << array1[counter] << " "; // печать элементов одномерного массива array1
	}
	cout << endl;
	
	int temp = 0;
	
	unsigned int start_time = clock();
	for (int i = array_size ; i >=0; i--)    // сравниваем попарно
	{
		for (int j = 0; j < array_size-1; j++)
		{
			compare++;
			if (array1[j] > array1[j + 1])
			{
				swap++;
				temp = array1[j];
				array1[j] = array1[j + 1];
				array1[j + 1] = temp;
			}
		}
	}
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << "runtime = " << search_time << endl; // врем€ работы программы  

	cout << endl;
	for (int counter = 0; counter < array_size; counter++)
	{
		//array1[counter] = rand() % 150 - rand() % 150; // заполн€ем массив случайными значени€ми в диапазоне от -49 до 49 включительно
		cout << array1[counter] << " "; // печать элементов одномерного массива array1
	}

	cout << endl;
	cout << "compare: " << compare << " swap: " << swap << endl;
	system("pause");
	return 0;
}