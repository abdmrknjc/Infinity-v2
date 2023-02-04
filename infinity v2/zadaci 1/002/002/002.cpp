#include <iostream>
#include <iomanip>
using namespace std;

int unosN() {
	int n;
	cout << "Unesite cijeli broj n: " << endl;
	cin >> n;
	return n;
}

float gSredina(int n) {
	float sredina = 1.0f;
	int brojac = 0;
	for (int i = 1; i <= n; i+=2)
	{
		if (i%5!=0)
		{
			sredina *= i;
			brojac++;
		}
	}
	return pow(sredina,1.0/brojac);
}

int main() {
	int n = unosN();
	cout << "G.sredina svih neparnih brojeva koji nisu djeljivi sa 5; od 1 do " << n << " je : " << setprecision(3) << gSredina(n) << endl;
}