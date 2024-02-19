#include<iostream>
using namespace std;

bool sveCifreIste(int broj) {
	int temp4 = broj % 10;
	broj /= 10;
	int temp3 = broj % 10;
	broj /= 10;
	int temp2 = broj % 10;
	broj /= 10;
	int temp1 = broj % 10;

	if (temp4 == temp3 || temp4 == temp2 || temp4 == temp1 || temp3 == temp2 || temp3 == temp1 || temp2 == temp1) {
		return false;
	}
	return true;
}

int sortirajUzlazno(int broj, int niz[], int size) {
	for (int i = 0; i < size; i++)
	{
		niz[i] = broj % 10;
		broj /= 10;
	}

	int sortirano = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (niz[i] > niz[j])
			{
				int c = niz[i];
				niz[i] = niz[j];
				niz[j] = c;
			}
		}
		sortirano = sortirano * 10 + niz[i];
	}
	return sortirano;
}

int sortirajSilazno(int broj, int niz[], int size) {
	for (int i = 0; i < size; i++)
	{
		niz[i] = broj % 10;
		broj /= 10;
	}

	int sortirano = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (niz[i] < niz[j])
			{
				int c = niz[i];
				niz[i] = niz[j];
				niz[j] = c;
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
	int prethodnaRazlika;

	do
	{
		cout << "Unesite broj: " << endl;
		cin >> broj;
	} while (!sveCifreIste(broj));

	int manji = sortirajUzlazno(broj, niz, vel);
	int veci = sortirajSilazno(broj, niz, vel);
	int razlika = veci - manji;
	int brojacIteracija = 0;

	do
	{
		cout << veci << " - " << manji << " = " << razlika << endl;
		prethodnaRazlika = razlika;
		broj = razlika;
		veci = sortirajSilazno(broj, niz, vel);
		manji = sortirajUzlazno(broj, niz, vel);
		razlika = veci - manji;
		brojacIteracija++;
	} while (razlika != prethodnaRazlika);
	cout << "Kaprekar konstanta se dobila u " << brojacIteracija << " iteracija." << endl;
}