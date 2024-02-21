#include<iostream>
#include<iomanip>
using namespace std;

int getRandomValues(int from, int to) {
	return rand() % (to - from + 1) + from;
}

int** createMatrix(int rows, int cols) {
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols];
	}
	return matrix;
}

void setRandomValues(int** matrix, int rows, int cols, int from, int to) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = getRandomValues(from, to);
		}
	}
}

void printMatrix(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(3) << matrix[i][j];
		}
		cout << endl;
	}
}

void getAveragesByRow(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		int suma = 0;
		for (int j = 0; j < cols; j++)
		{
			suma += matrix[i][j];
		}
		cout << "Prosjek reda na indexu " << i << " : " << float(suma) / cols << endl;
		cout << endl;
	}
}

void getAveragesByColumn(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		int suma = 0;
		for (int j = 0; j < cols; j++)
		{
			suma += matrix[j][i];
		}
		cout << "Prosjek kolone na indexu " << i << " : " << float(suma) / rows << endl;
		cout << endl;
	}
}

void deleteMatrix(int** matrix, int rows) {
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
		matrix[i] = nullptr;
	}
	delete[] matrix;
	matrix = nullptr;
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
	cout << endl;

	int from = 6;
	int to = 10;

	int** matrix = createMatrix(rows, cols);

	setRandomValues(matrix, rows, cols, from, to);

	cout << "MATRICA: " << endl;
	cout << "-----------------------------" << endl;
	printMatrix(matrix, rows, cols);
	cout << "-----------------------------" << endl;
	cout << endl;

	getAveragesByRow(matrix, rows, cols);
	cout << endl;
	getAveragesByColumn(matrix, rows, cols);

	deleteMatrix(matrix, rows);
}
