#include <iostream>
using namespace std;

/*Napisati program koji će omogućiti korisniku da unese veličinu n jednodimenzionalnog
dinamičkog niza integer vrijednosti (n > 2). Napisati rekurzivnu funkciju koja će taj niz
puniti serijom brojeva tako da je svaki sljedeći broj jednak umnošku dva prethodna broja,
a prva dva elementa su 1 i 3 (1, 3, 3, 9, 27, ...).

Zatim napraviti drugu rekurzivnu funkciju koja će izračunati zbir svih elemenata tog niza (voditi računa o tipu podatka zbog veličine broja).

(Obavezno koristiti aritmetiku pokazivača)*/

//void rekurzijaPunjenja(int*, int, int);

long long int zbir;

void rekurzijaPunjenja(int* niz, int n,int brojac=0) {
	if (brojac==n)
		return;
	if (brojac==0)
	{
		*(niz+brojac++) = 1;
		*(niz+brojac++) = 3;
	}
	else {
		*(niz + brojac) = *(niz + brojac - 2) * (*(niz + brojac - 1));
		brojac++;
	}
	rekurzijaPunjenja(niz, n, brojac);
}

long long int rekurzijaZbira(int* niz, int n, int brojac = 0, long long int zbir = 0) {
	if (brojac == n)
		return zbir;
	
	zbir += *(niz+brojac);
		brojac++;
	
	rekurzijaZbira(niz, n,brojac, zbir);
	
}


int main() {
	int n;
	do
	{
		cout << "Unesite n, n>2: " << endl;
		cin >> n;
	} while (n<2);
	int* niz=new int[n];
	rekurzijaPunjenja(niz, n);
	cout << "ISPIS" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(niz+i)<<endl;
	}
	cout << "Zbir je: " << rekurzijaZbira(niz, n);
	delete[]niz;
	niz = nullptr;
}