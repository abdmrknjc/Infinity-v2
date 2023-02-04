#include <iostream>
using namespace std;

int unosN() {
	int n;
	do {
		cout << "Unesite prirodan broj: " << endl;
		cin >> n;
	} while (n<0);
	return n;
}

int brojacCifara(int n) {
	int cifra = 0;
	int brojac = 0;
	while (n>0) {
		cifra = n % 10;
		brojac++;
		n /= 10;
	}
	return brojac;
}

int prvaCifra(int n) {
	while (n>=10)
	{
		n /= 10;
	}
	return n;
}

int zadnjaCifra(int n) {
	int zadnja;
	return zadnja = n % 10;
}

int srednjaCifra(int n) {
	int srednjaCifra = 0;
	int novi;
	int brojac = brojacCifara(n);
	char izuzetak = '-';
	if (brojac%2==0)
	{
		return 0;
	}
	int kolikoOtkinuti = brojac / 2;
	novi = n / pow(10, kolikoOtkinuti);
	srednjaCifra = novi % 10;
	return srednjaCifra;
}

int obrni(int n) {
	int cifra = 0;
	int obrnuti=0;
	while (n>0)
	{
		cifra = n % 10;
		obrnuti = obrnuti * 10 + cifra;
		n /= 10;
	}
	return obrnuti;
}

int main() {
	int n = unosN();
	cout << "Broj ima " << brojacCifara(n) << " cifara. " << endl;
	cout << "Prva cifra broja je: " << prvaCifra(n) << endl;
	cout << "Srednja cifra broja je: " << srednjaCifra(n) << endl;
	cout << "Zadnja cifra broja je: " << zadnjaCifra(n) << endl;
	cout << "Obrnuti broj je: " << obrni(n) << endl;
}