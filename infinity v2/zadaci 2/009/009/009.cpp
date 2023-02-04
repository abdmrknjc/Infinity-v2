#include <iostream>
using namespace std;

float unosx() {
	float x;
	cout << "Unesite realan broj x: " << endl;
	cin >> x;
	return x;
}

int unosm() {
	int m;
	cout << "Unesite cijeli broj m: " << endl;
	cin >> m;
	return m;
}

int main() {
	float x = unosx();
	int m = unosm();
	char izbor;
	float rezultat = 0;
	do
	{
		cout << "Unesite s za sin, c za cos, q za sqrt, p za pow: " << endl;
		cin >> izbor;
	} while (izbor != 's'&& izbor != 'c'&& izbor != 'q'&& izbor != 'p');
	switch (izbor)
	{
	case 's': {
		for (int i = 1; i <= m; i++)
		{
			rezultat += sin(x) + i;
		}
	}
	case 'c': {
		for (int i = 1; i <= m; i++)
		{
			rezultat += cos(x) + i;
		}
	}
	case 'q': {
		for (int i = 1; i <= m; i++)
		{
			rezultat += sqrt(x) + i;
		}
	}
	case 'p': {
		for (int i = 1; i <= m; i++)
		{
			rezultat += pow((x) + i,3);
		}
	}
	default: {
		cout << "Pokrenite program ponovo! " << endl;
		break; }
	}
	cout << "Rezultat je: " << rezultat << endl;
}