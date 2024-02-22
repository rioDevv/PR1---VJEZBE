#include<iostream>
using namespace std;

int savrsenBroj(int broj) {
	int suma = 0;
	for (int i = 1; i < broj; i++)
	{
		if (broj % i == 0)
		{
			suma += i;
		}
	}
	return suma;
}

int main() {
	int broj;
	int noviBroj = 0;

	do
	{
		cout << "Upisi znamenku: ";
		cin >> broj;
		if (broj > 0 && broj < 10)
		{
			noviBroj = noviBroj * 10 + broj;
		}
	} while (broj > 0 && broj < 10);

	cout << "Broj sastavljen od zadanih znamenaka je: " << noviBroj << endl;
	
	if (savrsenBroj(noviBroj) == noviBroj)
	{
		cout << "Broj je savrsen." << endl;
	}
	else
	{
		cout << "Broj nije savrsen." << endl;
	}
}


