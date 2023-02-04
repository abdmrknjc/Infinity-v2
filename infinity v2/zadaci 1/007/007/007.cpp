#include <iostream>
using namespace std;

int faktorijel(int br) {
	int faktorijelVar = 1;
	if (br == 0)
	{
		faktorijelVar = 1;
	}
	for (int i = 1; i <= br; i++)
	{
		faktorijelVar *= i;
	}
	return faktorijelVar;
}

int sumaFaktorijelaZnamenki(int br) {
	int sumaF = 0;
	int cifra = 0;
	while (br > 0)
	{
		cifra = br % 10;
		sumaF += faktorijel(cifra);
		br /= 10;
	}
	return sumaF;
}

int main() {
	for (int i = 100; i <= 999; i++)
	{
		if (i == sumaFaktorijelaZnamenki(i))
		{
			cout << i;
		}
	}
}