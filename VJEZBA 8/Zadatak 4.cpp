#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;

	/*
		Napisati program koji pronalazi najučestaliji element u 1D nizu.
		Hint: Za pronalazenje najucestalijeg elementa, veoma je pozeljno da se isti sortira.
		Za sortiranje mozete implementirati sopstvenu funkiju, a isto tako mozete koristiti gotovu
		funkiju 'sort' unutar biblioteke 'algorithm'.
		Za ovaj primjer, uključite biblioteku 'algorithm' i koristite funkciju 'sort'.
	*/

void unos(int arr[], const int vel) {
	for (int i = 0; i < vel; i++)
	{
		cout << "Unesite element na lokaciji " << i << endl;
		cin >> arr[i];
	}
	cout << endl;
}
void ispis(int arr[], const int vel) {
	cout << "Velicina niza: " << vel << endl;
	for (int i = 0; i < vel; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int getNajucestaliji(int niz[], int vel) {
	int trenutniElement = niz[0];
	int najucestalijiElement = trenutniElement;
	int trenutnaFrekvencija = 1;
	int najucestalijaFrekvencija = 1;
	for (int i = 1; i < vel; i++)
	{
		if (niz[i] == trenutniElement)
		{
			trenutnaFrekvencija++;
		}
		else
		{
			if (trenutnaFrekvencija > najucestalijaFrekvencija)
			{
				najucestalijaFrekvencija = trenutnaFrekvencija;
				najucestalijiElement = trenutniElement;
			}
			trenutniElement = niz[i];
			trenutnaFrekvencija = 1;
		}
	}
	if (trenutnaFrekvencija > najucestalijaFrekvencija)
	{
		najucestalijiElement = trenutniElement;
	}
	return najucestalijiElement;
}

int main() {
	int arr[5];
	unos(arr, size(arr));
	ispis(arr, size(arr));
	cout << "Najucestaliji element je: " << getNajucestaliji(arr, size(arr)) << endl;
	return 0;
}





