#include<iostream>
using namespace std;

int main() {
	char temp[200] = "";

	cout << "Unesite tekst: ";
	cin.getline(temp, size(temp));

	int size = strlen(temp) + 1;
	char* tekst = new char[size];

	strcpy_s(tekst, size, temp);

	int currentLongest = 0;
	int longest = 0;

	char* p = nullptr;

	for (int i = 0; i < size; i++)
	{
		if (isalpha(tekst[i]))
		{
			currentLongest++;
		}
		else
		{
			if (currentLongest > longest)
			{
				longest = currentLongest;
				p = tekst + i - currentLongest;
			}
			currentLongest = 0;
		}
	}

	cout << "Najveca duzina je: " << longest << endl;
	cout << "Najduza rijec: ";
	for (int i = 0; i < longest; i++)
	{
		cout << p[i];
	}

	delete[] tekst;
	tekst = nullptr;
}