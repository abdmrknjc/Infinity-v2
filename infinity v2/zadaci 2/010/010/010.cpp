#include <iostream>
using namespace std;

int main() {
	float g = 9.81;
	float v = 1.0;
	float s = 1.0;
	for (int i = 0, t=3; i < 20; i++,t+=3)
	{
		cout << "Situacija u " << t << ". sekundi je: " << endl;
		v = g * t;
		cout << "Brzina je: " << v << " m/s " << endl;
		s = (g / 2) * pow(t, 2);
		cout << "Predjeni put je: " << s << " m " << endl;
		cout << endl;
	}
}