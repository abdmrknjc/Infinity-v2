#include <iostream>
using namespace std;

int unosN() {
	int n;
	cout << "Unesite cijeli broj n: " << endl;
	cin >> n;
	return n;
}

int faktorijel(int broj) {
	int faktorijelVar = 1;
	for (int i = 1; i <= broj; i++)
	{
		faktorijelVar *= i;
	}
	return faktorijelVar;
}

int sumaFaktorijela(int n) {
	int suma = 0;
	for (int i = 1; i <= n; i+=2)
	{
		suma += faktorijel(i);
	}
	return suma;
}

int main() {
	int n = unosN();
	cout << "Suma faktorijela od 1 do " << n << " je: " << sumaFaktorijela(n) << endl;
}