/*Kreirati jednodimenzionalni dinamicki niz n velicine i napuniti ga serijom kubova svakog proslog broja pocevsi od 2.
Prekida se kada se desi overflow, napuni niz.Ispisati niz rekurzivno!

Koristiti aritmetiku pointera!*/

#include <iostream>
using namespace std;

void rekurzijaKubova(int*, int, int);
void rekurzijaIspisa(int*, int, int);

void rekurzijaKubova(int* niz, int vel, int brojac = 0) {
	if (brojac == vel)
		return;
	if (brojac == 0)
		*(niz + brojac) = pow(2, 3);
	else if (brojac<vel)
	{
		int temp = pow(*(niz + brojac - 1), 3);
		if (temp < 0)
		{
			return;
		}
		else
			*(niz + brojac) = temp;
	}
		
	rekurzijaKubova(niz, vel,brojac+1);
}

void rekurzijaIspisa(int* niz, int vel, int brojac = 0) {
	if (brojac==vel)
		return;
	cout << *(niz + brojac) << endl;
	rekurzijaIspisa(niz, vel, brojac + 1);
}

int main() {
	int vel;
	cout << "Unesite velicinu niza: " << endl;
	cin >> vel;
	int* niz = new int[vel];
	rekurzijaKubova(niz, vel);
	rekurzijaIspisa(niz, vel);
	delete[] niz;
	niz = nullptr;
}