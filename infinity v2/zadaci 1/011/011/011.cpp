#include <iostream>
using namespace std;

float unosX() {
	float x;
	cout << "Unesite realan broj x: " << endl;
	cin >> x;
	return x;
}

int unosM() {
	int m;
	cout << "Unesite cijeli broj m: " << endl;
	cin >> m;
	return m;
}

float rezultat(float x, int m) {
	char izbor;
	float suma = 0;
	do
	{
		cout << "Izaberi s za sin. c za cos, q za sqrt, p za pow: " << endl;
		cin >> izbor;
	} while (izbor!='s'&& izbor != 'c'&& izbor != 'p'&& izbor != 'q');
	switch (izbor)
	{
	case's': {
		for (int i = 1; i <= m; i++)
		{
			suma += i / (sin(x / i) + x);
		}
		return suma; }
	case'c': {
		for (int i = 1; i <= m; i++)
		{
			suma += i / (cos(x / i) + x);
		}
		return suma; }
	case'q': {
		for (int i = 1; i <= m; i++)
		{
			suma += i / (sqrt(x / i) + x);
		}
		return suma; }
	case'p': {
		for (int i = 1; i <= m; i++)
		{
			suma += i / (pow((x / i),2)+x);
		}
		return suma; }
	break;
	default:
		cout << "Pokreni ponovo " << endl;
		break;
	}
	return suma;
}

int main() {
	float x = unosX();
	int m = unosM();
	cout << rezultat(x, m);
}