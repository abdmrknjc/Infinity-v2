/*Napisati program koji će omogućiti korisniku da unese veličinu
jednodimenzionalnog dinamičkog niza integer vrijednosti.
Napisati rekurzivnu funkciju koja će taj niz popuniti random brojevima u opsegu od 1 do 100.
Za generisanje random brojeva koristiti rand() % 100 + 1.
Punjenje niza se prekida kada se popuni cijeli niz ili kada se tri puta uzastopno dobije isti random broj.
U ovom zadatku je zabranjeno indeksirati elemente niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.

(Obavezno sve riješiti jednom rekurzivnom funcijom.)*/

#include <iostream>
#include <ctime>
using namespace std;

void rekurzijaRandoma(int*, int, int);

void rekurzijaRandoma(int* niz, int vel, int brojac = 0) {
	if (brojac == vel)
		return;
	else {
		*(niz + brojac) = rand() % 100 + 1;
		if (*(niz+brojac)==*(niz+brojac-1)&&*(niz+brojac)==*(niz+brojac-2))
			return;
	}
	rekurzijaRandoma(niz, vel, brojac + 1);
}

int main() {
	int vel;
	srand(time(NULL));
	cout << "Unesite velicinu niza: " << endl;
	cin >> vel;
	int* niz = new int[vel];
	rekurzijaRandoma(niz, vel);
	for (int i = 0; i < vel; i++)
		cout << *(niz + i) << endl;
	delete[] niz;
	niz = nullptr;
}