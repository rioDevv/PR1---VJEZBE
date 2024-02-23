#include<iostream>
using namespace std;

struct fudbaler {
	int* godRodjenja;
	int* brojIgraca;
	int* golovi;

	fudbaler() {
		godRodjenja = new int;
		brojIgraca = new int;
		golovi = new int;
	}

	~fudbaler() {
		delete godRodjenja;
		godRodjenja = nullptr;

		delete brojIgraca;
		brojIgraca = nullptr;

		delete golovi;
		golovi = nullptr;
	}
};

void unos(fudbaler** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			*matrix[i][j].godRodjenja = 1980 + rand() % ((2000 + 1) - 1980);
			*matrix[i][j].brojIgraca = rand() % 30 + 1;
			*matrix[i][j].golovi = rand() % 5;
		}
	}
}

void ispis(fudbaler** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << "Godina rodjenja je: " << *matrix[i][j].godRodjenja << "\t";
			cout << "Broj igraca je: " << *matrix[i][j].brojIgraca << "\t";
			cout << "Broj golova igraca je: " << *matrix[i][j].golovi << endl;
		}
		cout << endl;
	}
}

int main() {
	srand(time(0));

	int rows;
	int cols;

	do
	{
		cout << "Unesite broj redova: ";
		cin >> rows;
		cout << "Unesite broj kolona: ";
		cin >> cols;
	} while (rows < 1 || cols < 1);

	fudbaler** matrix = new fudbaler*[rows];

	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new fudbaler[cols];
	}

	unos(matrix, rows, cols);
	ispis(matrix, rows, cols);

	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
		matrix[i] = nullptr;
	}
	delete[] matrix;
	matrix = nullptr;
}