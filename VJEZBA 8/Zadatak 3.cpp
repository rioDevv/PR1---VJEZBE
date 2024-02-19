#include<iostream>
#include<iomanip>
using namespace std;

	/*
		Napisati program koji provjerava da li je 1D niz palindrom.
		[Main funkcija] Kreirati dva niza od kojih ce jedan biti dimenzija 5 a drugi 6.
		Testirati funkciju za provjeru palindroma na oba niza.
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

bool jelPalindrom(int niz[], int vel) {
	for (int i = 0; i < vel / 2; i++)
	{
		if (niz[i] != niz[vel - i - 1])
		{
			return false;
		}
	}
	return true;
}


int main() {
	int niz1[5];
	int niz2[6];

	unos(niz1,size(niz1));
	ispis(niz1, size(niz1));

	unos(niz2, size(niz2));
	ispis(niz2, size(niz2));

	if (jelPalindrom(niz1, size(niz1)))
	{
		cout << "Prvi niz je palindrom." << endl;
	}
	else
	{
		cout<<"Prvi niz nije palindrom."<<endl;
	}

	if (jelPalindrom(niz2, size(niz2)))
	{
		cout << "Drugi niz je palindrom." << endl;
	}
	else
	{
		cout << "Drugi niz nije palindrom." << endl;
	}
}


