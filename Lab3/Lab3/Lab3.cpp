#include "pch.h"
#include <iostream>
#include <Windows.h>

using namespace std;

int* crossing(int* array, int low, int mid, int high) {

	int max_left = 0, left_sum = 0;
	int sum = 0;
	for (int i = mid; i >= low; i--) {  //левая половина
		sum += array[i];
		if (sum > left_sum) {
			left_sum = sum;
			max_left = i;
		}
	}

	int right_sum = 0, max_right = 0;
	sum = 0;
	for (int j = mid + 1; j <= high; j++) {   //правая половина
		sum += array[j];
		if (sum > right_sum) {
			right_sum = sum;
			max_right = j;
		}
	}
	int ret[3] = { max_left, max_right, left_sum + right_sum };
	return ret;
}

int* max_subarray(int* array, int low, int high) {
	int mid;
	if (high == low) {
		int ret[3] = { low, high, array[low] };
		return ret;

	}//только один элемент
	else {
		mid = (low + high) / 2;

		int* left = max_subarray(array, low, mid);  //ищем максимальный подмассив в левой части
		int left_low = left[0];
		int left_high = left[1];
		int left_sum = left[2];

		int* right = max_subarray(array, mid + 1, high);   //ищем максимальный в правой
		int right_low = right[0];
		int right_high = right[1];
		int right_sum = right[2];

		int* cross = crossing(array, low, mid, high); // ищем максимальный в центре
		int cross_low = cross[0];
		int cross_hight = cross[1];
		int cross_sum = cross[2];
	// возвращаем те значения, которые больше
		if (left_sum >= right_sum && left_sum >= cross_sum)
		{
			int ret[3] = { left_low, left_high, left_sum };
			return ret;
	
		}
		else if (right_sum >= left_sum && right_sum >= cross_sum)
		{
			int ret[3] = { right_low, right_high, right_sum };
			return ret;
		}
		else
		{
			int ret[3] = { cross_low, cross_hight, cross_sum };
			return ret;
		}
	}
}

int main()
{
	setlocale(0, "rus");
	int array_price[] = { 100, 113, 110, 85, 105, 102, 86, 63, 81, 101, 94, 106, 101, 79, 94, 90, 97 };
	int *change = new int[16];

	for (int i = 1; i < 17; i++) {
		change[i - 1] = array_price[i] - array_price[i - 1];
		
	}

	cout << "№         ";
	for (int i = 0; i < 17; i++) {
		printf("%5d", i);
	}

	cout<<"\nЦена:     ";
	for (int i = 0; i < 17; i++) {
		printf("%5d", array_price[i]);
	}

	cout << "\nИзменение:     ";
	for (int i = 0; i <16; i++) {
		printf("%5d", change[i]);
	}

	int low = 0, high = 15;
	int* res = max_subarray(change, low, high);

	int a = res[0], b = res[1], c = res[2];
	cout << "\nМаксимальный подмасссив: с " << res[0] + 1 << " до " << res[1] + 1 << "\nСумма = " << res[2] << endl;


	cout << "Лучше всего покупать после торгов в " << a << "-й день" << ", продавать в " << (b + 1) << "-й день" << endl;
	system("pause");
	return 0;
}