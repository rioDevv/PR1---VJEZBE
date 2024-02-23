#include<iostream>
using namespace std;

struct vozilo {
	char* markaVozila;
	char* brojSasije;
	char* tipVozila;
	int* kubnihCM;

	vozilo() {
		markaVozila = new char[10];
		brojSasije = new char[10];
		tipVozila = new char;
		kubnihCM = new int;
	}

	~vozilo() {
		delete[] markaVozila;
		markaVozila = nullptr;

		delete[] brojSasije;
		brojSasije = nullptr;

		delete tipVozila;
		tipVozila = nullptr;

		delete kubnihCM;
		kubnihCM = nullptr;
	}
};

void unos(vozilo** niz, int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cin.ignore();
			cout << "Unesite marku vozila: ";
			cin.getline(niz[i][j].markaVozila, 10);
			cout << "Unesite broj sasije: ";
			cin.getline(niz[i][j].brojSasije, 10);
			do
			{
				cout << "Unesite tip vozila: ";
				cin >> *niz[i][j].tipVozila;
			} while (*niz[i][j].tipVozila != 'A' && *niz[i][j].tipVozila != 'B' && *niz[i][j].tipVozila != 'C');
			cout << "Unesite broj kubne potrosnje vozila: ";
			cin >> *niz[i][j].kubnihCM;
		}
	}
}

void ispis(vozilo** niz, int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << "Marka vozila je: " << niz[i][j].markaVozila << "\t";
			cout << "Broj sasije vozila je: " << niz[i][j].brojSasije << "\t";
			cout << "Tip vozila je: " << *niz[i][j].tipVozila << "\t";
			cout << "Kubna potrosnja vozila je: " << *niz[i][j].kubnihCM << endl;
		}
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