#include <iostream>
using namespace std;

int unosN() {
	int n;
	do
	{
		cout << "Unesite prirodan broj n: " << endl;
		cin >> n;
	} while (n<1);
	return n;
}

float unosX() {
	float x;
	cout << "Unesite realan broj x: " << endl;
	cin >> x;
	return x;
}

float suma(int n, float x) {
	float sumaVar = 0;
	for (int i = 1; i <= n; i++)
	{
		sumaVar += cos(pow(x, i));
	}
	return sumaVar;
}

int main() {
	int n = unosN();
	float x = unosX();
	cout << "Suma je: " << suma(n, x);
}

