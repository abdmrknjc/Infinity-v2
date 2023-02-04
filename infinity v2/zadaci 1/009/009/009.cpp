#include <iostream>
using namespace std;

int unosN() {
	int n;
	do
	{
		cout << "Unesite prirodan broj n: " << endl;
		cin >> n;
	} while (n < 0);
	return n;
}

double suma(int n) {
	double suma = 0;
	for (int i = 1; i <= n; i++)
	{
		suma += 1 / pow((2 * i + 1), 2);
	}
	return suma;
}

int main() {
	int n = unosN();
	cout << "Suma je: " << suma(n);
}