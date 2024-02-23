#include<iostream>i
#include<iomanip>
using namespace std;

const int rows = 4;
const int cols = 4;

bool isBlack(int index1, int index2) {
	return ((index1 + index2) % 2) != 0;
}

int brojCifara(int broj) {
	int brojac = 0;
	while (broj > 0)
	{
		broj /= 10;
		brojac++;
	}
	return brojac;
}

void unos(int matrix[][cols], int r, int c) {
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (isBlack(i,j))
			{
				int unos;
				do
				{
					cout << "Unesite parni broj sa neparnim brojem cifara (crno polje): ";
					cin >> unos;
				} while (!(unos % 2 == 0) || brojCifara(unos) % 2 == 0);

				matrix[i][j] = unos;
			}
			else
			{
				int unos;
				do
				{
					cout << "Unesite neparan broj sa parnim brojem cifara (bijelo polje): ";
					cin >> unos;
				} while (unos % 2 == 0 || !(brojCifara(unos) % 2 == 0));

				matrix[i][j] = unos;
			}
		}
	}
}

void ispis(int matrix[][cols], int r, int c) {
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << setw(3) << matrix[i][j];
		}
		cout << endl;
	}
}

bool isSimetricMainDiagonal(int matrix[][cols], int r, int c) {
	for (int i = 0; i < r; i++)
	{
		for (int j = i + 1; j < c; j++)
		{
			if (matrix[i][j] != matrix[j][i])
			{
				return false;
			}
		}
	}
	return true;
}

float averageByRow(int matrix[][cols], int r, int c) {
	int indexNajbolji = 0;
	int prosjekRedova[rows] = { 0 };

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			prosjekRedova[i] += matrix[i][j];
		}
		prosjekRedova[i] /= cols;
		if (i > 0)
		{
			if (prosjekRedova[i] > prosjekRedova[indexNajbolji])
			{
				indexNajbolji = i;
			}
		}
	}
	cout << "Najveci prosjek je: " << prosjekRedova[indexNajbolji] << endl;
	return indexNajbolji;
}

float averageByColumns(int matrix[][cols], int r, int c) {
	int indexNajgori = 0;
	int prosjekKolona[cols] = { 0 };

	for (int j = 0; j < cols; j++)
	{
		for (int i = 0; i < rows; i++)
		{
			prosjekKolona[j] += matrix[i][j];
		}
		prosjekKolona[j] /= cols;
		if (j > 0)
		{
			if (prosjekKolona[j] > prosjekKolona[indexNajgori])
			{
				indexNajgori = j;
			}
		}
	}
	cout << "Najmanji prosjek je: " << prosjekKolona[indexNajgori] << endl;
	return indexNajgori;
}

int main() {
	int matrix[rows][cols];

	unos(matrix, rows, cols);
	ispis(matrix, rows, cols);

	if (isSimetricMainDiagonal(matrix,rows,cols))
	{
		cout << "Niz je simetrican po glavnoj dijagonali." << endl;
		cout << "Index reda sa najvecim prosjekom elemenata je: " << averageByRow(matrix, rows, cols) << endl;
	}
	else
	{
		cout << "Niz nije simetrican po glavnoj dijagonali." << endl;
		cout << "Index kolone sa najmanjim prosjekom elemenata je: " << averageByColumns(matrix, rows, cols) << endl;
	}
}