#include<iostream>
using namespace std;

bool sveCifreIste(int broj) {
	int cifra4 = broj % 10;
	broj /= 10;
	int cifra3 = broj % 10;
	broj /= 10;
	int cifra2 = broj % 10;
	broj /= 10;
	int cifra1 = broj % 10;

	if (cifra1 == cifra2 || cifra1 == cifra3 || cifra1 == cifra4 || cifra2 == cifra3 || cifra2 == cifra4 || cifra3 == cifra4)
	{
		return false;
	}
	return true;
}

int sortirajSilazno(int broj, int niz[], int vel) {
	for (int i = 0; i < vel; i++)
	{
		niz[i] = broj % 10;
		broj /= 10;
	}	

	int sortirano = 0;

	for (int i = 0; i < vel; i++)
	{
		for (int j = i + 1; j < vel; j++)
		{
			if (niz[i] < niz[j])
			{
				int temp = niz[i];
				niz[i] = niz[j];
				niz[j] = temp;
			}
		}
		sortirano = sortirano * 10 + niz[i];
	}
	return sortirano;
}

int sortirajUzlazno(int broj, int niz[], int vel) {
	for (int i = 0; i < vel; i++)
	{
		niz[i] = broj % 10;
		broj /= 10;
	}

	int sortirano = 0;

	for (int i = 0; i < vel; i++)
	{
		for (int j = i + 1; j < vel; j++)
		{
			if (niz[i] > niz[j])
			{
				int temp = niz[i];
				niz[i] = niz[j];
				niz[j] = temp;
			}
		}
		sortirano = sortirano * 10 + niz[i];
	}
	return sortirano;
}

int main() {
	int broj;
	const int vel = 4;
	int niz[vel];
	
	do
	{
		cout << "Unesite broj: ";
		cin >> broj;
	} while (broj < 1000 || broj > 9999 || !sveCifreIste(broj));
	
	int prethodnaRazlika;
	int silazno = sortirajSilazno(broj, niz, vel);
	int uzlazno = sortirajUzlazno(broj, niz, vel);
	int razlika = silazno - uzlazno;
	int brojIteracija = 0;

	do
	{
		cout << silazno << " - " << uzlazno << " = " << razlika << endl;
		prethodnaRazlika = razlika;
		silazno = sortirajSilazno(razlika, niz, vel);
		uzlazno = sortirajUzlazno(razlika, niz, vel);
		razlika = silazno - uzlazno;
		brojIteracija++;
	} while (razlika != prethodnaRazlika);

	cout << "Kaprekar konstanta se dobila u " << brojIteracija << " iteracija." << endl;
}
