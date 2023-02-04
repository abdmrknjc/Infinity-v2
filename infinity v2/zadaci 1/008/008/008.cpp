#include <iostream>
using namespace std;

int obrni(int br) {
	int cifra = 0;
	int novi = 0;
	while (br>0)
	{
		cifra = br % 10;
		novi = novi * 10 + cifra;
		br /= 10;
	}
	return novi;
}

int sumaCifara(int br) {
	int cifra = 0;
	int suma = 0;
	while (br>0)
	{
		cifra = br % 10;
		suma += cifra;
		br /= 10;
	}
	return suma;
}

int main() {
	int x;
	int y;
	do {
		cout << "Unesite granice intervala, od 10 do 5000: " << endl;
		cin >> x;
		cin >> y;
	} while (x<10||x>5000||y<10||y>5000);
	cout << "Brojevi koji ispunjavaju dati uslov: " << endl;
	for (int i = x; i <= y; i++)
	{
		if (obrni(i)%sumaCifara(i)==0)
		{
			cout << i << endl;
		}
	}
}