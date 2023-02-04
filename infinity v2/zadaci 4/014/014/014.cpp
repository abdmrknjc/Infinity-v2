#include <iostream>
using namespace std;

struct student
{
    char* ID;
    char* imePrezime;
    float* prosjek;

    student() {
        ID = new char[15];
        imePrezime = new char[26];
        prosjek = new float;
    }
    void unos() {
        cin.ignore();
        cout << "Unesite ID studenta: " << endl;
        cin.getline(ID, 15);
        cout << "Unesite ime i prezime studenta: " << endl;
        cin.getline(imePrezime, 26);
        cout << "Unesite prosjek studenta: " << endl;
        cin >> *prosjek;
    }

    void dealokacija() {
        delete ID;
        ID = nullptr;
        delete imePrezime;
        imePrezime = nullptr;
        delete prosjek;
        prosjek = nullptr;
    }

};

void unos(student**, int, int);
void ispis(student**, int, int);
void najFaks(student**, int, int);
void zlatniStudent(student**, int, int);
void dealokacija(student**&, int,int);

void unos(student** niz, int red, int kolona) {
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            (*(niz + i) + j)->unos();
        }
    }
}

void ispis(student** niz, int red, int kolona) {
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            cout << "ID: " << (*(niz+i)+j)->ID, 15;
            cout << endl;
            cout << "Ime i prezime studenta: " << (*(niz + i) + j)->imePrezime, 26;
            cout << endl;
            cout << "Prosjek studenta: " << *(*(niz + i) + j)->prosjek << endl;
            cout << "___________________________________________" << endl;
            cout << endl;
        }
    }
}

void najFaks(student** niz, int red, int kolona) {
    float* najFaksVar = new float[red] {};
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            *(najFaksVar + i) += *(*(niz + i) + j)->prosjek;
        }
        *(najFaksVar + i) /= kolona;
    }
    int indeksNajFaksa = 0;
    for (int i = 0; i < red; i++)
    {
        if (*(najFaksVar+i)>*(najFaksVar+indeksNajFaksa))
        {
            indeksNajFaksa = i;
        }
    }
    cout << "Najbolji fakultet je fakultet sa indeksom: " << indeksNajFaksa << endl;

    delete[]najFaksVar;
    najFaksVar = nullptr;
}

void zlatniStudent(student** niz, int red, int kolona) {
    int IDreda = 0; int IDkolone = 0;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            if ((*(*(niz + IDreda) + IDkolone)->prosjek) > (*(*(niz + i) + j)->prosjek))
            {
                IDreda = i;
                IDkolone = j;
            }
        }
    }

    cout << "Najbolji student je student sa IDom: " << ((*(niz + IDreda) + IDkolone))->ID << endl;
}

void dealokacija(student**& niz, int red,int kolona) {
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            (*(niz + i) + j)->dealokacija();
        }
    }
    for (int i = 0; i < red; i++)
    {
        delete[] *(niz + i);
        *(niz + i) = nullptr;
    }
    delete[] niz;
    niz = nullptr;
}


int main() {
    int red, kolona;
    cout << "Unesite br redova: " << endl; cin >> red;
    cout << "Unesite br kolona: " << endl; cin >> kolona;
    student** niz = new student * [red];
    for (int i = 0; i < red; i++)
    {
        *(niz + i) = new student[kolona];
    }
    unos(niz, red, kolona);
    ispis(niz, red, kolona);
    najFaks(niz, red, kolona);
    zlatniStudent(niz, red, kolona);
    dealokacija(niz, red,kolona);
}


