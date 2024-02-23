#include<iostream>
using namespace std;

struct vozilo {
	char* markaVozila;
	char* nazivVozila;
	char* tipVozila; // omoguciti unos samo 'A','B','C'
	float* potrosnja_goriva_po_km;

	vozilo() {
		markaVozila = new char[10];
		nazivVozila = new char[10];
		tipVozila = new char;
		potrosnja_goriva_po_km = new float;
	}

	~vozilo() {
		delete[] markaVozila;
		markaVozila = nullptr;

		delete[] nazivVozila;
		nazivVozila = nullptr;

		delete tipVozila;
		tipVozila = nullptr;

		delete potrosnja_goriva_po_km;
		potrosnja_goriva_po_km = nullptr;
	}
};

void unos(vozilo** niz, int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cin.ignore();
			cout << "Unesite marku vozila: ";
			cin.getline((*(niz + i) + j)->markaVozila, 10);
			cout << "Unesite naziv vozila: ";
			cin.getline((*(niz + i) + j)->nazivVozila, 10);
			do
			{
				cout << "Unesite tip vozila: ";
				cin >> *(*(niz + i) + j)->tipVozila;
			} while (*(*(niz + i) + j)->tipVozila != 'A' && *(*(niz + i) + j)->tipVozila != 'B' && *(*(niz + i) + j)->tipVozila != 'C');
			cout << "Unesite potrosnju goriva po km: ";
			cin >> *(*(niz + i) + j)->potrosnja_goriva_po_km;
		}
	}
}

void ispis(vozilo** niz, int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << "Marka vozila je: " << (*(niz + i) + j)->markaVozila << "\t";
			cout << "Naziv vozila je: " << (*(niz + i) + j)->nazivVozila << "\t";
			cout << "Tip vozila je: " << *(*(niz + i) + j)->tipVozila << "\t";
			cout << "Potrosnja goriva po km iznosi: " << (*(niz + i) + j)->potrosnja_goriva_po_km << endl;
		}
		cout << endl;
	}
}

int main() {
	int rows;
	int cols;

	do
	{
		cout << "Unesite broj redova: ";
		cin >> rows;
		cout << "Unesite broj kolona: ";
		cin >> cols;
	} while (rows < 1 || cols < 1);

	vozilo** niz = new vozilo * [rows];

	for (int i = 0; i < rows; i++)
	{
		niz[i] = new vozilo[cols];
	}

	unos(niz, rows, cols);
	ispis(niz, rows, cols);

	for (int i = 0; i < rows; i++)
	{
		delete[] niz[i];
		niz[i] = nullptr;
	}
	delete[] niz;
	niz = nullptr;
}

