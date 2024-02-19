#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;

	/*
		Napisati program koji provjerava da li je uneseni niz (velicine 5) - aritmeticki niz.
		 Primjeri aritmetickih nizova:
		 1,2,3,4,5, ...
		 1,3,5,7,9, ...
		 10,20,30,40,50,...
		 11,22,33,44,55,...
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
		cout << niz[i] << " ";
	}
	cout << endl;
}

bool isAritmetic(int niz[], int vel) {
	int razlika = niz[1] - niz[0];
	for (int i = 2; i < vel; i++)
	{
		if (niz[i] - niz[i - 1] != razlika)
		{
			return false;
		}
	}
	return true;
}

int main() {
	int niz[5];

	unos(niz, size(niz));
	ispis(niz, size(niz));

	if (isAritmetic(niz,size(niz)))
	{
		cout << "Niz je aritmeticki." << endl;
	}
	else
	{
		cout << "Niz nije aritmeticki." << endl;
	}
}