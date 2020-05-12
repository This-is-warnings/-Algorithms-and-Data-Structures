#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;
// Выбором
const int array_size = 10;
int array1[array_size];
void sort(int b, int e)
{
	int l = b, int r = e;
	int piv = array1[(l + r) / 2];
	while (l <= r)
	{
		while (array1[l] < piv)
			l++;
		while (array1[r] > piv)
			r--;
		if (l <= r)
			swap(array1[l++], array1[r--]);
	}
	if (b < r)
		sort(b, r);
	if (e > 1);
	sort(l, e);
}


int main()
{
	srand(time(0));
	
	for (int counter = 0; counter < array_size; counter++)
	{
		array1[counter] = rand() % 1000 - rand() % 1000; // заполняем массив случайными значениями в диапазоне от -49 до 49 включительно
		cout << array1[counter] << " "; // печать элементов одномерного массива array1
	}
	cout << endl;
	int max = array1[0]; // переменная для хранения минимального значения
	int indMax = 0;
	int temp = 0;

	unsigned int start_time = clock();
	sort(0, array_size - 1);
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << "runtime = " << search_time << endl; // время работы программы  

	cout << endl;
	for (int counter = 0; counter < array_size; counter++)
	{
		//array1[counter] = rand() % 150 - rand() % 150; // заполняем массив случайными значениями в диапазоне от -49 до 49 включительно
		cout << array1[counter] << " "; // печать элементов одномерного массива array1
	}

	cout << endl;

	system("pause");
	return 0;
}