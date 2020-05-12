#include <Windows.h>
#include <iostream>
#include <ctime>

using namespace std;
// Выбором
int main()
{
	srand(time(0));
	int compare = 0;
	int swap1 = 0;
	const int array_size = 10000;
	int array1[array_size];
	for (int counter = 0; counter < array_size; counter++)
	{
	
		//array1[counter] = rand() % 10000 - rand() % 10000; // CЛучайный порядок
		array1[counter] = counter * 10;
		cout << array1[counter] << " "; // печать элементов одномерного массива array1
	}
	//for (int i = 0; i < array_size; i++)
	//{
	//	array1[i] = i * 10;
	//}
	cout << endl;
	int max = array1[0]; 
	int indMax = 0;
	int temp = 0;
//	int count = 0;
	//srand(time(0));
	unsigned int start_time = clock();
	for (int j = array_size-1; j >=0; j--) {
		for (int i = 0; i <= j; i++)
		{
			compare++;
			if (max < array1[i]) { // поиск макс. и смена с последним
				max = array1[i];
				indMax = i;
			}
		}
		
		//count++;
		//cout << "Count = " << count << ", indMax = " << indMax << ", max = " << max << endl;
		swap1++;
		
		//swap(array1[indMax], array1[j]);
		temp = array1[indMax];
		array1[indMax] = array1[j];
		array1[j] = temp;
		max = array1[0];
		indMax = 0;
	}
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << "runtime = " << search_time << endl; // время работы программы  

	cout << endl;
	for (int counter = 0; counter < array_size; counter++)
	{
	
		cout << array1[counter] << " "; // печать элементов одномерного массива array1
	}

	cout << endl;
	                
	cout << "compare: " << compare << " swap: " << swap1 << endl;
	system("pause");
	return 0;
}