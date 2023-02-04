#include <iostream>
using namespace std;


struct vozilo
{
    char* markaVozila;
    char* nazivVozila;
    char* tipVozila; // omogućiti unos samo 'A', 'B','C'
    float* potrosnja_goriva_po_km;

    vozilo() {
        markaVozila = new char[10];
        nazivVozila = new char[10];
        tipVozila = new char;
        potrosnja_goriva_po_km = new float;
    }
    void unos() {
        cout << "Unesite marku vozila: " << endl;
        cin.getline(markaVozila, 10);
        cout << "Unesite naziv vozila" << endl;
        cin.getline(nazivVozila, 10);
        cout << "Unesite tip vozila";
        cin >> *tipVozila;
        cout << "Unesite potrosnju goriva: " << endl;
        cin.ignore();
        cin >> *potrosnja_goriva_po_km;
        cin.ignore();
    }
    void ispis() {
        cout << "Marka vozila: " << markaVozila << endl;
        cout << "Naziv vozila: " << nazivVozila << endl;
        cout << "Tip vozila: " << *tipVozila << endl;
        cout << "Potrosnja: " << *potrosnja_goriva_po_km << endl;
        cout << "-----------------------" << endl;
    }
    ~vozilo() {
        delete[] markaVozila;
        markaVozila = nullptr;
        delete[] nazivVozila;
        nazivVozila = nullptr;
        delete tipVozila;
        tipVozila = nullptr;
        delete potrosnja_goriva_po_km;
        potrosnja_goriva_po_km = nullptr;
    }
};

void unosNiza(vozilo**&, int, int);
void ispisNiza(vozilo**&, int, int);



void unosNiza(vozilo**& niz, int redovi, int kolone) {
    for (int i = 0; i < redovi; i++)
    {
        for (int j = 0; j < kolone; j++)
        {
            (*(niz + i) + j)->unos();
        }
    }
}
void ispisNiza(vozilo**& niz, int redovi, int kolone) {
    for (int i = 0; i < redovi; i++)
    {
        for (int j = 0; j < kolone; j++)
        {
            (*(niz + i) + j)->ispis();
        }
    }
}
int najvecaPotrosnja(vozilo**& niz, int redovi, int kolone) {
    int indexFirme = 0;
    int prosjek = 0;
    for (int i = 0; i < redovi; i++)
    {
        int tempProsjek = 0;
        for (int j = 0; j < kolone; j++)
        {
            tempProsjek += *(*(niz + i) + j)->potrosnja_goriva_po_km;
        }
        tempProsjek /= kolone;
        if (tempProsjek > prosjek) {
            indexFirme = i;
            prosjek = tempProsjek/kolone;
        }
    }

    return indexFirme;
}
float prosjekCAutomobila(vozilo**&niz, int redovi, int kolone) {
    float prosjek = 0;
    int brojac = 0;

    for (int i = 0; i < redovi; i++)
    {
        
        for (int j = 0; j < kolone; j++)
        {
            if (*(*(niz + i) + j)->tipVozila == 'c') {
                prosjek += *(*(niz + i) + j)->potrosnja_goriva_po_km;
                brojac++;
           }
        }
    }
    return prosjek / brojac;
}

int main() {
    int redovi, kolone;
    cout << "Unesite red: "; cin >> redovi;
    cout << "Unesite kolone: "; cin >> kolone;
    cin.ignore();

    vozilo** niz = new vozilo * [redovi];
    for (int i = 0; i < redovi; i++)
    {
        *(niz + i) = new vozilo[kolone];
    }
    unosNiza(niz,redovi,kolone);
    ispisNiza(niz,redovi,kolone);
    cout << najvecaPotrosnja(niz, redovi, kolone) << endl;
    cout << prosjekCAutomobila(niz, redovi, kolone);

    //dealokacija(niz,redovi);
}