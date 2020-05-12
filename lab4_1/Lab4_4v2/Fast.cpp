#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;
// Выбором
const int array_size = 7;
int array1[array_size];
int compare = 0;
int swap1 = 0;
void sort(int l1, int r2)
{
	int l = l1, r = r2;
	int piv =array1[(l + r) / 2];
	while (l <= r) {
		compare++;
		while (array1[l] < piv) {
			compare++;
			l++;
		}
		compare++;
		while (array1[r] > piv) {
			compare++;
			r--;
		}
		compare++;
		if (l <= r) {
			swap(array1[l++], array1[r--]);
			swap1++;
		}
	};
	if (l1 < r) {
		sort(l1, r);
	}
	if (r2 > l) {
		sort(l, r2);
	}
}



int main()
{
	srand(time(0));

	for (int counter = 0; counter < array_size; counter++)
	{
		cin >> array1[counter];
		//array1[counter] = counter * 10;
		//array1[counter] = rand() % 10000 - rand() % 10000; // заполняем массив случайными значениями в диапазоне от -49 до 49 включительно
		//cout << array1[counter] << " "; // печать элементов одномерного массива array1
	}
	cout << endl;
	int max = array1[0]; // переменная для хранения минимального значения
	int indMax = 0;
	int temp = 0;

	unsigned int start_time = clock();
	sort(0, array_size-1);
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
	cout << "compare: " << compare << " swap: " << swap1 << endl;
	system("pause");
	return 0;
}