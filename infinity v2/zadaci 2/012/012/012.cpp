#include <iostream>
using namespace std;
int unosM() {
	int m;
	do
	{
		cout << "Unesite m, m>100,m<500: " << endl;
		cin >> m;
	} while (m<100||m>500);
	return m;
}

int unosN() {
	int n;
	do
	{
		cout << "Unesite n,n>100,n<500: " << endl;
		cin >> n;
	} while (n < 100 || n>500);
	return n;
}

float aritmetickaSredina(int cifra,int brojac) {
	float sredina = 0;
	for (int i = 0; i <= cifra; i++)
	{
		sredina += cifra/brojac;
	}
	return sredina;
}

int srednjaCifra(int br) {
	//12345
	int pomocna = br;
	int brojacCifara = 0;
	int srednjaCifraVar = 0;
	while (pomocna > 0)
	{
		pomocna /= 10;
		brojacCifara++;
	}
	int kolikoOtkinuti = brojacCifara / 2;
	int novi = br / pow(10,kolikoOtkinuti);
	srednjaCifraVar = novi % 10;
	return srednjaCifraVar;
}

int main() {
	int m = unosM();
	int n = unosN();
	int brojac = 0;
	int najvecaSrednja = 0;
	if (m>n)
	{
		int temp = n;
		n = m;
		m = temp;
	}
	for (int i = m; i <= n; i++)
	{
		int srednja=srednjaCifra(i);
		brojac++;
		float aSredina = aritmetickaSredina(srednja, brojac);
		if (srednja>najvecaSrednja)
		{
			najvecaSrednja = srednja;
		}
	}
	cout << "Aritmeticka sredina svih srednjih cifara brojeva u rangu od " << m << " do " << n << " je: " << aritmetickaSredina(srednja,brojac) << endl;
	cout << "Najveca srednja cifra navedenog ranga je: " << najvecaSrednja << endl;
}