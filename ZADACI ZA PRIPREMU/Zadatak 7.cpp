#include<iostream>
using namespace std;

bool isPalindrom(int broj) {
	int kopijaBroja = broj;
	int noviBroj = 0;
	while (broj > 0)
	{
		int temp = broj % 10;
		noviBroj = noviBroj * 10 + temp;
		broj /= 10;
	}

	broj = kopijaBroja;

	if (noviBroj == broj)
	{
		return true;
	}
	return false;
}

int main() {
	int a, b;
	
	do
	{
		cout << "Unesite a: ";
		cin >> a;
		cout << "Unesite b: ";
		cin >> b;
	} while (a < 200 || b < a + 100);
	
	if (a % 2 != 0)
	{
		a++;
	}

	for (int i = a; i <= b; i+=2)
	{
		for (int j = 10; j < i / 2; j++)
		{
			if (isPalindrom(j) && isPalindrom(i - j))
			{
				cout << i << " = " << i - j << " + " << j << endl;
				break;
			}
		}
	}
}