#include<iostream>
#include<iomanip>
#include<time.h>
using namespace std;

	/*
		Napisati program koji izračunava prosjek ocjena za svakog studenta u 2D nizu i prosjek
		svakog predmeta u 2D nizu [proizvoljnih dimenzija]. Studenti su rasporedjeni po redovima,
		a predmeti po kolonama.Program treba da ispiše prosjek svakog studenta ponaosob i
		prosjek svakog predmeta ponaosob. Matricu ocjena popuniti slucajnim vrijednostima [5-
		10]. Ukoliko je ocjena = 5, ne racunati prosjek za istu [jer se vodimo logikom da ocjena 5
		oznacava da student nije polozio dati predmet].
	*/

const int MAX_REDOVA = 50;
const int MAX_KOLONA = 50;

int getRandomValues(int from, int to) {
	return rand() % (to - from + 1) + from;
}

void setRandomValues(int matrica[][MAX_KOLONA], int rows, int cols, int from, int to) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrica[i][j] = getRandomValues(from, to);
		}
	}
}

void printMatrix(int matrica[][MAX_KOLONA], int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(3) << matrica[i][j];
		}
		cout << endl;
	}
}

void printAverageGradesStudent(int matrica[][MAX_KOLONA], int rows, int cols) {
	for (int i = 0; i < rows; i++)
	{
		int suma = 0;
		int brojac = 0;
		for (int j = 0; j < cols; j++)
		{
			if (matrica[i][j] != 5)
			{
				suma += matrica[i][j];
				brojac++;
			}
		}
		cout << "Student broj " << i + 1 << " ima prosjek ocjena: " << float(suma) / brojac << endl;
	}
	cout << endl;
}

void printAverageGradesSubject(int matrica[][MAX_KOLONA], int rows, int cols) {
	for (int i = 0; i < cols; i++)
	{
		int suma = 0;
		int brojac = 0;
		for (int j = 0; j < rows; j++)
		{
			if (matrica[j][i] != 5)
			{
				suma += matrica[j][i];
				brojac++;
			}
		}
		cout << "Predmet broj " << i + 1 << " ima prosjek ocjena: " << float(suma) / brojac << endl;
	}
	cout << endl;
}

int main() {
	srand(time(0));
	int rows;
	int cols;
	int matrix[MAX_REDOVA][MAX_KOLONA];

	do
	{
		cout << "Unesi redove: ";
		cin >> rows;
		cout << "Unesi kolone: ";
		cin >> cols;
	} while (rows<0 || rows>MAX_REDOVA || cols<0 || cols>MAX_KOLONA);

	int from = 5;
	int to = 10;

	setRandomValues(matrix, rows, cols, from, to);
	printMatrix(matrix, rows, cols);

	printAverageGradesStudent(matrix, rows, cols);
	printAverageGradesSubject(matrix, rows, cols);
}