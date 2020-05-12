#include<Windows.h>
#include<iostream>
#include <iomanip>
using namespace std;



int pole[8][8] =   // 0 - пусто, 1 - свои, 2 - пешка, 3 -конь
// 4 - слон, 5 - ладья, 6 - ферзь, 7 - король, -1 - игрок
{
	{0,0,0,0,7,5,0,0},
	{6,0,0,4,0,2,0,0},
	{0,0,2,2,0,0,0,0},
	{0,1,0,1,0,1,0,0},
	{0,0,1,0,0,0,0,0},
	{0,0,0,1,0,1,0,0},
	{0,0,1,1,1,1,0,1},
	{1,1,1,1,1,1,1,1}
};

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

int poleHodov[8][8];
int hodKon[8][8];
void vivodHodov()
{
	cout << setw(3);
	for (int i = 0; i < 8; i++)   // 2 - нельзя ходить, 1 -  можно, 3 - можно сбить
	{
		for (int j = 0; j < 8; j++)
		{
			if (poleHodov[i][j] == 2) cout << "X" << setw(3);
			if (poleHodov[i][j] == 1) cout << "O" << setw(3);
			if(poleHodov[i][j] == 3)cout << "H" << setw(3);
			if (poleHodov[i][j] == 4)cout << "И" << setw(3);
		}
		cout << endl;
	}
}
void updateHodov()
{
	for (int i = 0; i < 8; i++)   // 2 - нельзя ходить, 1 -  можно, 3 - можно сбить
	{
		for (int j = 0; j < 8; j++)
		{
			if (pole[i][j] == 0) poleHodov[i][j] = 1;
			if (pole[i][j] == 1) poleHodov[i][j] = 2;
			if (pole[i][j] >= 2) poleHodov[i][j] = 3;
			
		}
	}
	for (int i = 0; i < 8; i++)   // 2 - нельзя ходить, 1 -  можно, 3 - можно сбить
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
					if (i > 0 && j > 1) poleHodov[i - 1][j - 2]=2;
					if (i > 1 && j > 0) poleHodov[i - 2][j - 1]=2;
					if (i > 1 && j < 7) poleHodov[i - 2][j + 1]=2;
					if (i > 0 && j < 6) poleHodov[i - 1][j + 2]=2;
					if (i < 7 && j < 6) poleHodov[i + 1][j + 2]=2;
					if (i < 6 && j < 7) poleHodov[i + 2][j + 1]=2;
					if (i < 6 && j > 0) poleHodov[i + 2][j - 1]=2;
					if (i < 7 && j >1) poleHodov[i + 1][j - 2]=2;
					break;
				}
				case 4:
				{
					int k = i, l = j;
					if (k > 0 && l > 0)
					{
						while (pole[k - 1][l - 1] == 0)
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
						while (pole[k + 1][l - 1] == 0)
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
						while (pole[k - 1][l + 1] == 0)
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
						while (pole[k + 1][l + 1] == 0)
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
						while (pole[k - 1][l] == 0)
						{
							poleHodov[k - 1][l] = 2;
							k--;
							if (k == 0) break;
						}
					}
					k = i;
					if (l != 0)
					{
						while (pole[k][l-1] == 0)
						{
							poleHodov[k][l-1] = 2;
							l--;
							if (l == 0) break;
						}
					}
					l = j;
					if (k != 7)
					{
						while (pole[k + 1][l] == 0)
						{
							poleHodov[k + 1][l] = 2;
							k++;
							if (k == 7) break;
						}
					}
					k = i;
					if (l != 7)
					{
						while (pole[k][l + 1] == 0)
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
						while (pole[k - 1][l - 1] == 0)
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
						while (pole[k + 1][l - 1] == 0)
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
						while (pole[k - 1][l + 1] == 0)
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
						while (pole[k + 1][l + 1] == 0)
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
						while (pole[k - 1][l] == 0)
						{
							poleHodov[k - 1][l] = 2;
							k--;
							if (k == 0) break;
						}
					}
					k = i;
					if (l != 0)
					{
						while (pole[k][l - 1] == 0)
						{
							poleHodov[k][l - 1] = 2;
							l--;
							if (l == 0) break;
						}
					}
					l = j;
					if (k != 7)
					{
						while (pole[k + 1][l] == 0)
						{
							poleHodov[k + 1][l] = 2;
							k++;
							if (k == 7) break;
						}
					}
					k = i;
					if (l != 7)
					{
						while (pole[k][l + 1] == 0)
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
					break;
				}
				}
			}
		}
	}
	
};



void zapHodKon(int hod)
{
	bool izm = false;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (hodKon[i][j] == hod) {
				if (i > 0 && j > 1) {
					if (hodKon[i - 1][j - 2] == -1 && poleHodov[i - 1][j - 2]!=2)
					{
						/*if (poleHodov[i - 1][j - 2] == 3)
						{
							pole[i - 1][i - 2] = 0;
							cout << "udp nach hod (" << hod << ") ---";
							updateHodov();
							cout << "udp kon hod (" << hod << ") ---" << endl;
						}*/
						hodKon[i - 1][j - 2] = hod+1;
						izm = true;
					}
				}
				if (i > 1 && j > 0) {
					if (hodKon[i - 2][j - 1] == -1 && poleHodov[i - 2][j - 1]!=2)
					{
						/*if (poleHodov[i - 2][j - 1] == 3)
						{
							pole[i - 2][i - 1] = 0;
							cout << "udp nach hod (" << hod << ") ---";
							updateHodov();
							cout << "udp kon hod (" << hod << ") ---" << endl;
						}*/
						hodKon[i - 2][j - 1] = hod+1;
						izm = true;						
					}
				}
				if (i > 1 && j < 7) {
					if (hodKon[i - 2][j + 1] == -1 && poleHodov[i - 2][j + 1]!=2)
					{

					/*	if (poleHodov[i - 2][j +1] == 3)
						{
							pole[i - 2][i +1] = 0;
							cout << "udp nach hod (" << hod << ") ---";
							updateHodov();
							cout << "udp kon hod (" << hod << ") ---" << endl;
						}*/
						hodKon[i - 2][j + 1] = hod+1;
						izm = true;					
					}
				}
				if (i > 0 && j < 6) {
					if (hodKon[i - 1][j + 2] == -1 && poleHodov[i - 1][j + 2]!=2)
					{
					/*	if (poleHodov[i - 1][j + 2] == 3)
						{
							pole[i - 1][i + 2] = 0;
							cout << "udp nach hod (" << hod << ") ---";
							updateHodov();
							cout << "udp kon hod (" << hod << ") ---" << endl;
						}*/
						hodKon[i - 1][j + 2] = hod+1;
						izm = true;						
					}
				}
				if (i < 7 && j < 6) {
					if (hodKon[i + 1][j + 2] == -1 && poleHodov[i + 1][j + 2]!=2)
					{
						/*if (poleHodov[i + 1][j + 2] == 3)
						{
							pole[i + 1][i + 2] = 0;
							cout << "udp nach hod (" << hod << ") ---";
							updateHodov();
							cout << "udp kon hod (" << hod << ") ---" << endl;
						}*/
						hodKon[i + 1][j + 2] = hod+1;
						izm = true;						
					}
				}
				if (i < 6 && j < 7) {
					if (hodKon[i + 2][j + 1] == -1 && poleHodov[i + 2][j + 1]!=2)
					{
						/*if (poleHodov[i +2][j +1] == 3)
						{
							pole[i + 2][i +1] = 0;
							cout << "udp nach hod (" << hod << ") ---";
							updateHodov();
							cout << "udp kon hod (" << hod << ") ---" << endl;
						}*/
						hodKon[i + 2][j + 1] = hod +1;
						izm = true;			
					}
				}
				if (i < 6 && j > 0) {
					if (hodKon[i + 2][j - 1] == -1 && poleHodov[i + 2][j - 1]!=2)
					{
						/*if (poleHodov[i +2][j - 1] == 3)
						{
							pole[i +2][i - 1] = 0;
							cout << "udp nach hod (" << hod << ") ---";
							updateHodov();
							cout << "udp kon hod (" << hod << ") ---" << endl;
						}*/
						hodKon[i + 2][j - 1] = hod+1;
						izm = true;	
					}
				}
				if (i < 7 && j > 1) {
					if (hodKon[i + 1][j - 2] == -1 && poleHodov[i + 1][j - 2]!=2)
					{
					/*	if (poleHodov[i + 1][j - 2] == 3)
						{
							pole[i + 1][i - 2] = 0;
							cout << "udp nach hod (" << hod << ") ---";
							updateHodov();
							cout << "udp kon hod (" << hod << ") ---" << endl;
						}*/
						hodKon[i + 1][j - 2] = hod+1;
						izm = true;
					}
				}
			}
		}
	}
	if (izm == true)
	{
		zapHodKon(hod + 1);
	}
}
int main()
{
	setlocale(0, "rus");
	vivodPolya();
	updateHodov();
	cout << "Введите вашу позицию: \nM: ";
	int m1, n1;
	cin >> m1;
	cout << "N: ";
	cin >> n1;
	
	if (pole[m1-1][n1-1] != 0)
	{
		cout << "Позиция занята \n";
		system("pause");
		return 0;
	}
	pole[m1-1][n1-1] = -1;
	poleHodov[m1 - 1][n1 - 1] = 4;
	cout << "Введите позицию, в которую хотите пройти: \nM: ";
	int m2, n2;
	cin >> m2;
	cout << "N: ";
	cin >> n2;
	if (pole[m2-1][n2-1] != 0)
	{
		cout << "Позиция занята \n";
		system("pause");
		return 0;
	}
	pole[m2-1][n2-1] = -2;
	vivodPolya();
	updateHodov();
	cout << endl << endl;
	vivodHodov();
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			hodKon[i][j] = -1;
		}
	}
	hodKon[m1-1][n1-1] = 0;
	
	/*for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (hodKon[i][j] == -1) {
				if (i > 0 && j > 1) {
					if (hodKon[i - 1][j - 2] == 0)
					{
						hodKon[i - 1][j - 2] =1;
						
					}
				}
				if (i > 1 && j > 0) {
					if (hodKon[i - 2][j - 1] == 0)
					{
						hodKon[i - 2][j - 1] = 1;
					}
				}
				if (i > 1 && j < 7) {
					if (hodKon[i - 2][j + 1] == 0)
					{
						hodKon[i - 2][j + 1] =1;
						
					}
				}
				if (i > 0 && j < 6) {
					if (hodKon[i - 1][j + 2] == 0)
					{
						hodKon[i - 1][j + 2] = 1;
						
					}
				}
				if (i < 7 && j < 6) {
					if (hodKon[i + 1][j + 2] == 0)
					{
						hodKon[i + 1][j + 2] = 1;
					
					}
				}
				if (i < 6 && j < 7) {
					if (hodKon[i + 2][j + 1] == 0)
					{
						hodKon[i + 2][j + 1] =1;
				
					}
				}
				if (i < 6 && j > 0) {
					if (hodKon[i + 2][j - 1] == 0)
					{
						hodKon[i + 2][j - 1] =1;
						
					}
				}
				if (i < 7 && j > 1) {
					if (hodKon[i + 1][j - 2] == 0)
					{
						hodKon[i + 1][j - 2] = 1;
					
					}
				}
			}
		}
	}*/



	zapHodKon(0);

	cout << endl << setw(3);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << hodKon[i][j] << setw(3);
		}
		cout << endl;
	}
	system("pause");
	return 0;
}