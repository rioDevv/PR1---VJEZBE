#include<iostream>
using namespace std;

struct Datum
{
	int dan;
	int mjesec;
	int godina;

	void unos() {
		do
		{
			cout << "Unesite dan: ";
			cin >> dan;
			cout << "Unesite mjesec: ";
			cin >> mjesec;
			cout << "Unesite godinu: ";
			cin >> godina;
		} while (!isValid());
	}

	void ispis() {
		cout << dan << "." << mjesec << "." << godina << endl;
	}

	bool isValid() {
		if (godina < 0)
		{
			return false;
		}
		if (mjesec < 0 || mjesec > 12)
		{
			return false;
		}
		
		int brojDanaUMjesecu = 31;

		if (mjesec == 2)
		{
			if ((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)
			{
				brojDanaUMjesecu = 29;
			}
			else
			{
				brojDanaUMjesecu = 28;
			}
		}
		else if (mjesec == 4 || mjesec == 6 || mjesec == 9 || mjesec == 11)
		{
			brojDanaUMjesecu = 30;
		}
		if (dan < 0 || dan > brojDanaUMjesecu)
		{
			return false;
		}
		return true;
	}

	int toInt() {
		return godina * 365 + mjesec * 30 + dan;
	}
};

Datum& min(Datum& d1, Datum& d2) {
	if (d1.toInt() > d2.toInt())
	{
		return d1;
	}
	return d2;
}

Datum& max(Datum& d1, Datum& d2) {
	if (d1.toInt() < d2.toInt())
	{
		return d1;
	}
	return d2;
}

int getDifferenceBetween(Datum& d1, Datum& d2) {
	int razlika = abs(d1.toInt() - d2.toInt());
	return razlika;
}

Datum* getClosestDate(Datum* arr, int size, Datum& targetDatum) {
	Datum* najblizi = &arr[0];
	int najmanjiNajblizi = getDifferenceBetween(targetDatum, arr[0]);

	for (int i = 1; i < size; i++)
	{
		int razlika = getDifferenceBetween(targetDatum, arr[i]);
		if (najmanjiNajblizi > razlika)
		{
			najmanjiNajblizi = razlika;
			najblizi = &arr[i];
		}
	}
	return najblizi;
}

int main() {
	int vel;
	do
	{
		cout << "Unesite dimenzije niza datuma: ";
		cin >> vel;
	} while (vel<0);

	cout << "---------------------------------------" << endl;

	Datum* nizDatuma = new Datum[vel];
	
	for (int i = 0; i < vel; i++)
	{
		cout << "Unesite datum na indexu " << i << " : " << endl;
		nizDatuma[i].unos();
		cout << "---------------------------------------" << endl;
	}

	for (int i = 0; i < vel; i++)
	{
		nizDatuma[i].ispis();
	}

	Datum targetDatum;

	do
	{
		targetDatum.unos();
	} while (!targetDatum.isValid());

	Datum* najblizi = getClosestDate(nizDatuma, vel, targetDatum);
	cout << "Najblizi datum unesenom je: " << endl;
	najblizi->ispis();

	for (int i = 0; i < vel; i++)
	{
		delete[] nizDatuma;
		nizDatuma = nullptr;
	}
}