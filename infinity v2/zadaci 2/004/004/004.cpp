#include <iostream>
using namespace std;

bool prost(int br) {
	for (int i = 2; i < br; i++) {
		if (br % i == 0) {
			return false;
		}
	}
	return true;
}

void goldbach(int n1, int n2) {
	if (n1 < 4)
	{
		n1 = 4;
	}
	if (n1%2!=0)
	{
		n1++;
	}
	for (int i = 2; i <= n2; i++)
	{
		for (int j = 2; j <= n2; j++)
		{
			if (prost(i)&&prost(j))
			{
				if (i+j==n1)
				{
					cout << n1 << " = " << i << " + " << j << endl;
					n1 += 2;
				}
			}
			if (n1 > n2)
			{
				return;
			}
		}
	}
}

int main() {
	int n1;
	int n2;
	cout << "Unesite 2 prirodna broja n1 i n2: " << endl;
	cin >> n1;
	cin >> n2;
	int temp = 0;
	if (n1 > n2) {
		temp = n2;
		n2 = n1;
		n1 = temp;
	}
	goldbach(n1, n2);
}