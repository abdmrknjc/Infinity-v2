#include <iostream>
#include <ctime>
using namespace std;

int bacanje() {
	int brojbacanja = 0;
	int brojistih = 0;
	do
	{
		int kocka1 = rand() % 6 + 1;
		int kocka2 = rand() % 6 + 1;
		int kocka3 = rand() % 6 + 1;
		if (kocka1==kocka2==kocka3)
		{
			brojistih++;
		}
		else
		{
			brojistih = 0;
		}
		brojbacanja++;
	} while (brojistih<2);
	return brojbacanja;
}

int main() {
	srand(time(NULL));
	cout << "Tri ista broja su se dobila nakon " << bacanje() << " istih bacanja. " << endl;
}