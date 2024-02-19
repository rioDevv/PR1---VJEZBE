#include<iostream>
#include<iomanip>
#include<time.h>
using namespace std;

	/*
		Napisati program koji ce za unesenu matricu [proizvoljnih dimenzija] uraditi transponovanje
		iste.
		 Koristiti matricu sa random vrijednostima sa opsegom [1-10].
		 Npr.
		 Matrica
		 1 2 3
		 4 5 6
		 7 8 9
		 nakon transponovanja postaje poprima sljedeci oblik:
		 1 4 7
		 2 5 8
		 3 6 9
	*/

const int MAX_REDOVA = 50;
const int MAX_KOLONA = 50;

int getRandomValues(int from, int to) {
	return rand() % (to - from + 1) + from;
}

void setRandomValues(int matrix[][MAX_KOLONA], int rows, int cols, int from, int to) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = getRandomValues(from, to);
		}
	}
}

void printMatrix(int matrix[][MAX_KOLONA], int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(3) << matrix[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	int rows;
	int cols;
	int matrica[MAX_REDOVA][MAX_KOLONA];

	do
	{
		cout << "Unesite broj redova: ";
		cin >> rows;
		cout << "Unesite broj kolona: ";
		cin >> cols;
	} while (rows < 0 || rows > MAX_REDOVA || cols < 0 || cols > MAX_KOLONA);

	int from = 1;
	int to = 10;

	setRandomValues(matrica, rows, cols, from, to);
	printMatrix(matrica, rows, cols);

	int transponiranaMatrica[MAX_REDOVA][MAX_KOLONA];

	for (int j = 0; j < cols; j++)
	{
		for (int i = 0; i < rows; i++)
		{
			transponiranaMatrica[j][i] = matrica[i][j];
		}
	}

	printMatrix(transponiranaMatrica, rows, cols);
}