#include<iostream>
using namespace std;

const int MAX_VEL = 50;

void unos(int niz[],int i, int vel) {
	if (i == vel)
	{
		return;
	}
	cin >> niz[i];
	unos(niz, i + 1, vel);
}

void ispis(int niz[], int i, int vel) {
	if (i == vel)
	{
		return;
	}
	cout << niz[i];
	ispis(niz, i + 1, vel);
}

int sumaElemenata(int niz[], int i, int vel) {
	if (i == vel)
	{
		return 0;
	}
	return niz[i] + sumaElemenata(niz, i + 1, vel);
}

int sumaPozitivnih(int niz[], int i, int vel) {
	if (i == vel)
	{
		return 0;
	}
	return ((niz[i] > 0) ? niz[i] : 0) + sumaPozitivnih(niz, i + 1, vel);
}

int sumaSaParnimIndexom(int niz[], int i, int vel) {
	if (i == vel)
	{
		return 0;
	}
	return ((i % 2 == 0) ? niz[i] : 0) + sumaSaParnimIndexom(niz, i + 1, vel);
}

int main() {
	int vel;

	do
	{
		cout << "Unesite velicinu niza: ";
		cin >> vel;
	} while (vel < 1);

	int niz[MAX_VEL];

	unos(niz, 0, vel);
	ispis(niz, 0, vel);
	cout << endl;

	cout << "Suma elemenata iznosi: " << sumaElemenata(niz, 0, vel) << endl;
	cout << "Suma pozitivnih elemenata iznosi: " << sumaPozitivnih(niz, 0, vel) << endl;
	cout << "Suma elemenata sa parnim indexom: " << sumaSaParnimIndexom(niz, 0, vel) << endl;
}
