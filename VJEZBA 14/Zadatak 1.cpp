#include<iostream>
using namespace std;

int count(char** tekstovi, int brojTekstova, const char* rijec) {
	int brojac = 0;
	for (int i = 0; i < brojTekstova; i++)
	{
		if (strstr(tekstovi[i], rijec) != nullptr)
		{
			brojac++;
		}
	}
	return brojac;
}

bool isSingleWord(const char* tekst) {
	const char* p = tekst;
	while (*p != '\0')
	{
		if (*p == ' ')
		{
			return false;
		}
		p++;
	}
	return true;
}

int main() {
	int brojTekstova = 1;
	do
	{
		cout << "Unesite broj tekstova:	";
		cin >> brojTekstova;
		cin.ignore();
	} while (brojTekstova<0);

	char** tekstovi = new char*[brojTekstova];

	for (int i = 0; i < brojTekstova; i++)
	{
		char temp[200] = "";
		
		cout << "Unesite tekst na indexu " << i << endl;
		cin.getline(temp, size(temp));

		int size = strlen(temp) + 1;
		tekstovi[i] = new char[size];

		strcpy_s(tekstovi[i], size, temp);
	}

	for (int i = 0; i < brojTekstova; i++)
	{
		cout << "Tekst " << i << " : " << tekstovi[i] << endl;
	}

	char rijec[50];

	do
	{
		cout << "Unesite jednu rijec: ";
		cin.getline(rijec, size(rijec));
	} while (!isSingleWord(rijec));

	cout << "Broj tekstova u kojima mozemo pronaci rijec je: " << count(tekstovi, brojTekstova, rijec) << endl;
	
	for (int i = 0; i < brojTekstova; i++)
	{
		delete[] tekstovi[i];
		tekstovi[i] = nullptr;
	}
	delete[] tekstovi;
	tekstovi = nullptr;

	return 0;
}