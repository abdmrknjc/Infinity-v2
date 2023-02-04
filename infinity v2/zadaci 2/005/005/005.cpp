#include <iostream>
using namespace std;

int napraviNovi(int& n) {
	int cifra = 0;
	int novi = 0;
	while (n>0)
	{
		cifra = n % 10;
		if (cifra%2!=0)
		{
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

int main() {
	int n;
	do
	{
		cout << "Unesite n, n>50,n<5000000: " << endl;
		cin >> n;
	} while (n < 50 || n>5000000);
	cout << "Uneseni broj je:" << n << endl;
	cout << "Broj dobiven nakon operacija je: " << napraviNovi(n) << endl;
}