#include <iostream>
using namespace std;

struct vozilo
{
    char* markaVozila;
    char* brojSasije;
    char* tipVozila; //dozvoliti unos samo vrijednosti "A", "B", ili "C"
    int* kubnihCM;

    vozilo() {
        markaVozila = new char[10];
        brojSasije = new char[20];
        tipVozila = new char;
        kubnihCM = new int;
    }

    ~vozilo() {
        delete[] markaVozila;
        markaVozila = nullptr;
        delete[] brojSasije;
        brojSasije = nullptr;
        delete tipVozila;
        tipVozila = nullptr;
        delete kubnihCM;
        kubnihCM = nullptr;
    }
};

void unos(vozilo**, int, int);
void ispis(vozilo**, int, int);
void firmaNajProsjeka(vozilo**, int, int);
void firmaProsjecneKubikazePoTipovima(vozilo**, int, int);
void dealokacija(vozilo**&, int);

void unos(vozilo** niz, int red, int kolona) {
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            cout << "unesite marku vozila: " << endl;
            cin.getline((*(niz + i) + j)->markaVozila,10);
            cout << "Unesite br sasije: " << endl;
            cin.getline((*(niz + i) + j)->brojSasije,20);
            do {
                cout << "Unesite tip vozila a,b ili c" << endl;
                cin >> *(*(niz + i) + j)->tipVozila;
            } while (*(*(niz + i) + j)->tipVozila!='a'&& *(*(niz + i) + j)->tipVozila!='b'&& *(*(niz + i) + j)->tipVozila!='c');
            cin.ignore();
            cout << "Unesite br kubnih cm" << endl;
            cin >> *(*(niz + i) + j)->kubnihCM;
            cin.ignore();
        }
    }
}

void ispis(vozilo** niz, int red, int kolona) {
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            cout << "marka vozila: " << (*(niz + i) + j)->markaVozila << endl;
            cout << "br sasije: " << (*(niz + i) + j)->brojSasije << endl;
            cout << "tip vozila: " << *(*(niz + i) + j)->tipVozila << endl;
            cout << "kubnih cm: " << *(*(niz + i) + j)->kubnihCM << endl;
            cout << "______________________________________" << endl;
        }
        cout << endl;
    }
}

void firmaNajProsjeka(vozilo** niz, int red, int kolona) {
    int* prosjecnaKub = new int[red] {};
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            *(prosjecnaKub + i) += *(*(niz + i) + j)->kubnihCM;
        }
        *(prosjecnaKub + i) /= kolona;
    }
    int indeksFirme = 0;
    for (int i = 0; i < red; i++)
    {
        if (*(prosjecnaKub + i)> *(prosjecnaKub + indeksFirme))
        {
            indeksFirme = i;
        }
    }
    cout << "Najvecu prosjecnu kubikazu ima firma sa indeksom " << indeksFirme << endl;
    delete[] prosjecnaKub;
    prosjecnaKub = nullptr;
}

void firmaProsjecneKubikazePoTipovima(vozilo** niz, int red, int kolona) {
    int prosjekA = 0;
    int prosjekB = 0;
    int prosjekC = 0;
    int brojacTipaA = 0;
    int brojacTipaB = 0;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++) {
            int kubikaza= *(*(niz + i) + j)->kubnihCM;
            char tipVozila = *(*(niz + i) + j)->tipVozila;
            switch (tipVozila) {
            case'a': prosjekA += kubikaza; brojacTipaA++; break;
            case'b': prosjekB += kubikaza; brojacTipaB++; break;
            }
        }
    }
    if (brojacTipaA>0) {
        cout << "prosjecna kubikaza vozila tipa a je: " << prosjekA / brojacTipaA << endl;
    }
    if (brojacTipaB > 0) {
        cout << "prosjecna kubikaza vozila tipa b je: " << prosjekB / brojacTipaB << endl;
    }
}

void dealokacija(vozilo**& niz, int red) {
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
    cout << "broj redova: " << endl;
    cin >> red;
    cout << "broj kolona: " << endl;
    cin >> kolona;
    cin.ignore();
    vozilo** niz = new vozilo * [red];
    for (int i = 0; i < red; i++)
        *(niz + i) = new vozilo[kolona];
    unos(niz, red, kolona);
    ispis(niz, red, kolona);
    firmaNajProsjeka(niz, red, kolona);
    firmaProsjecneKubikazePoTipovima(niz,red,kolona);
}