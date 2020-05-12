#include <iostream>
#include <Windows.h>

using namespace std;

bool Work1(int n)
{
	if (n < 2) return false;                  // размерность = 1
	for (int i = 2; i <= sqrt(n); i++) {      // арифмит. операций = 2*sqrt(n)
		if (n % i == 0)                       // трудоемкость = sqrt(n)*2+1
			return false;
	}
	return true;
}
bool Work2(int n) {

	int c = 0;
	if (n > 2) {                               // размерность =1
		for (int i = 2; i <= n; i++) {         // ариф опер = 2*(n-1)+1
			if (n%i == 0) {                    // трудоемкость = 2*(n-1) + 2
				c++;
			}
		}
		if (c == 1) {
			return true;
		}
		else { return false; }
	}
	else return false;


	/* (n < 2) {
		return false;
	} 
	else if (n == 2) {
		return true;
	} 
	else if (n % i == 0) {
		return false;
	} 
	else if (i < n / 2) {
		return Work2(n, i + 1);
	}
	else {
		return true;
	}*/
}

int main()
{
	cout << "Choose the way\n1-Way 1\n2-Way 2" << endl;
	int k;
	cin >> k;
	int n;
	cout << "Cin n" << endl;
	cin >> n;
	if (k == 1) {
		if (Work1(n)) cout << n << " is prime" << endl;
		else cout << n << " is not prime" << endl;
	}
	if (k == 2) {
		if (Work2(n)) cout << n << " is prime" << endl;
		else cout << n << " is not prime" << endl;
	}
	system("pause");
}