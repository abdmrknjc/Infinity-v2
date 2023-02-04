#include <iostream>
using namespace std;

struct uposlenik
{
    char* ID;
    char* imePrezime;
    float* plata;

    uposlenik() {
        ID = new char[5];
        imePrezime = new char[25];
        plata = new float;
    }

    ~uposlenik() {
        delete ID;
        ID = nullptr;
        delete imePrezime;
        imePrezime = nullptr;
        delete plata;
        plata = nullptr;
    }
};

void unos(uposlenik**, int, int);
void ispis(uposlenik**, int, int);
void najveciProsjek(uposlenik**, int, int);
void dealokacija(uposlenik**&, int);

void unos(uposlenik** niz, int red, int kolona) {
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            /*cin.ignore();
            cout << "Unesite ID radnika: " << endl;
            cin.getline((*(niz + i) + j)->ID, 5);
            cout << "Unesite ime i prezime radnika: " << endl;
            cin.getline((*(niz + i) + j)->imePrezime, 25);
            cout << "Unesite platu radnika: " << endl;
            cin >> *(*(niz + i) + j)->plata;*/
            *(*(niz + i) + j)->plata = rand() % 4000 + 1000;
        }
    }
}

void ispis(uposlenik** niz, int red, int kolona) {
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            //cout << "ID: " << (*(niz + i) + j)->ID << endl;
            //cout << "Ime i prezime: " << (*(niz + i) + j)->imePrezime << endl;
            cout << "Plata: " << *(*(niz + i) + j)->plata << endl;
            cout << "_________________________________________________" << endl;
            cout << endl;
        }
    }
}

void najveciProsjek(uposlenik** niz, int red, int kolona) {
    float* prosjekOdjela = new float[red] {};
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            *(prosjekOdjela + i) += *(*(niz + i) + j)->plata;
        }
        *(prosjekOdjela+i) /= kolona;
    }
    int indeksNajOdjela = 0;
    for (int i = 0; i < red; i++)
    {
        if (*(prosjekOdjela+i)>*(prosjekOdjela+indeksNajOdjela))
        {
            indeksNajOdjela = i;
        }
    }
    cout << "Najbolji odjel je odjel s prosjekom " << indeksNajOdjela << " i njegov prosjek je: " << *(prosjekOdjela+indeksNajOdjela) << endl;
    delete[] prosjekOdjela;
    prosjekOdjela = nullptr;
}

void dealokacija(uposlenik**& niz, int red) {
    for (int i = 0; i < red; i++) {
        delete[] * (niz + i);
        *(niz + i) = nullptr;
    }
    delete[]niz;
    niz = nullptr;
}


int main() {
    int red, kolona;
    cout << "unesite broj redova: " << endl;
    cin >> red;
    cout << "unesite broj kolona: " << endl;
    cin >> kolona;
    uposlenik** niz = new uposlenik * [red];
    for (int i = 0; i < red; i++)
    {
        *(niz + i) = new uposlenik[kolona];
    }
    unos(niz, red, kolona);
    ispis(niz, red, kolona);
    najveciProsjek(niz, red, kolona);
    dealokacija(niz, red);
}