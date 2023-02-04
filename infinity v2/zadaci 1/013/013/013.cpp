#include <iostream>
using namespace std;

float unosx() {
	float x;
	cout << "Unesi realan br x: " << endl;
	cin >> x;
	return x;
}

int unosm() {
	int m;
	do
	{
		cout << "Unesite cijeli broj m > 0: " << endl;
		cin >> m;
	} while (m<0);
	return m;
}

float proracun(float x, int m) {
	char izbor;
	float ProracunSiO = 0;
	float ProracunMiD = 1;
	do {
		cout << "s za sabiranje, o za oduzimanje, m za mnozenje, d za dijeljenje: " << endl;
		cin >> izbor;
	} while (izbor !='s'&& izbor != 'o'&& izbor != 'm'&& izbor != 'd');
	switch (izbor)
	{
	case's': {
		for (int i = 1; i <= m; i++)
		{
			ProracunSiO += ((x - i) * i);
		}
		return ProracunSiO; }
	case'o': {
		for (int i = 1; i <= m; i++)
		{
			ProracunSiO -= ((x - i) * i);
		}
		return ProracunSiO;
	}
	case'm': {
		for (int i = 1; i <= m; i++)
		{
			ProracunMiD *= ((x - i) * i);
		}
		return ProracunMiD;
	}
	case'd': {
		for (int i = 1; i <= m; i++)
		{
			ProracunMiD /= ((x - i) * i);
		}
		return ProracunMiD;
	}
	default:
		cout << "Pokreni ponovo! " << endl;
		break;
	}
}

int main() {
	float x = unosx();
	int m = unosm();
	cout << proracun(x, m);
}