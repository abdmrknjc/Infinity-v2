#include <iostream>
using namespace std;

int unosN() {
	int n;
	cout << "Unesite cijeli br n: " << endl;
	cin >> n;
	return n;
}

int faktorijel(int br) {
	int faktorijelVar = 1;
	for (int i = 0; i <= br; i++)
	{
		faktorijelVar *= i;
	}
	return faktorijelVar;
}

float proracun(int br) {
	float suma = 0;
	for (int i = 1; i <= br; i++)
	{
		suma += (pow(-1, i - 1) * (i / (1.0 + faktorijel(i))));
	}
	return suma;
}

int main() {
	int n = unosN();
	cout << proracun(n);
}