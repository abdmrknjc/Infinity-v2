/*Poštujući sve faze programiranja, napisati program koji korisniku omogućava unos
realnog broja x i odabir funkcije za proračun datog izraza.
Korisnik bira funkciju unosom jednog od sljedećih karaktera : 's'(sin), 'c'(cos).
U slučaju da korisnik unese karakter koji ne odgovara niti jednog od predefinisanih vrijednosti ispisati odgovarajuću poruku i ponoviti odabir.*/

#include <iostream>
using namespace std;

float unosx() {
	float x;
	cout << "unesite realan broj x: " << endl;
	cin >> x;
	return x;
}

char izbor() {
	char slovo;
	do
	{
		cout << "Unesite s za sin, c za cos: " << endl;
		cin >> slovo;
	} while (slovo!='s' && slovo!='c');
	return slovo;
}

int main() {
	float x = unosx();
	char slovo = izbor();
	float suma = 0.0f;
	if (slovo=='s')
	{
		for (int i = 1; i <= x; i++) {
			suma += i / (sin(x / i) + x);
		}
	}
	if (slovo=='c')
	{
		for (int i = 1; i <= x; i++)
		{
			suma += i / (cos(x / i) + x);
		}
	}
	cout << "Proracun je: " << suma+1 << endl;
}

