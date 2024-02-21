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
		for (int  j = 0; j < cols; j++)
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

int** addMatrices(int** m1, int** m2, int rows, int cols) {
	int** m3 = createMatrix(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			m3[i][j] = m1[i][j] + m2[i][j];
		}
	}
	return m3;
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
	int rows;
	int cols;

	do
	{
		cout << "Unesite broj redova: ";
		cin >> rows;
		cout << "Unesite broj kolona: ";
		cin >> cols;
	} while (rows < 1 || cols < 1);

	int from = 1;
	int to = 10;

	int** m1 = createMatrix(rows, cols);
	int** m2 = createMatrix(rows, cols);

	cout << "MATRICA M1: " << endl;
	setRandomValues(m1, rows, cols, from, to);
	printMatrix(m1, rows, cols);

	cout << "MATRICA M2: " << endl;
	setRandomValues(m2, rows, cols, from, to);
	printMatrix(m2, rows, cols);

	int** m3 = addMatrices(m1, m2, rows, cols);
	
	cout << "MATRICA M3: " << endl;
	printMatrix(m3, rows, cols);

	deleteMatrix(m1, rows);
	deleteMatrix(m2, rows);
	deleteMatrix(m3, rows);
}
