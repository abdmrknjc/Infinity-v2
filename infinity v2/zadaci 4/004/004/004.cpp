#include<iostream>
using namespace std;

struct vremenska_prognoza
{
    char* padavine; //dozvoliti unos rijeci npr. "kisa" ili "snijeg"
    float* temperatura;
    float* vlaznost_vazduha;

    vremenska_prognoza() {
        padavine = new char[10];
        temperatura = new float;
        vlaznost_vazduha = new float;
    }

    ~vremenska_prognoza() {
        delete[] padavine;
        padavine = nullptr;
        delete temperatura;
        temperatura = nullptr;
        delete vlaznost_vazduha;
        vlaznost_vazduha = nullptr;
    }
};

void unos(vremenska_prognoza**, int, int);
void ispis(vremenska_prognoza**, int, int);
void najtacnijiMeteorolog(vremenska_prognoza**, int, int);

void unos(vremenska_prognoza** niz, int red, int kolona) {
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            cin.ignore();
            cout << "Unesite vrstu padavina: " << endl;
            cin.getline((*(niz + i) + j)->padavine, 10);
            cout << "Unesite temperaturu: " << endl;

            cin >> *(*(niz + i) + j)->temperatura;
            cout << "Unesite postotak vlaznosti vazduha: " << endl;
            cin >> *(*(niz + i) + j)->vlaznost_vazduha;
            cout << "_______________________________" << endl;
        }
        cout << endl;
    }
}

void ispis(vremenska_prognoza** niz, int red, int kolona) {
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            cout << "Vrsta padavina: " << (*(niz + i) + j)->padavine << endl;
            cout << "Temperatura: " << *(*(niz + i) + j)->temperatura << endl;
            cout << "Postotak vlaznosti vazduha: " << *(*(niz + i) + j)->vlaznost_vazduha << endl;
            cout << "___________________________________________________" << endl;
        }
        cout << endl;
    }
}

void najtacnijiMeteorolog(vremenska_prognoza** niz, int red, int kolona) {
    vremenska_prognoza* nizStvarnih= new vremenska_prognoza[kolona];
    for (int i = 0; i < kolona; i++)
    {
        cin.ignore();
        cout << "Unesite vrstu padavina: " << endl;
        cin.getline(((nizStvarnih + i))->padavine, 10);
        cout << "Unesite temperaturu: " << endl;

        cin >> *(nizStvarnih + i)->temperatura;
        cout << "Unesite postotak vlaznosti vazduha: " << endl;
        cin >> *(nizStvarnih + i)->vlaznost_vazduha;
        cout << "_______________________________" << endl;
    }
   
    for (int i = 0; i < kolona; i++)
    {
        cout << (nizStvarnih + i)->padavine << endl;
        cout << *(nizStvarnih + i)->temperatura << endl;
        cout << *(nizStvarnih + i)->vlaznost_vazduha << endl;
        cout << "_____________________________________" << endl;
    }
    int sumaStvarnih = 0;
    for (int i = 0; i < kolona; i++)
    {
        sumaStvarnih += *(nizStvarnih + i)->temperatura;
    }
    int indeksMeteorologa = 0;
    int razlikaTemp = INT_MAX; //jer je najveci broj i nema nista vece od njega kako bi pocetna iteracija bila tacna
    for (int i = 0; i < red; i++)
    {
        int sumaMeteorologa = 0;
        for (int j = 0; j < kolona; j++)
        {
            sumaMeteorologa += *(*(niz + i) + j)->temperatura;
        }   
        if (abs(sumaStvarnih - sumaMeteorologa)<razlikaTemp)
        {
            indeksMeteorologa = i;
            razlikaTemp = abs(sumaStvarnih - sumaMeteorologa);
        }
    }
    cout << "Najtacniji meteorolog je meteorolog sa indeksom " << indeksMeteorologa << endl;
    delete[] nizStvarnih;
    nizStvarnih = nullptr;
}

void dealokacija(vremenska_prognoza** niz, int red) {
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
    vremenska_prognoza** niz = new vremenska_prognoza*[red];
    for (int i = 0; i < red; i++)
    {
        *(niz + i) = new vremenska_prognoza[kolona];
    }
    //unos(niz, red, kolona);
    //ispis(niz, red, kolona);
    najtacnijiMeteorolog(niz, red, kolona);
    dealokacija(niz, red);
}
