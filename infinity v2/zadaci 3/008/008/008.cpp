/*Napisati program koji učitava prirodan broj n.Program treba ispisati najmanji prirodni broj m, veći ili jednak n,
koji je potencija nekog prirodnog broja, tj. m=k^l, gdje su k i l≥2 prirodni brojevi.
U ovom zadatku je zabranjeno koristiti pow funkciju za računanje potencije.
Potenciju računati koristeći rekurzivnu funkciju kojoj se proslijeđuje k i l i u kojoj je dozvoljena samo operacija množenja.

Za olakšanje rješenja, možete odabrati prototip funkcija po želji.*/

#include <iostream>
using namespace std;

int rekurzija(int n, int k = 2, int l = 2) {
	if (n == k)
		return n;
	if (n>k*l)
		return rekurzija(n, k + 1, l + 1);
}

int main()
{
	int n;
	cout << "Unesite n " << endl;
	cin >> n;
	cout << rekurzija(n);
	return 0;
}