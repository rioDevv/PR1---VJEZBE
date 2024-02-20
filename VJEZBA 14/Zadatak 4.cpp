#include<iostream>
#include<iomanip>
#include<time.h>
using namespace std;

int getRandomValue(int from, int to) {
	return rand() % (to - from + 1) + from;
}

int** createMatrix(int rows, int cols) {
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols] {0};
	}
	return matrix;
}

void setRandomValues(int** matrix, int rows, int cols, int from, int to) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = getRandomValue(from, to);
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

int** diagonalStack(int** m1, int** m2, int r1, int c1, int r2, int c2) {
	int rows = r1 + r2;
	int cols = c1 + c2;
	int** m3 = createMatrix(rows,cols);

	for (int i = 0; i < r1; i++)
	{
		for (int j = 0; j < c1; j++)
		{
			m3[i][j] = m1[i][j];
		}
	}

	for (int i = 0; i < r2; i++)
	{
		for (int j = 0; j < c2; j++)
		{
			m3[i + r1][j + c1] = m2[i][j];
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
	srand(time(0));

	int r1, c1;
	int r2, c2;

	do
	{
		cout << "Unesite broj redova za prvu matricu: ";
		cin >> r1;
		cout << "Unesite broj kolona za prvu matricu: ";
		cin >> c1;
	} while (r1 < 1 || c1 < 1);

	do
	{
		cout << "Unesite broj redova za drugu matricu: ";
		cin >> r2;
		cout << "Unesite broj kolona za drugu matricu: ";
		cin >> c2;
	} while (r2 < 1 || c2 < 1);

	int** m1 = createMatrix(r1, c1);
	int** m2 = createMatrix(r2, c2);

	int from = 1;
	int to = 10;

	setRandomValues(m1, r1, c1, from, to);
	cout << "Matrica M1:" << endl;
	printMatrix(m1, r1, c1);
	cout << endl;

	setRandomValues(m2, r2, c2, from, to);
	cout << "Matrica M2:" << endl;
	printMatrix(m2, r2, c2);
	cout << endl;

	int** m3 = diagonalStack(m1, m2, r1, c1, r2, c2);
	int r3 = r1 + r2;
	int c3 = c1 + c2;

	if (m3 != nullptr)
	{
		cout << "Matrica M3: " << endl;
		printMatrix(m3, r3, c3);
	}

	deleteMatrix(m1, r1);
	deleteMatrix(m2, r2);
	deleteMatrix(m3, r3);
}