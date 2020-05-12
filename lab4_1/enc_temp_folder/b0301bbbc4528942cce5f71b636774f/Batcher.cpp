#include <iostream>
#include <Windows.h>
#include <ctime>
using namespace std;

int logForT(int n)
{
	for (int i = 0; i < n; i++)
	{
		if (pow(2, i) >= n) return i;
	}
}
int main()
{

	int compare = 0;
	int swap1 = 0;
	const int n = 8;
	//int mas[16] = { 503,87,512,61,908,170,897,275,653,426,154,509,612, 677,765,703 };
	int mas[n];
	for (int i = 0; i < n; i++)
	{
		//mas[i] = i * 10;
		mas[i] = rand() % 100 - rand() % 100; // заполн€ем массив случайными значени€ми в диапазоне от -49 до 49 включительно
		cout << mas[i] << " ";
	}
	// M1
	cout << endl;
	unsigned int start_time = clock();
	int t = logForT(n);
	int p = pow(2, t - 1);
	int q, r, d;
	// M2
	while (p > 0) {
		q = pow(2, t - 1);
		r = 0;
		d = p;
		while (true) {
			cout << "for p: " << p << " q: " << q << " r: " << r << " d: " << d << endl;
			for (int i = 0; i < n - d; i++) {
				//if ((i&p) == r)
			//	{
					compare++;
					cout << i << " and " << i + d << " ";
					if (mas[i] > mas[i + d]) {
						swap1++;
						swap(mas[i], mas[i + d]);
					}
			//	}
			}
			cout << endl << endl;
			if (q != p) {
				d = q - p;
				q = q / 2;
				r = p;

			}
			else break;
		}
		p = p / 2;
	}
	//if (p > 0) goto M2;

	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	cout << "runtime = " << search_time << endl; // врем€ работы программы  

	for (int i = 0; i < n; i++)
	{
		cout << mas[i] << " ";
	}
	cout << endl;
	cout << "compare: " << compare << " swap: " << swap1 << endl;
	system("pause");
	return 0;
}