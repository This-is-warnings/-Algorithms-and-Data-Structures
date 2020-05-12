#include<Windows.h>
#include<iostream>
#include <iomanip>
using namespace std;
// наше заданное поле
int pole[8][8] =   // 0 - пусто, 1 - свои, 2 - пешка, 3 -конь
// 4 - слон, 5 - ладья, 6 - ферзь, 7 - король, -1 - игрок
{
	{6,0,0,0,7,5,0,0},
	{0,0,0,4,0,2,0,0},
	{0,0,2,2,0,0,0,0},
	{0,1,0,1,0,1,0,0},
	{0,0,0,0,0,0,0,0},
	{0,0,0,1,0,1,0,0},
	{0,0,0,1,0,0,0,1},
	{1,1,0,1,0,0,1,1}
};
// функция вывода поля на экран
void vivodPolya()
{
	cout << setw(3) << " " << 1 << setw(3) << 2 << setw(3) << 3
		<< setw(3) << 4 << setw(3) << 5 << setw(3) << 6
		<< setw(3) << 7 << setw(3) << 8 << endl;
	//cout << setw(3);
	for (int i = 0; i < 8; i++)
	{
		cout << i + 1 << setw(3);
		for (int j = 0; j < 8; j++)
		{
			switch (pole[i][j])
			{
			case 0:
			{
				cout << "O";
				if (j != 7) cout << setw(3);
				break;
			}
			case 1:
			{
				cout << "Т"; if (j != 7) cout << setw(3);
				break;
			}
			// 0 - пусто, 1 - свои, 2 - пешка, 3 -конь
// 4 - слон, 5 - ладья, 6 - ферзь, 7 - король, -1 - игрок
			case 2:
			{
				cout << "П"; if (j != 7) cout << setw(3);
				break;
			}
			case 3:
			{
				cout << "К"; if (j != 7) cout << setw(3);
				break;
			}
			case 4:
			{
				cout << "С"; if (j != 7) cout << setw(3);
				break;
			}
			case 5:
			{
				cout << "Л"; if (j != 7) cout << setw(3);
				break;
			}
			case 6:
			{
				cout << "Ф"; if (j != 7) cout << setw(3);
				break;
			}
			case 7:
			{
				cout << "К"; if (j != 7) cout << setw(3);
				break;
			}
			case -1:
			{
				cout << "И"; if (j != 7) cout << setw(3);
				break;
			}
			case -2:
			{
				cout << "+"; if (j != 7) cout << setw(3);
				break;
			}
			}
		}
		cout << endl;
	}
}
// поля для обозначения ходов
int poleHodov[8][8];
//вывод ходов на экран
void vivodHodov()
{
	cout << setw(3);
	for (int i = 0; i < 8; i++)   // 2 - нельзя ходить, 1 -  можно, 3 - можно сбить, 4 - игрок
	{
		for (int j = 0; j < 8; j++)
		{
			if (poleHodov[i][j] == 2) cout << "X" << setw(3);
			if (poleHodov[i][j] == 1) cout << "O" << setw(3);
			if (poleHodov[i][j] == 3)cout << "H" << setw(3);
			if (poleHodov[i][j] == 4)cout << "И" << setw(3);
		}
		cout << endl;
	}
}
// заполняем наше поле для ходов, для каждой фигуры отдельно
void updateHodov()
{
	for (int i = 0; i < 8; i++)   // 2 - нельзя ходить, 1 -  можно, 3 - можно сбить, -2 - цель
	{
		for (int j = 0; j < 8; j++)
		{
			if (pole[i][j] == -2) poleHodov[i][j] = 1;
			if (pole[i][j] == 0) poleHodov[i][j] = 1;
			if (pole[i][j] == 1) poleHodov[i][j] = 2;
			if (pole[i][j] >= 2) poleHodov[i][j] = 3;

		}
	}
	for (int i = 0; i < 8; i++)   // 2 - нельзя ходить, 1 -  можно, 3 - можно сбить
									// 
	{
		for (int j = 0; j < 8; j++)
		{
			if (pole[i][j] >= 2) {
				switch (pole[i][j])
				{
				case 2:
				{
					if (i != 0 && j != 7) poleHodov[i - 1][j + 1] = 2;
					if (i != 7 && j != 7) poleHodov[i + 1][j + 1] = 2;
					break;
				}
				case 3:
				{
					if (i > 0 && j > 1) poleHodov[i - 1][j - 2] = 2;
					if (i > 1 && j > 0) poleHodov[i - 2][j - 1] = 2;
					if (i > 1 && j < 7) poleHodov[i - 2][j + 1] = 2;
					if (i > 0 && j < 6) poleHodov[i - 1][j + 2] = 2;
					if (i < 7 && j < 6) poleHodov[i + 1][j + 2] = 2;
					if (i < 6 && j < 7) poleHodov[i + 2][j + 1] = 2;
					if (i < 6 && j > 0) poleHodov[i + 2][j - 1] = 2;
					if (i < 7 && j > 1) poleHodov[i + 1][j - 2] = 2;
					break;
				}
				case 4:
				{
					int k = i, l = j;
					if (k > 0 && l > 0)
					{
						while (pole[k - 1][l - 1] != 1)
						{
							poleHodov[k - 1][l - 1] = 2;
							k--;
							l--;
							if (k == 0 || l == 0) break;
						}
					}
					k = i; l = j;
					if (k != 7 && l != 0)
					{
						while (pole[k + 1][l - 1] != 1)
						{
							poleHodov[k + 1][l - 1] = 2;
							k++;
							l--;
							if (k == 7 || l == 0) break;
						}
					}
					k = i; l = j;
					if (k != 0 && l != 7)
					{
						while (pole[k - 1][l + 1] != 1)
						{
							poleHodov[k - 1][l + 1] = 2;
							k--;
							l++;
							if (k == 0 || l == 7) break;
						}
					}
					k = i; l = j;
					if (k != 7 && l != 7)
					{
						while (pole[k + 1][l + 1] != 1)
						{
							poleHodov[k + 1][l + 1] = 2;
							k++;
							l++;
							if (k == 7 || l == 7) break;
						}
					}

					break;
				}
				case 5:
				{
					int k = i, l = j;
					if (k != 0)
					{
						while (pole[k - 1][l] != 1)
						{
							poleHodov[k - 1][l] = 2;
							k--;
							if (k == 0) break;
						}
					}
					k = i;
					if (l != 0)
					{
						while (pole[k][l - 1] != 1)
						{
							poleHodov[k][l - 1] = 2;
							l--;
							if (l == 0) break;
						}
					}
					l = j;
					if (k != 7)
					{
						while (pole[k + 1][l] != 1)
						{
							poleHodov[k + 1][l] = 2;
							k++;
							if (k == 7) break;
						}
					}
					k = i;
					if (l != 7)
					{
						while (pole[k][l + 1] != 1)
						{
							poleHodov[k][l + 1] = 2;
							l++;
							if (l == 7) break;
						}
					}
					break;
				}
				case 6:
				{
					int k = i, l = j;
					if (k > 0 && l > 0)
					{
						while (pole[k - 1][l - 1] != 1)
						{
							poleHodov[k - 1][l - 1] = 2;
							k--;
							l--;
							if (k == 0 || l == 0) break;
						}
					}
					k = i; l = j;
					if (k != 7 && l != 0)
					{
						while (pole[k + 1][l - 1] != 1)
						{
							poleHodov[k + 1][l - 1] = 2;
							k++;
							l--;
							if (k == 7 || l == 0) break;
						}
					}
					k = i; l = j;
					if (k != 0 && l != 7)
					{
						while (pole[k - 1][l + 1] != 1)
						{
							poleHodov[k - 1][l + 1] = 2;
							k--;
							l++;
							if (k == 0 || l == 7) break;
						}
					}
					k = i; l = j;
					if (k != 7 && l != 7)
					{
						while (pole[k + 1][l + 1] != 1)
						{
							poleHodov[k + 1][l + 1] = 2;
							k++;
							l++;
							if (k == 7 || l == 7) break;
						}
					}
					k = i; l = j;

					if (k != 0)
					{
						while (pole[k - 1][l] != 1)
						{
							poleHodov[k - 1][l] = 2;
							k--;
							if (k == 0) break;
						}
					}
					k = i;
					if (l != 0)
					{
						while (pole[k][l - 1] != 1)
						{
							poleHodov[k][l - 1] = 2;
							l--;
							if (l == 0) break;
						}
					}
					l = j;
					if (k != 7)
					{
						while (pole[k + 1][l] != 1)
						{
							poleHodov[k + 1][l] = 2;
							k++;
							if (k == 7) break;
						}
					}
					k = i;
					if (l != 7)
					{
						while (pole[k][l + 1] != 1)
						{
							poleHodov[k][l + 1] = 2;
							l++;
							if (l == 7) break;
						}
					}

					break;
				}
				case 7:
				{
					if (i > 0) poleHodov[i - 1][j] = 2;
					if (j > 0) poleHodov[i][j - 1] = 2;
					if (j < 7) poleHodov[i][j + 1] = 2;
					if (i < 7) poleHodov[i + 1][j] = 2;
					if (i > 0 && j > 0)poleHodov[i - 1][j - 1] = 2;
					if (i < 7 && j < 7) poleHodov[i + 1][j + 1] = 2;
					if (i > 0 && j < 7)poleHodov[i - 1][j + 1] = 2;
					if (i < 7 && j>0)poleHodov[i + 1][j - 1] = 2;
					break;			// король ходит непонятно, поэтому оставим его =)
				}
				}
			}
		}
	}

};
// поле ходов нашего коня, которая хранит все возможных ходы
int poleK[8][8];
// вывод поля
void vivodPoleK()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << poleK[i][j] << setw(3);
		}
		cout << endl;
	}
}
// эти переменные глобальные, для использования в функции ниже
int m2, n2;

// функция заполнения ходов коня
int hodK()
{
	int hod = 0; // переменная, которая отвечает за номер хода
	bool izm = false; // переменная, которая содержит в себе изменения 
	bool m = true; // переменная для цикла
	while (m) {
		izm = false;
		//cout << "Search for hod " << hod << endl;
		//vivodPoleK();
		for (int i = 0; i < 8; i++) {	// проходим по массива и ищем настоящий номер хода(например
										// сначала это будет 0, затем для него ищем ходы 1, затем для	
										// хода 1 ищем ходы 2 и т.д.)
			for (int j = 0; j < 8; j++)
			{
				if (poleK[i][j] == hod) // если нашли нужный номер хода
				{
					//все что описано в этом блоке используется ниже и для дальнейших проверок возможных ходов
					//--------------------------------------------------------------------
			
					if (i > 0 && j > 1) { // проверка выхода за пределы поля для данного хода
						if (poleK[i - 1][j - 2] == -1 && poleHodov[i - 1][j - 2] != 2) // первая проверка - занята ли данная позиция других ходом,
																						// вторая проверка - можно ли ходить в данную позицию(может
																						// быть под боем вражеской фигуры)
						{
							
							poleK[i - 1][j - 2] = hod + 1; // ставим следующий ход
							izm = true;	// изменения произошли
							
							//cout << "izm" << endl;
						}
					}
					//-----------------------------------------------------------------

					// все тоже самое что и для верхнего блока, только проверяется другая позиция
					if (i > 1 && j > 0) {
						if (poleK[i - 2][j - 1] == -1 && poleHodov[i - 2][j - 1] != 2)
						{
							
							poleK[i - 2][j - 1] = hod + 1;
							izm = true;
							//cout << "izm" << endl;
						}
					}
					if (i > 1 && j < 7) {
						if (poleK[i - 2][j + 1] == -1 && poleHodov[i - 2][j + 1] != 2)
						{

							
							poleK[i - 2][j + 1] = hod + 1;
							izm = true;
							//cout << "izm" << endl;
						}
					}
					if (i > 0 && j < 6) {
						if (poleK[i - 1][j + 2] == -1 && poleHodov[i - 1][j + 2] != 2)
						{
							
							poleK[i - 1][j + 2] = hod + 1;
							izm = true;
							//cout << "izm" << endl;
						}
					}
					if (i < 7 && j < 6) {
						if (poleK[i + 1][j + 2] == -1 && poleHodov[i + 1][j + 2] != 2)
						{
							
							poleK[i + 1][j + 2] = hod + 1;
							izm = true;
							//cout << "izm" << endl;
						}
					}
					if (i < 6 && j < 7) {
						if (poleK[i + 2][j + 1] == -1 && poleHodov[i + 2][j + 1] != 2)
						{
							
							poleK[i + 2][j + 1] = hod + 1;
							izm = true;
							//cout << "izm" << endl;
						}
					}
					if (i < 6 && j > 0) {
						if (poleK[i + 2][j - 1] == -1 && poleHodov[i + 2][j - 1] != 2)
						{
							
							poleK[i + 2][j - 1] = hod + 1;
							izm = true;
							//cout << "izm" << endl;
						}
					}
					if (i < 7 && j > 1) {
						if (poleK[i + 1][j - 2] == -1 && poleHodov[i + 1][j - 2] != 2)
						{
							poleK[i + 1][j - 2] = hod + 1;
							izm = true;
						//	cout << "izm" << endl;
						}
					}


				}
			}
		}
		// цикл проверки хода закончился
	
		if (poleK[m2 - 1][n2 - 1] != -1) // если дошли до искомой позиции, возвращаем количество ходов
		{
			return hod + 1;
		}
		if (izm == false) // если не было никаких изменений, то выходим из цикла
		{
			m = false;
		}
		hod++; // прибавляем единицу, для поиска следующих ходов
	}
	return -1;// возвращаем в случае, если некуда ходить, и в искомой позиции нет ходов
}

int main()
{
	setlocale(LC_ALL, "RUS");

	vivodPolya();
	cout << "Введите вашу позицию: \nM: ";
	int m1, n1;
	cin >> m1;
	cout << "N: ";
	cin >> n1;

	if (pole[m1 - 1][n1 - 1] != 0)
	{
		cout << "Позиция занята \n";
		system("pause");
		return 0;
	}
	pole[m1 - 1][n1 - 1] = -1;
	poleK[m1 - 1][n1 - 1] = 0;
	poleHodov[m1 - 1][n1 - 1] = 4;
	cout << "Введите позицию, в которую хотите пройти: \nM: ";
	
	cin >> m2;
	cout << "N: ";
	cin >> n2;
	if (pole[m2 - 1][n2 - 1] != 0)
	{
		cout << "Позиция занята \n";
		system("pause");
		return 0;
	}
	pole[m2 - 1][n2 - 1] = -2;
	// заполняем поле ходов
	updateHodov();
	vivodHodov();
	// поле ходов коня заполняем изначально -1
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			poleK[i][j] = -1;
		}
	}
	// нашу позиицию наполняем нулём
	poleK[m1 - 1][n1 - 1] = 0;
	//poleK[5][4] = 0;

	// вызываем главную функцию
	int z = hodK();
	// ответ:
	if (z > 0)
	{
		cout << "До позиции можно дойти за " << z << " ходов\n";
	}
	else { cout << "До данной позиции нельзя дойти\n"; }
	// для наглядности поле возможных ходов
	cout << endl << setw(3);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << poleK[i][j] << setw(3);
		}
		cout << endl;
	}


	system("pause");
	return 0;
}