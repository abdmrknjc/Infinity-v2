/*Napisati program koji će omogućiti korisniku da unese veličinu jednodimenzionalnog
dinamičkog niza integer vrijednosti. Napisati funkciju koja će taj niz popuniti serijom
Fibonacci brojeva počevši od broja 1. Za pronalazenje elemenata Fibonacci serije obavezno
koristiti rekurzivnu funkciju. Punjenje niza se prekida kada se popuni cijeli niz ili kada se desi overflow na integer varijabli.

(U ovom zadatku je zabranjeno indeksirati niz uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.)*/

#include <iostream>
using namespace std;

void rekurzijaFib(int*, int, int);

void rekurzijaFib(int* niz, int vel, int brojac=0) {
	if (brojac==vel)
	{
		return;
	}
	if (brojac==0||brojac==1)
	{
		*(niz + brojac) = 1;
                rekurzijaFib(niz,vel,brojac+1);
	}
	else if (*(niz + brojac-1)+*(niz+brojac-2) < 0) {
		return;
	}
	else
		*(niz + brojac) = *(niz + brojac - 1) + *(niz + brojac - 2); // jer treba da je taj clan jednak zbiru proslog i pretproslog!!
	
	rekurzijaFib(niz, vel,brojac+1);
}

int main() {
	int vel;
	cout << "Velicina niza: " << endl;
	cin >> vel;
	int* niz = new int[vel];
	rekurzijaFib(niz, vel);
	cout << "ISPIS" << endl;
	for (int i = 0; i < vel; i++)
	{
		cout << *(niz + i)<<endl;
	}
        delete[] niz;
        niz=nullptr;
}
