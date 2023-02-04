/*Napisati program koji će omogućiti korisniku da unese veličinu jednodimenzionalnog
dinamičkog niza integer vrijednosti. Napisati rekurzivnu funkciju koja će taj niz
popuniti serijom brojeva 2, 4, 8, 16, 32, 64, 128, 256, 512, itd.,
tako da je svaki sljedeći broj jednak prethodnom pomnoženom sa 2, počevši od broja 2.
Zatim,korisnik unosi željeni broj te rekurzivnom funkcijom provjerava da li je taj broj član kreiranog niza.
Rekurzija se prekida kada se popuni cijeli niz ili kada se desi overflow na integer varijabli.

(U ovom zadatku je zabranjeno indeksirati niz uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.)*/

#include <iostream>
using namespace std;

void rekurzijaPunjenja(int* niz, int vel,int brojac);

void rekurzijaPunjenja(int* niz, int vel,int brojac=0) {
	if (brojac==0)
	{
		*(niz + brojac) = 2;
	}
	else if (brojac==vel || *(niz + brojac - 1) * 2 < 0)
	{
		return;
	}
	else
	{
		*(niz + brojac) = *(niz + brojac - 1) * 2;
	}
	cout << brojac << endl;
	rekurzijaPunjenja(niz, vel, brojac + 1);
}

int main() {
	int vel;
	cout << "Velicina niza: " << endl;
	cin >> vel;
	int* niz=new int [vel];
	rekurzijaPunjenja(niz, vel);
	cout << "ISPIS" << endl;
	for (int i = 0; i < vel; i++)
	{
		cout << *(niz+i) << " ";
	}

	int *niz;

	delete[] niz;
	niz = nullptr;

}