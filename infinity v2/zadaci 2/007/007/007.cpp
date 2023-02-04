#include <iostream>
#include <ctime>
using namespace std;

int unosn() {
	int n;
	do
	{
		cout << "Unesite n, n>10 i n<1000: " << endl;
		cin >> n;
	} while (n<10||n>1000);
	return n;
}

bool prost(int br) {
	if (br<=1)
		return false;
for (int i = 2; i < br; i++)
	if (br%i==0)
		return false;
return true;
}

int main() {
	srand(time(NULL));
	int brojacProstih = 0;
	int brojacUnosa = 0;
	int n = unosn();
	while (brojacUnosa<n)
	{
		int slucajniUnos = rand() % 1000 + 1;
		if (prost(slucajniUnos))
		{
			brojacProstih++;
		}
		brojacUnosa++;
	}
	float procenat = brojacProstih * 100 / brojacUnosa;
	cout << "Od " << brojacUnosa << " brojeva " << brojacProstih << " su prosti brojevi. " << endl;
	cout << "Procenat prostih brojeva je: " << procenat << " % " << endl;
}