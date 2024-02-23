#include<iostream>
#include<iostream>
using namespace std;

int main() {
	srand(time(0));

	int karta1;
	int karta2;
	int karta3;
	int brojPonavaljanja = 0;
	int brojIteracija = 0;
	
	do
	{
		karta1 = rand() % 14 + 1;
		karta2 = rand() % 14 + 1;
		karta3 = rand() % 14 + 1;
		brojIteracija++;
		if (karta1 + 5 == karta2 && karta2 + 5 == karta3)
		{
			cout << karta1 << " " << karta2 << " " << karta3 << endl;
			brojPonavaljanja++;
		}
	} while (brojPonavaljanja < 1);

	cout << "Izvrsilo se nakon: " << brojIteracija << " ponavljanja." << endl;
}

