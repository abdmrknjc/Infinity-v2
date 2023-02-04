#include <iostream>
#include <ctime>
using namespace std;

int unosn() {
	int n;
	do
	{
		cout << "Unesite n, n>10 i n<1000: " << endl;
		cin >> n;
	} while (n<10||n>1000);
	return n;
}

bool isSavrsen(int br) {
	int sumaSvihDjelioca = 0;
		for (int i = 1; i < br; i++)
		{
			if (br%i==0)
			{
				sumaSvihDjelioca += i;
			}
		}
	if (sumaSvihDjelioca == br)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main() {
	srand(time(NULL));
	int n = unosn();
	int brojacSavrsenih = 0;
	for (int i = 1; i <= n; i++)
	{
		int slucajniUnos = rand() % 1000 + 1;
		if (isSavrsen(slucajniUnos))
		{
			brojacSavrsenih++;
		}
		cout << "Slucajni unos: " << slucajniUnos << endl;
	}
	cout << "Od " << n << " unesenih brojeva, " << brojacSavrsenih * 100.0 / n << " % su savrseni brojevi." << endl;
}