#include<iostream>
using namespace std;

int nthFibonacci(int broj) {
	if (broj <= 2)
	{
		return 1;
	}
	return nthFibonacci(broj - 1) + nthFibonacci(broj - 2);
}

int main() {
	int broj;
	do
	{
		cout << "Unesite broj: ";
		cin >> broj;
	} while (broj < 1);

	cout << "Odgovarujuci Fibonaccijev broj je: " << nthFibonacci(broj);
}