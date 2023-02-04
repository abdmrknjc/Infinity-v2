/*Kreirati dinamički dvodimenzionalni niz čiji su elementi objekti tipa fudbaler
(fudbaler je struktura čija su obilježja data u nastavku). Omogućiti korisniku da unese dimenzije niza.

struct fudbaler
{
    int* godRodjenja;
    int* brojIgraca;
    int* golovi;
};

Redovi dvodimenzionalnog niza predstavljaju različite timove, a kolone predstavljaju igrače u tim timovima.

Omogućiti korisniku unos svih podataka za sve igrače, te napraviti (i testirati u main funkciji)
funkciju koja će pronaći tim sa najvećim prosjekom. Zatim napraviti (i testirati u main funkciji)
funkciju koja će pronaći igrača sa najviše golova u timu sa najlošijim prosjekom golova.
Radi lakšeg testiranja programa obavezno u funkciji unosa podataka omogućiti da se podaci generišu kao sljedeće:

godRodjenja: 1980 + rand() % ((2000 + 1) - 1980) // Generiše brojeve u rangu 1980 - 2000
brojIgraca: rand() % 30 + 1
golovi: rand() % 5

(U ovom zadatku je zabranjeno indexirati elemente niza uglastim zagradama. Obavezno koristiti aritmetiku pokazivača.) */
#include <iostream>
#include <ctime>
using namespace std;

struct fudbaler
{
    int* godRodjenja;
    int* brojIgraca;
    int* golovi;

    fudbaler() {
        godRodjenja = new int;
        brojIgraca = new int;
        golovi = new int;
    }

    ~fudbaler() {
        delete godRodjenja;
        godRodjenja = nullptr;
        delete brojIgraca;
        brojIgraca = nullptr;
        delete golovi;
        golovi = nullptr;
    }
};

void unos(fudbaler**, int, int);
void ispis(fudbaler**, int, int);
void ekipaNajboljegProsjeka(fudbaler**, int, int);
void najigracNajgoreEkipe(fudbaler**, int, int);
void dealokacija(fudbaler**&, int);

void unos(fudbaler** niz, int red, int kolona) {
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            *(*(niz + i) + j)->godRodjenja = 1980 + rand() % ((2000 + 1) - 1980);
            *(*(niz + i) + j)->brojIgraca = rand()%30 + 1;
            *(*(niz + i) + j)->golovi = rand() % 5;
        }
    }
}

void ispis(fudbaler** niz,int red,int kolona){
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            cout << "Godina rodjenja: " << *(*(niz + i) + j)->godRodjenja << endl;
            cout << "Broj igraca: " << *(*(niz + i) + j)->brojIgraca << endl;
            cout << "Broj golova: " << *(*(niz + i) + j)->golovi << endl;
            cout << "_______________________________________" << endl;
        }
        cout << endl;
    }
}

void ekipaNajboljegProsjeka(fudbaler** niz, int red, int kolona) {
    float* najboljaEkipa = new float[red] {};
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            *(najboljaEkipa + i) += *(*(niz + i) + j)->golovi;
        }
        *(najboljaEkipa + i) /= kolona;
    }

    int indeksEkipe = 0;
    for (int i = 0; i < red; i++)
    {
        if (*(najboljaEkipa+i)> *(najboljaEkipa + indeksEkipe))
        {
            indeksEkipe = i;
        }
    }
    cout << "Najbolja ekipa je ekipa sa indeksom " << indeksEkipe << " i ima podatke: " << endl;
    for (int j = 0; j < kolona; j++)
    {
        cout << "Godina rodjenja: " << *(*(niz + indeksEkipe) + j)->godRodjenja << endl;
        cout << "Broj igraca: " << *(*(niz + indeksEkipe) + j)->brojIgraca << endl;
        cout << "Broj golova: " << *(*(niz + indeksEkipe) + j)->golovi << endl;
        cout << "_______________________________________" << endl;
    }
    delete[]najboljaEkipa;
    najboljaEkipa = nullptr;
}

void najigracNajgoreEkipe(fudbaler** niz, int red, int kolona) {
    float* najgoraEkipa = new float[red] {};
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            *(najgoraEkipa + i) += *(*(niz + i) + j)->golovi;
        }
        *(najgoraEkipa + i) /= kolona;
    }
    int indeksEkipe = 0;
    for (int i = 0; i < red; i++)
    {
        if (*(najgoraEkipa + i) > *(najgoraEkipa + indeksEkipe))
        {
            indeksEkipe = i;
        }
    }
    int najigrac = *(*(niz + indeksEkipe)+0)->golovi;
    int indeksj = 0;
    for (int j = 0; j < kolona; j++)
    {
        if (*(*(niz + indeksEkipe) + j)->golovi>najigrac)
        {
            indeksj = j;
        }
    }
    cout << "Najbolji igrac u najgoroj ekipi je rodjen: " << * (*(niz + indeksEkipe) + indeksj)->godRodjenja << endl;
    cout << "Najbolji igrac u najgoroj ekipi je broj: " << *(*(niz + indeksEkipe) + indeksj)->brojIgraca << endl;
    cout << "Najbolji igrac u najgoroj ekipi ima golova: " << *(*(niz + indeksEkipe) + indeksj)->golovi << endl;
    delete[]najgoraEkipa;
    najgoraEkipa = nullptr;
}

void dealokacija(fudbaler**& niz, int red) {
    for (int i = 0; i < red; i++)
    {
        delete[] *(niz + i);
        *(niz + i) = nullptr;
    }
    delete[]niz;
    niz = nullptr;
}

int main() {
    int red, kolona;
    cout << "Unesite broj redova: " << endl;
    cin >> red;
    cout << "unesite broj kolona: " << endl;
    cin >> kolona;
    fudbaler** niz = new fudbaler * [red];
    for (int i = 0; i < red; i++)
    {
        *(niz + i) = new fudbaler[kolona];
    }
    unos(niz, red, kolona);
    ispis(niz, red, kolona);
    ekipaNajboljegProsjeka(niz, red, kolona);
    najigracNajgoreEkipe(niz, red, kolona);
    dealokacija(niz, red);

    cin.get();
    return 0;
}