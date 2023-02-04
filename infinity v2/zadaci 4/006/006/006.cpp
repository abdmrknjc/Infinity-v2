#include <iostream>
using namespace std;

struct kosarkas
{
    char* ID;
    char* imePrezime;
    int* postignutiKosevi;

    kosarkas() {
        ID = new char[10];
        imePrezime = new char[20];
        postignutiKosevi = new int;
    }

    ~kosarkas() {
        delete[] ID;
        ID = nullptr;
        delete[]imePrezime;
        imePrezime = nullptr;
        delete postignutiKosevi;
        postignutiKosevi = nullptr;
    }
};

void unos(kosarkas**, int, int);
void ispis(kosarkas**, int, int);
void najKlub(kosarkas**, int, int);
void dealokacija(kosarkas**&, int);

void unos(kosarkas** niz, int red, int kolona) {
    cin.ignore();
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            cout << "Unesite ID kosarkasa: " << endl;
            cin.getline((*(niz + i) + j)->ID, 10);
            cout << "Unesite ime i prezime kosarkasa: " << endl;
            cin.getline((*(niz + i) + j)->imePrezime, 20);
            cout << "Unesite broj postignutih koseva: " << endl;
            cin >> *(*(niz + i) + j)->postignutiKosevi;
            cin.ignore();
        }
    }
}

void ispis(kosarkas** niz, int red, int kolona) {
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            cout << "ID: " << (*(niz + i) + j)->ID << endl;
            cout << "Ime i prezime: " << (*(niz + i) + j)->imePrezime << endl;
            cout << "Broj postignutih koseva: " << *(*(niz + i) + j)->postignutiKosevi << endl;
            cout << "__________________________________________" << endl;
        }
        cout << endl;
    }
}

void najKlub(kosarkas** niz, int red, int kolona) {
    int* najUspjesnijiKlub = new int[kolona] {};
    int indeksKluba = 0;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            *(najUspjesnijiKlub+i) += *(*(niz + i) + j)->postignutiKosevi;
        }
    }
    for (int i = 0; i < kolona; i++)
    {
        if (*(najUspjesnijiKlub+i)>*(najUspjesnijiKlub+indeksKluba))
        {
            indeksKluba = i;
        }
    }
    cout << "Najuspjesniji klub je klub sa indeksom " << indeksKluba << endl;
    int najKosarkas = *(*(niz + indeksKluba) + 0)->postignutiKosevi;
    int indeksNajKosarkasa = 0;
    for (int j = 0; j < kolona; j++)
    {
        if (*(*(niz + indeksKluba) + j)->postignutiKosevi > najKosarkas)
        {
            najKosarkas = *(*(niz + indeksKluba) + j)->postignutiKosevi;
            indeksNajKosarkasa = j;
        }
    }
    int najKosarkasfinal=* (*(niz + indeksKluba) + indeksNajKosarkasa)->postignutiKosevi;
    cout << "Najbolji kosarkas najtima je kosarkas sa indeksom " << indeksNajKosarkasa << endl;
    int* najgori = new int[red] {};
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            *(najgori + i) += *(*(niz + i) + j)->postignutiKosevi;
        }
    }
    int najgoriKosarkas = *(najgori + 0);
    for (int i = 0; i < red; i++)
    {
        najgoriKosarkas = *(najgori + i);
    }
    int razlikanajboljeginajgoreg = abs(najKosarkasfinal-najgoriKosarkas);
    cout << "Razlika izmedju najboljeg kosarkasa najkluba i najgoreg kosarkasa lige u kosevima je: " << razlikanajboljeginajgoreg << endl;
    delete[] najUspjesnijiKlub;
    najUspjesnijiKlub = nullptr;
}


void dealokacija(kosarkas**& niz, int red) {
    for (int i = 0; i < red; i++)
    {
        delete[] * (niz + i);
        *(niz + i) = nullptr;
    }
    delete[] niz;
    niz = nullptr;
}

int main() {
    int red, kolona;
    cout << "Unesite broj redova: " << endl; cin >> red;
    cout << "Unesite broj kolona: " << endl; cin >> kolona;
    kosarkas** niz = new kosarkas * [red];
    for (int i = 0; i < red; i++)
    {
        *(niz + i) = new kosarkas[kolona];
    }
    unos(niz, red, kolona);
    ispis(niz, red, kolona);
    najKlub(niz, red, kolona);
    dealokacija(niz, red);
}