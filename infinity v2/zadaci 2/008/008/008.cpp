#include <iostream>
using namespace std;

int faktorijel(int& br) {
	unsigned long long int faktorijelVar = 1;
	for (int i = 1; i <= br; i++)
	{
		faktorijelVar *= i;
	}
	return faktorijelVar;
}


int sumaFaktorijelaFibonacci(int treci) {
	unsigned long long int sumaFaktorijelaFibonacciVar = 0;
	for (int i = 1; i <= treci; i++)
	{
		sumaFaktorijelaFibonacciVar += faktorijel(i);
	}
	return sumaFaktorijelaFibonacciVar;
}

bool prost(int br) {
	if (br<=1)
	{
		return false;
	}
	for (int i = 2; i < br; i++)
	{
		if (br%i==0)
		{
			return false;
		}
	}
	return true;
}

int main() {
	unsigned long long int prvi = 2;
	unsigned long long int drugi = 3;
	unsigned long long int treci = 0;
	int brojacFibonacci = 0;
	for (long long int i = 2; i < 100; i++)
	{
		treci = prvi + drugi;
		prvi = drugi;
		drugi = treci;
		brojacFibonacci++; if (prost(treci))
		{
			sumaFaktorijelaFibonacci(treci);
		}
	}
	unsigned long long int rezultat = sumaFaktorijelaFibonacci(treci);
	cout << "Rezultat je: " << rezultat << endl;
}