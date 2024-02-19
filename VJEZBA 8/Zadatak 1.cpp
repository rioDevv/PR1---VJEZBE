#include<iostream>
#include<iomanip>
using namespace std;

	/*
		Napisati program u kojem je potrebno unijeti 5 elemenata niza. Zatim, korisnik treba da
		unese jednu vrijednost nakon cega ce se ispisati vrijednost niza koja je najslicnija unesenoj
		vrijednosti.
		Napomena: Mozete koristiti funkcije 'unos' i 'ispis'.
	*/

void unos(int niz[], int vel) {
	for (int i = 0; i < vel; i++)
	{
		cout << "Unesite element na indexu " << i << " : ";
		cin >> niz[i];
		cout << endl;
	}
}

void ispis(int niz[], int vel) {
	for (int i = 0; i < vel; i++)
	{
		cout << "Element na indexu " << i << " : " << niz[i] << endl;
	cout << endl;
	}
}

int trazeniBroj(int niz[], int vel, int trazeni) {
	int najslicnija = niz[0];
	int najmanjaRazlika = abs(niz[0] - trazeni);
	for (int i = 0; i < vel; i++)
	{
		int razlika = abs(niz[i] - trazeni);
		if (razlika < najmanjaRazlika)
		{
			najslicnija = niz[i];
			najmanjaRazlika = razlika;
		}
	}
	return najslicnija;
}

int main() {
	const int vel = 5;
	int niz[vel];
	int trazeni;

	unos(niz, vel);
	ispis(niz, vel);

	do
	{
		cout << "Unesite trazeni broj: ";
		cin >> trazeni;
	} while (trazeni<0);
	cout << endl;

	cout << "Najblizi broj je: " << trazeniBroj(niz, vel, trazeni);
}