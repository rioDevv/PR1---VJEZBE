#include<iostream>
#include<iomanip>
using namespace std;

const int rows = 3;
const int cols = 3;

int getRandomValues(int from, int to) {
	return rand() % (to - from + 1) + from;
}

void setRandomValues(int matrix[][cols], int rows, int cols, int from, int to) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = getRandomValues(from, to);
		}
	}
}

void printMatrix(int matrix[][cols], int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(3) << matrix[i][j];
		}
		cout << endl;
	}
}

void transposeMatrix(int matrix[][cols], int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = i + 1; j < cols; j++)
		{
			int temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}
}

float getAritmeticAboveMainDiagonal(int matrix[][cols], int rows, int cols) {
	float suma = 0;
	int brojac = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = i + 1; j < cols; j++)
		{
			if (matrix[i][j] % 2 == 0)
			{
				suma += matrix[i][j];
				brojac++;
			}
		}
	}
	if (suma == 0)
	{
		return 0;
	}
	return float(suma) / brojac;
}

float getAritmeticAboveSideDiagonal(int matrix[][cols], int rows, int cols) {
	float suma = 0;
	int brojac = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols - i - 1; j++)
		{
			if (matrix[i][j] % 2 != 0)
			{
				suma += matrix[i][j];
				brojac++;
			}
		}
	}
	return float(suma) / brojac;
}

int main() {
	srand(time(0));

	int matrix[rows][cols];
	int from = 1;
	int to = 10;

	setRandomValues(matrix, rows, cols, from, to);
	cout << "MATRICA: " << endl;
	printMatrix(matrix, rows, cols);
	cout << endl;

	int aritmetickaIznadGlavne = getAritmeticAboveMainDiagonal(matrix, rows, cols);

	transposeMatrix(matrix, rows, cols);
	cout << "TRANSPONIRANA MATRICA: " << endl;
	printMatrix(matrix,rows,cols);
	cout << endl;

	int aritmetickaIznadSporedne = getAritmeticAboveSideDiagonal(matrix, rows, cols);

	cout << "Aritmeticka sredina svih parnih brojeva iznad glavne dijagonale iznosi: " << aritmetickaIznadGlavne << endl;
	cout << "Aritmeticka sredina svih neparnih brojeva iznad sporedne dijagonale iznosi: " << aritmetickaIznadSporedne << endl;
}
