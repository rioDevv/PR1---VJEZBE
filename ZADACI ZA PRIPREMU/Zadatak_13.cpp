#include<iostream>
#include<time.h>
using namespace std;

bool isPrime(int broj) {
	if (broj <= 1) {
		return false;
	}
	for (int i = 2; i < broj; i++) {
		if (broj % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main() {
	srand(time(0));
	int n, unos;
	do
	{
		cout << "Unesite broj: " << endl;
		cin >> n;
	} while (n < 10 || n>1000);

	int brojacProstih = 0;

	for (int i = 0; i < n; i++)
	{
		unos = rand() % 1000 + 1;
		if (isPrime(unos))
		{
			brojacProstih++;
		}
		cout << unos << " ";
	}
	cout << endl;

	cout << "U ovom uzorku od " << n << " brojeva,prostih ima: " << brojacProstih;
	cout << ",pa je procenat prostih brojeva u ovom slucaju: " << (double(brojacProstih) / n) * 100 << "%" << endl;
}
