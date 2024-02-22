#include<iostream>
#include<time.h>
using namespace std;

int main() {
	srand(time(0));
	int prvaKockica;
	int drugaKockica;
	int trecaKockica;
	int brojacBacanja = 0;
	int brojIstih = 0;

	do
	{
		prvaKockica = rand() % 6 + 1;
		drugaKockica = rand() % 6 + 1;
		trecaKockica = rand() % 6 + 1;
		brojacBacanja++;

		if (prvaKockica == drugaKockica && drugaKockica == trecaKockica)
		{
			cout << prvaKockica << endl;
			cout << drugaKockica << endl;
			cout << trecaKockica << endl;
			cout << "---------------------" << endl;
			cout << brojacBacanja << endl;
			cout << "---------------------" << endl;
			brojIstih++;
		}
		else {
			brojIstih = 0;
		}

	} while (brojIstih < 2);

	cout << "OVOLIKO JE TREBALO: " << brojacBacanja;
}
