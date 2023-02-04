#include <iostream>
using namespace std;

int unosCifara() {
	int cifra;
	int broj = 0;
	do
	{
		cout << "Upisi cifru: " << endl;
		cin >> cifra;
		if (cifra >= 0 && cifra <= 9)
		{
			broj = broj * 10 + cifra;
		}
		if (cifra > 9)
		{
			cout << "Cifra nije validna. " << endl;
		}
	} while (cifra > -1);
	return broj;
}

int main() {
	cout << "Broj sastavljen od cifara je: " << unosCifara() << endl;
}