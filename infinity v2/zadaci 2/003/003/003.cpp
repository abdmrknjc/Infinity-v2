#include <iostream>
using namespace std;

int obrniNovi(int);

int unosn() {
	int n;
	do
	{
		cout << "unesite pozitivan broj n: " << endl;
		cin >> n;
	} while (n<1);
	return n;
}

int napraviNovi(int n) {
	int cifra = 0;
	int novi = 0;
	while (n>0)
	{
		cifra = n % 10;
		if (cifra%2==0)
		{
			cifra = 5;
			novi = novi * 10 + cifra;
			n /= 10;
		}
		else
		{
			novi = novi * 10 + cifra;
			n /= 10;
		}
	}
	return novi;
}

int obrniNovi(int novi) {
	int obrnuti = 0;
	int cifra = 0;
	while (novi>0)
	{
		cifra = novi % 10;
		obrnuti = obrnuti * 10 + cifra;
		novi /= 10;
	}
	return obrnuti;
}

int main() {
	int n = unosn();
	int novi = napraviNovi(n);
	cout << "Uneseni broj je: " << n << endl;
	cout << "Broj dobiven nakon operacija je: " << obrniNovi(novi) << endl;
	cout << "Razlika brojeva je: " << n - obrniNovi(novi) << endl;
}