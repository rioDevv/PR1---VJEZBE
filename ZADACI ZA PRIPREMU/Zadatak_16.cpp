#include<iostream>
using namespace std;

void popuniNiz(int* niz, int vel, int trenutniBroj = 2) {
	if (vel <= 0)
	{
		return;
	}

	if (trenutniBroj > INT_MAX / 2)
	{
		cout << "Doslo je do overflowa." << endl;
		return;
	}

	*niz = trenutniBroj;

	popuniNiz(niz + 1, vel - 1, trenutniBroj * 2);
}

void ispisiNiz(int niz[], int vel) {
	for (int i = 0; i < vel; i++)
	{
		cout << niz[i] << " ";
	}
}
	
int main() {
	int vel;
	do
	{
		cout << "Unesite velicinu niza: ";
		cin >> vel;
	} while (vel<1);

	int* niz = new int[vel];

	popuniNiz(niz, vel);
	ispisiNiz(niz, vel);
}