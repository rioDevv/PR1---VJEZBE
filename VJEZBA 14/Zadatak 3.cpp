#include<iostream>
using namespace std;

void enterArray(int** parray, int i, int max) {
	if (i == max)
	{
		return;
	}
	cout << "Unesite element na indexu " << i << " : ";
	cin >> *parray[i];
	enterArray(parray, i + 1, max);
}

void printArray(int** parray, int i, int max) {
	if (i == max)
	{
		return;
	}
	cout << *parray[i] << " ";
	printArray(parray, i + 1, max);
}

int sumArray(int** parray, int i, int max) {
	if (i == max)
	{
		return 0;
	}
	return *parray[i] + sumArray(parray, i + 1, max);
}

int findElement(int** parray, int i, int max, int target) {
	if (i == max)
	{
		return -1;
	}
	if (*parray[i] == target)
	{
		return i;
	}
	findElement(parray, i + 1, max, target);
}

int main() {
	int* parray[10] = { nullptr };

	for (int i = 0; i < size(parray); i++)
	{
		parray[i] = new int;
	}

	enterArray(parray, 0, size(parray));

	cout << "Ispis elemenata: " << endl;
	printArray(parray, 0, size(parray));
	cout << endl;

	cout << "Suma elemenata iznosi: " << sumArray(parray, 0, size(parray)) << endl;
	
	int target;
	cout << "Unesite trazeni element: ";
	cin >> target;
	
	if (target != -1)
	{
		cout << "Trazeni element je na indexu :" << findElement(parray, 0, size(parray), target);
	}
	else
	{
		cout << "Trazeni element ne postoji u nizu." << endl;
	}

	for (int i = 0; i < size(parray); i++)
	{
		delete parray[i];
		parray[i] = nullptr;
	}
}