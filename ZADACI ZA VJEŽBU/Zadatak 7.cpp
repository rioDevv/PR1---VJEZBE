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

int** hstack(int** m1, int** m2, int r1, int c1, int r2, int c2) {
	if (r1 != r2) {
		cout << "Matrice imaju razlicit broj redova, pa prema tome - horizontalno slaganje se ne moze izvesti.";
		return nullptr; 
	}

	int** m3 = createMatrix(r1,c1 + c2);
	int brojKolona = 0;

	for (int j = 0; j < c1; j++)
	{
		for (int i = 0; i < r1; i++)
		{
			m3[i][brojKolona] = m1[i][j];
		}
		brojKolona++;
	}

	for (int j = 0; j < c2; j++)
	{
		for (int i = 0; i < r2; i++)
		{
			m3[i][brojKolona] = m2[i][j];
		}
		brojKolona++;
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
	cout << endl;

	int from = 1;
	int to = 20;

	int** m1 = createMatrix(r1, c1);
	int** m2 = createMatrix(r2, c2);

	setRandomValues(m1, r1, c1, from, to);
	cout << "MATRICA M1: " << endl;
	cout << "----------------------------" << endl;
	printMatrix(m1, r1, c1);
	cout << "----------------------------" << endl;

	setRandomValues(m2, r2, c2, from, to);
	cout << "MATRICA M2: " << endl;
	cout << "----------------------------" << endl;
	printMatrix(m2, r2, c2);
	cout << "----------------------------" << endl;

	int** m3 = hstack(m1, m2, r1, c1, r2, c2);

	int r3 = r1;
	int c3 = c1 + c2;

	if (m3 != nullptr) {
		cout << "Matrica M3 formirana horizontalnim slaganjem matrica M1 i M2: " << endl;
		printMatrix(m3, r3, c3);
	}

	deleteMatrix(m1, r1);
	deleteMatrix(m2, r2);
	deleteMatrix(m3, r3);
}
