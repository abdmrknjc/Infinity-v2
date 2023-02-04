#include <iostream>
using namespace std;

int unosA() {
	int a;
	do
	{
		cout << "Unesite br a, a>100000: " << endl;
		cin >> a;
	} while (a<100000);
	return a;
}

int napraviB(int a) {
	int cifra = 0;
	int b = 0;
	while (a>0)
	{
		cifra = a % 10;
		if (cifra%2==0)
		{
			a /= 10;
		}
		else
		{
			b = b * 10 + cifra;
			a /= 10;
		}
	}
	return b;
}

int main() {
	int a = unosA();
	cout << "Uneseni broj je: " << a << endl;
	cout << "Broj nakon operacije je: " << napraviB(a) << endl;
	cout << "Razlika brojeva je: " << a - napraviB(a) << endl;
}