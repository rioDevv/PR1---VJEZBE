#include<iostream>
using namespace std;

bool isPrime(int broj, int i) {
	if (broj <= 1)
	{
		return false;
	}
	if (broj == 2 || broj == 3)
	{
		return true;
	}
	if (broj % i == 0)
	{
		return false;
	}
	if (i == broj - 1)
	{
		return true;
	}
	return isPrime(broj, i + 1);
}

int main() {
	int broj;
	do
	{
		cout << "Unesi broj: ";
		cin >> broj;
	} while (broj < 0);

	if (isPrime(broj, 2))
	{
		cout << "Broj je prost." << endl;
	}
	else
	{
		cout << "Broj je slozen." << endl;
	}
}