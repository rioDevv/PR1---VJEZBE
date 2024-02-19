#include<iostream>
#include<iomanip>
using namespace std;

	/*
		Napisati program koji provjerava da li je 1D niz rastući.
		Velicina niza je 5.
	*/

void unos(int niz[], int vel) {
	for (int i = 0; i < vel; i++)
	{
		cout << "Unesi element na indexu " << i << " : ";
		cin >> niz[i];
	}
	cout << endl;
}

void ispis(int niz[], int vel) {
	for (int i = 0; i < vel; i++)
	{
		cout << niz[i] << endl;
	}
}

bool jeRastuci(int niz[], int vel) {
	for (int i = 0; i < vel - 1; i++)
	{
		if (niz[i] > niz[i + 1])
		{
			return false;
		}
	}
	return true;
}

int main() {
	const int vel = 5;
	int niz[vel];

	unos(niz, vel);
	ispis(niz, vel);

	if (jeRastuci(niz,vel))
	{
		cout << "Niz je rastuci." << endl;
	}
	else
	{
		cout << "Niz nije rastuci." << endl;
	}
}

