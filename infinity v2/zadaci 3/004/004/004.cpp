/*Napisati program koji će omogućiti korisniku da unese veličinu
jednodimenzionalnog dinamičkog niza integer vrijednosti.
Napisati rekurzivnu funkciju koja će taj niz popuniti faktorijelom
rednog broja člana niza (1!, 2!, 3!, 4!...). Rekurzija se prekida kada se
popuni cijeli niz ili kada se desi overflow na integer varijabli.
U ovom zadatku je zabranjeno indeksirati elemente niza uglastim zagradama.

(Obavezno koristiti aritmetiku pokazivača. Obavezno sve riješiti jednom rekurzivnom funkcijom.)*/

#include <iostream>
using namespace std;

void rekurzijaFaktorijel(int*, int, int, int);

void rekurzijaFaktorijel(int* niz, int vel, int brojac = 1,int proizvod=1) {
	if (brojac>vel)
		return;
	if (proizvod<0) {
		return;
	}
	else
	{
		*(niz + brojac - 1) = proizvod;
	}
	rekurzijaFaktorijel(niz, vel,brojac+1,proizvod*(brojac+1)); //mnozenje trenutnog proizvoda s brojacem+1(brojac predstavlja 
																//clanove faktorijela) da bi se dobio faktorijel 
}

int main() {
	int vel;
	cout << "VELICINA NIZA: " << endl;
	cin >> vel;
	int* niz = new int[vel];
	rekurzijaFaktorijel(niz, vel);
	cout << "ISPIS" << endl;
	for (int i = 0; i < vel; i++) {
		cout << *(niz + i) << endl;
	}

	delete[] niz;
	niz = nullptr;
}