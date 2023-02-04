#include <iostream>
#include <ctime>
using namespace std;

struct figura
{
    int ID;
    char* nazivFigure;
    float* visinaFigure;

    figura() {
        ID = 0;
        nazivFigure = new char[11];
        visinaFigure = new float;
    }

    ~figura() {
        delete[] nazivFigure;
        nazivFigure = nullptr;
        delete visinaFigure;
        visinaFigure = nullptr;
    }
};

void unos(figura**, int, int);
void ispis(figura**, int, int);
float* prosjecnaVisina(figura**, int, int);

void unos(figura** niz, int red, int kolona) {
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j ++)
        {
            /*cout << "Unesite ID figure: " << endl;
            cin >> (*(niz + i) + j)->ID;
            cout << "Unesite naziv figure: " << endl;
            cin.ignore();
            cin.getline((*(niz + i) + j)->nazivFigure, 11);
            cout << "Unesite visinu figure: " << endl;*/
            *(*(niz + i) + j)->visinaFigure=rand()%9+1;
            
        }
    }
}

void ispis(figura** niz, int red, int kolona) {
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            //cout << "ID figure: " << (*(niz + i) + j)->ID << endl;
            //cout << "Naziv figure: " << ((*(niz + i) + j)->nazivFigure) << endl;
            cout /*<< "Visina figure: "*/ << *(*(niz + i) + j)->visinaFigure<<" ";
            //cout << "________________________________________" << endl;
        }
        cout << endl;
    }
}

float* prosjecnaVisina(figura** niz, int red, int kolona) {
    int zbiriij = 0;
    float prosjek = 0.0;
    float brojacCrnih = 0.0;
    float* a;
    for (int i = 0; i < red; i++)
    {
        for (int j = 0; j < kolona; j++)
        {
            if ((i+j)%2==0)
            {
                if (i + j > 7)
                {
                    zbiriij += *(*(niz + i) + j)->visinaFigure;
                    brojacCrnih++;
                }
            }
            
        }
    }
    prosjek = zbiriij / brojacCrnih;
    a = &prosjek;
    return a;
}

//URADITI ALOKACIJU

int main() {
    srand(time(0));
    int red, kolona;
    cout << "unesite br redova: " << endl; cin >> red;
    cout << "unesite br kolona: " << endl; cin >> kolona;
    figura** niz = new figura * [red];
    for (int i = 0; i < red; i++) {
        *(niz+i) = new figura [kolona];
    }
    unos(niz, red, kolona);
    ispis(niz, red, kolona);
    cout << *prosjecnaVisina(niz, red, kolona);
}