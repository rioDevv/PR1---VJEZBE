#include<iostream>
using namespace std;

int getSrednjaCifra(int broj) {
	while (broj > 99)
	{
		broj /= 10;
	}
	return broj % 10;
}

float getAritmetic(int broj1, int broj2) {
	float suma = 0;
	int brojac = 0;
	for (int i = broj1; i <= broj2; i++)
	{
		suma += getSrednjaCifra(i);
		brojac++;
	}
	return float(suma) / brojac;
}

int main() {
	int m, n;

	do
	{
		cout << "Unesi m: ";
		cin >> m;
		cout << "Unesi n: ";
		cin >> n;
	} while (n < m || m < 100 || n>500);

	cout << "Aritmeticka sredina srednjih cifara iznosi: " << getAritmetic(m, n) << endl;
}
