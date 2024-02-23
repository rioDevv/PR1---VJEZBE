#include<iostream>
using namespace std;

void capitalizeWords(char* tekst) {
	int prvoSlovo = true;

	for (int i = 0; tekst[i] != '\0'; i++)
	{
		if (isalpha(tekst[i]))
		{
			if (prvoSlovo)
			{
				tekst[i] = toupper(tekst[i]);
				prvoSlovo = false;
			}
		}
		else
		{
			prvoSlovo = true;
		}
	}
}

int countOccurences(char** tekstovi, int brojTekstova, char* rijec) {
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

int main() {
	int brojTekstova;
	int ukupnaVelicina = 0;

	do
	{
		cout << "Unesite broj tekstova: ";
		cin >> brojTekstova;
		cin.ignore();
	} while (brojTekstova < 1);
	cout << endl;

	char** tekstovi = new char* [brojTekstova];

	for (int i = 0; i < brojTekstova; i++)
	{
		char temp[200] = "";
		cout << i + 1 << ". tekst: ";
		cin.getline(temp, size(temp));
		int size = strlen(temp) + 1;
		tekstovi[i] = new char[size];
		strcpy_s(tekstovi[i], size, temp);
		ukupnaVelicina += strlen(temp) + 1;
	}

	cout << endl;
	cout << "Nakon capializeWords: " << endl;
	cout << endl;

	for (int i = 0; i < brojTekstova; i++)
	{
		capitalizeWords(tekstovi[i]);
		cout << i + 1 << ". :" << tekstovi[i] << endl;
	}

	cout << endl;

	char* noviTekst = new char[ukupnaVelicina];
	noviTekst[0] = '\0';

	for (int i = 0; i < brojTekstova; i++)
	{
		strcat_s(noviTekst, ukupnaVelicina,tekstovi[i]);
		if (i != brojTekstova - 1)
		{
			strcat_s(noviTekst, ukupnaVelicina, ";");

		}
	}

	int prvoSlovo = true;

	for (int i = 0; i < ukupnaVelicina; i++)
	{
		if (isalpha(noviTekst[i]))
		{
			if (prvoSlovo)
			{
				noviTekst[i] = toupper(noviTekst[i]);
				prvoSlovo = false;
			}
		}
		else
		{
			prvoSlovo = true;
		}
	}

	for (int i = 0; i < ukupnaVelicina; i++)
	{
		cout << noviTekst[i];
	}
	cout << endl;

	char trazenaRijec[50];

	cout << "Unesite trazenu rijec: ";
	cin.getline(trazenaRijec, size(trazenaRijec));

	cout << "Rijec se ponavlja " << countOccurences(tekstovi, brojTekstova, trazenaRijec) << " puta." << endl;

	for (int i = 0; i < brojTekstova; i++)
	{
		delete[] tekstovi[i];
		tekstovi[i] = nullptr;
	}
	delete[] tekstovi;
	tekstovi = nullptr;

	delete[] noviTekst;
	noviTekst = nullptr;
}

