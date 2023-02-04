#include <iostream>
using namespace std;

int main() {
	float firmaA = 10;
	float firmaB = 7;
	float firmaC = 5;
	int godina = 0;
	double godisnjiA = 1.0205;
	double godisnjiB = 1.0280;
	double godisnjiC = 1.0430;
	while (firmaA>firmaB || firmaA>firmaC)
	{
		firmaA *= godisnjiA;
		firmaB *= godisnjiB;
		firmaC *= godisnjiC;
		godina++;
	}
	if (firmaB>firmaC)
	{
		cout << "Firma B je prva prestigla firmu A, nakon " << godina << " godina , njen prihod iznosi : " << firmaB << endl;
	}
	else
	{
		cout << "Firma C je prva prestigla firmu A, nakon " << godina << " godina. " << endl;
	}
	cout << "Prihod firme A iznosi: " << firmaA << " MIL eura. " << endl;
	cout << "Prihod firme B iznosi: " << firmaB << " MIL eura. " << endl;
	cout << "Prihod firme C iznosi: " << firmaC << " MIL eura. " << endl;
}