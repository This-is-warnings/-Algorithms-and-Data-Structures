#include<Windows.h>
#include<iostream>
#include <iomanip>
using namespace std;
// ���� �������� ����
int pole[8][8] =   // 0 - �����, 1 - ����, 2 - �����, 3 -����
// 4 - ����, 5 - �����, 6 - �����, 7 - ������, -1 - �����
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
// ������� ������ ���� �� �����
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
				cout << "�"; if (j != 7) cout << setw(3);
				break;
			}
			// 0 - �����, 1 - ����, 2 - �����, 3 -����
// 4 - ����, 5 - �����, 6 - �����, 7 - ������, -1 - �����
			case 2:
			{
				cout << "�"; if (j != 7) cout << setw(3);
				break;
			}
			case 3:
			{
				cout << "�"; if (j != 7) cout << setw(3);
				break;
			}
			case 4:
			{
				cout << "�"; if (j != 7) cout << setw(3);
				break;
			}
			case 5:
			{
				cout << "�"; if (j != 7) cout << setw(3);
				break;
			}
			case 6:
			{
				cout << "�"; if (j != 7) cout << setw(3);
				break;
			}
			case 7:
			{
				cout << "�"; if (j != 7) cout << setw(3);
				break;
			}
			case -1:
			{
				cout << "�"; if (j != 7) cout << setw(3);
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
// ���� ��� ����������� �����
int poleHodov[8][8];
//����� ����� �� �����
void vivodHodov()
{
	cout << setw(3);
	for (int i = 0; i < 8; i++)   // 2 - ������ ������, 1 -  �����, 3 - ����� �����, 4 - �����
	{
		for (int j = 0; j < 8; j++)
		{
			if (poleHodov[i][j] == 2) cout << "X" << setw(3);
			if (poleHodov[i][j] == 1) cout << "O" << setw(3);
			if (poleHodov[i][j] == 3)cout << "H" << setw(3);
			if (poleHodov[i][j] == 4)cout << "�" << setw(3);
		}
		cout << endl;
	}
}
// ��������� ���� ���� ��� �����, ��� ������ ������ ��������
void updateHodov()
{
	for (int i = 0; i < 8; i++)   // 2 - ������ ������, 1 -  �����, 3 - ����� �����, -2 - ����
	{
		for (int j = 0; j < 8; j++)
		{
			if (pole[i][j] == -2) poleHodov[i][j] = 1;
			if (pole[i][j] == 0) poleHodov[i][j] = 1;
			if (pole[i][j] == 1) poleHodov[i][j] = 2;
			if (pole[i][j] >= 2) poleHodov[i][j] = 3;

		}
	}
	for (int i = 0; i < 8; i++)   // 2 - ������ ������, 1 -  �����, 3 - ����� �����
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
					break;			// ������ ����� ���������, ������� ������� ��� =)
				}
				}
			}
		}
	}

};
// ���� ����� ������ ����, ������� ������ ��� ��������� ����
int poleK[8][8];
// ����� ����
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
// ��� ���������� ����������, ��� ������������� � ������� ����
int m2, n2;

// ������� ���������� ����� ����
int hodK()
{
	int hod = 0; // ����������, ������� �������� �� ����� ����
	bool izm = false; // ����������, ������� �������� � ���� ��������� 
	bool m = true; // ���������� ��� �����
	while (m) {
		izm = false;
		//cout << "Search for hod " << hod << endl;
		//vivodPoleK();
		for (int i = 0; i < 8; i++) {	// �������� �� ������� � ���� ��������� ����� ����(��������
										// ������� ��� ����� 0, ����� ��� ���� ���� ���� 1, ����� ���	
										// ���� 1 ���� ���� 2 � �.�.)
			for (int j = 0; j < 8; j++)
			{
				if (poleK[i][j] == hod) // ���� ����� ������ ����� ����
				{
					//��� ��� ������� � ���� ����� ������������ ���� � ��� ���������� �������� ��������� �����
					//--------------------------------------------------------------------
			
					if (i > 0 && j > 1) { // �������� ������ �� ������� ���� ��� ������� ����
						if (poleK[i - 1][j - 2] == -1 && poleHodov[i - 1][j - 2] != 2) // ������ �������� - ������ �� ������ ������� ������ �����,
																						// ������ �������� - ����� �� ������ � ������ �������(�����
																						// ���� ��� ���� ��������� ������)
						{
							
							poleK[i - 1][j - 2] = hod + 1; // ������ ��������� ���
							izm = true;	// ��������� ���������
							
							//cout << "izm" << endl;
						}
					}
					//-----------------------------------------------------------------

					// ��� ���� ����� ��� � ��� �������� �����, ������ ����������� ������ �������
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
		// ���� �������� ���� ����������
	
		if (poleK[m2 - 1][n2 - 1] != -1) // ���� ����� �� ������� �������, ���������� ���������� �����
		{
			return hod + 1;
		}
		if (izm == false) // ���� �� ���� ������� ���������, �� ������� �� �����
		{
			m = false;
		}
		hod++; // ���������� �������, ��� ������ ��������� �����
	}
	return -1;// ���������� � ������, ���� ������ ������, � � ������� ������� ��� �����
}

int main()
{
	setlocale(LC_ALL, "RUS");

	vivodPolya();
	cout << "������� ���� �������: \nM: ";
	int m1, n1;
	cin >> m1;
	cout << "N: ";
	cin >> n1;

	if (pole[m1 - 1][n1 - 1] != 0)
	{
		cout << "������� ������ \n";
		system("pause");
		return 0;
	}
	pole[m1 - 1][n1 - 1] = -1;
	poleK[m1 - 1][n1 - 1] = 0;
	poleHodov[m1 - 1][n1 - 1] = 4;
	cout << "������� �������, � ������� ������ ������: \nM: ";
	
	cin >> m2;
	cout << "N: ";
	cin >> n2;
	if (pole[m2 - 1][n2 - 1] != 0)
	{
		cout << "������� ������ \n";
		system("pause");
		return 0;
	}
	pole[m2 - 1][n2 - 1] = -2;
	// ��������� ���� �����
	updateHodov();
	vivodHodov();
	// ���� ����� ���� ��������� ���������� -1
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			poleK[i][j] = -1;
		}
	}
	// ���� �������� ��������� ����
	poleK[m1 - 1][n1 - 1] = 0;
	//poleK[5][4] = 0;

	// �������� ������� �������
	int z = hodK();
	// �����:
	if (z > 0)
	{
		cout << "�� ������� ����� ����� �� " << z << " �����\n";
	}
	else { cout << "�� ������ ������� ������ �����\n"; }
	// ��� ����������� ���� ��������� �����
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