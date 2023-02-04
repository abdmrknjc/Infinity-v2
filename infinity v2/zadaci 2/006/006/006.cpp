#include <iostream>
#include <ctime>
using namespace std;

int unosn() {
	int n;
	do
	{
		cout << "Unesite n, n<1000 i n>10: " << endl;
		cin >> n;
	} while (n<10||n>1000);
	return n;
}

int main() {
	int n = unosn();
	srand(time(NULL));
	int brojbacanja = 0;
	float case1 = 0;
	float case2 = 0;
	float case3 = 0;
	float case4 = 0;
	float case5 = 0;
	float case6 = 0;
	while (brojbacanja<n)
	{
		int kocka = rand() % 6 + 1;
		switch (kocka)
		{
		case 1: {case1++; } break;
		case 2: {case2++; } break;
		case 3: {case3++; } break;
		case 4: {case4++; } break;
		case 5: {case5++; } break;
		case 6: {case6++; } break;
		default:
			cout << "Kocka nije dobro bacena! " << endl;
			break;
		}
		brojbacanja++;
		cout << kocka << " " << endl;
	}
	cout << "Procenat bacanja s rezultatom 1: " << case1 * 100/n << " % " << endl;
	cout << "Procenat bacanja s rezultatom 2: " << case2 * 100 / n << " % " << endl;
	cout << "Procenat bacanja s rezultatom 3: " << case3 * 100 / n << " % " << endl;
	cout << "Procenat bacanja s rezultatom 4: " << case4 * 100 / n << " % " << endl;
	cout << "Procenat bacanja s rezultatom 5: " << case5 * 100 / n << " % " << endl;
	cout << "Procenat bacanja s rezultatom 6: " << case6 * 100 / n << " % " << endl;
}