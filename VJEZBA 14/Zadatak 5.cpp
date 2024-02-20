#include<iostream>
using namespace std;

void rotateArray(int** parray, int size, int rotateWindow) {
	if (rotateWindow < size)
	{
		int** tempArray = new int*[size];

		for (int i = 0; i < rotateWindow; i++)
		{
			tempArray[i] = parray[i];
		}

		for (int i = rotateWindow; i < size; i++)
		{
			parray[i - rotateWindow] = parray[i];
		}

		for (int i = size - rotateWindow; i < size; i++)
		{
			parray[i] = tempArray[i - (size - rotateWindow)];
		}
	}
}

int main() {
	int vel;
	do
	{
		cout << "Unesite velicinu niza: ";
		cin >> vel;
	} while (vel<0);

	int** parray = new int* [vel];

	for (int i = 0; i < vel; i++)
	{
		parray[i] = new int;
	}

	for (int i = 0; i < vel; i++)
	{
		cout << "Unesite element na indexu " << i << " : ";
		cin >> *parray[i];
	}

	cout << "ISPIS ELEMENATA PRIJE ROTACIJE: " << endl;

	for (int i = 0; i < vel; i++)
	{
		cout << *parray[i] << " ";
	}

	int rotationWindow = 0;

	do
	{
		cout << "Unesite velicinu rotacije: ";
		cin >> rotationWindow;
	} while (0 > rotationWindow || rotationWindow > vel);

	rotateArray(parray, vel, rotationWindow);

	cout << "ISPIS ELEMENATA POSLIJE ROTACIJE: " << endl;

	for (int i = 0; i < vel; i++)
	{
		cout << *parray[i] << " ";
	}

	//DEALOKACIJA 

	for (int i = 0; i < vel; i++)
	{
		delete[] parray[i];
		parray[i] = nullptr;
	}
	delete[] parray;
	parray = nullptr;
}