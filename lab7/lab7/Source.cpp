#include <iostream>
#include <ctime>
using namespace std;


int hashTableIndex;// индекс в хеш-таблице
int *hashTable;// хеш-таблица
bool *used; // массив используемых индексов
int sizeEl;// кол-во элементов
int tableSize; // размер таблицы

// хеш-функци€
int func(int value) {
	return (value % tableSize);
}


void vivod()
{
	for (int i = 0; i < tableSize; i++)
	{
		if (used[i])
		{
			cout << "[" << i << "] = " << hashTable[i] << endl;
		}
		else
		{
			cout << "[" << i << "] = " << endl;
		}
	}

}
// ищем место куда вставить и вставл€ем величины в таблицу
bool pushEl(int value) {
	int ind = func(value);
	int i = 1;
	while (used[ind] && hashTable[ind] != value)
	{
		if (hashTable[ind] == value) return false;
		ind = func(value) + i;
		i++;
	}
	if (!used[ind]) {
		used[ind] = true;
		hashTable[ind] = value;
		return true;
	}
	return false;
	//cout << ind << " " << value << endl;
}

// функци€ поиска
int findEl(int value) {
	int ind = func(value);
	int i = 1;
	while (used[ind] && hashTable[ind] != value)
	{
		ind = func(value) + i;
		i++;
	}
	if (used[ind] && hashTable[ind] == value)
	{
		return ind;
	}
	else return -1;
}

int main() {
	setlocale(LC_ALL, "RUS");
	cout << "—делайте выбор: \n" <<
			"1 - заполнить массив самосто€тельно\n"
			"2 - заполнить массив случайными числами\n";
	
	int choise;
	int t1, t2, t3,t4;
	cin >> choise;
	if (choise == 1)
	{
		cout << "¬ведите количество элементов: ";
		cin >> sizeEl;
		cout << "¬ведите размер хеш-таблицы: ";
		cin >> tableSize;
		if (sizeEl > tableSize)
		{
			cout << "Ёлементов больше чем размер хеш-таблицы!\n";
			system("pause");
			return 0;
		}
		hashTable = new int[tableSize];
		used = new bool[tableSize];
		for (int i = 0; i < tableSize; i++) {
			hashTable[i] = 0;
			used[i] = false;
		}
		cout << "¬водите элементы: " << endl;
		int el;
		for (int i = 0; i < sizeEl; i++)
		{
			cin >> el;
			pushEl(el);
		}
	}
	else if (choise == 2)
	{
		cout << "¬ведите количество элементов: ";
		cin >> sizeEl;
		cout << "¬ведите размер хеш-таблицы: ";
		cin >> tableSize;
		if (sizeEl > tableSize)
		{
			cout << "Ёлементов больше чем размер хеш-таблицы!\n";
			system("pause");
			return 0;
		}
		hashTable = new int[tableSize];
		used = new bool[tableSize];
		for (int i = 0; i < tableSize; i++) {
			hashTable[i] = 0;
			used[i] = false;
		}
		cout << "ћассив: \n";
		int m;
		int*temp = new int[sizeEl];
		for (int i = 0; i < sizeEl; i++)
		{
			//if (i == 0) t1 = clock();
			m = rand();
			pushEl(m);
			temp[i] = m;
			//if (i == 100) t2 = clock();
			//if (i == sizeEl - 100) t3 = clock();
			//if (i == sizeEl - 1) t4 = clock();
			cout << m << " ";
		}
		cout << endl;
		/*t1 = clock();
		for (int i = 0; i < sizeEl; i++)
		{
			findEl(temp[i]);
		}
		t2 = clock();
		cout << endl << "time " << t2 - t1 << endl;*/
		//cout << "first 100: " << (double)(t2 - t1) << " , last 100: " << t4 - t3 << " ,  " << t4 - t1 << endl;
	
	}
	else {
		system("pause");
		return 0;
	}

	while (true)
	{
		cout << "—делайте выбор: \n" <<
			"1 - поиск элемента\n"
			"2 - добавить элемент\n"
			"3 - вывод таблицы\n";
		cin >> choise;
		if (choise == 1)
		{
			int ser;
			cout << "¬ведите элемент \n";
			cin >> ser;
			int k = findEl(ser);
			if (k!=-1)
			{
				cout << "“акой элемент существует в таблице\n≈го индекс: " << k << endl;
			}
			else cout << "такого элемента не существует\n";

		}
		else if (choise == 2)
		{
			if (sizeEl >= tableSize)
			{
				cout << "“аблица заполнена!\n";
			}
			else
			{
				int ser;
				cout << "¬ведите элемент \n";
				cin >> ser;
				if (pushEl(ser)) {
					sizeEl++;
					cout << "Ёлемент добавлен!\n";
				}
				else
				{
					cout << "Ёлемент не добавлен!\n";
				}
			}
		}
		else if (choise == 3)
		{
			vivod();
		}
	}

	system("pause");
	return 0;
}
