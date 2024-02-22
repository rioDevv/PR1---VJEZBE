#include<iostream>
using namespace std;

bool isPrime(int broj) {
	if (broj == 2 || broj == 3)
	{
		return true;
	}
	for (int i = 2; i < broj; i++)
	{
		if (broj % i == 0)
		{
			return false;
		}
	}
	return true;
}

void goldbach(int broj1, int broj2) {
	if (broj1 % 2 != 0)
	{
		broj1++;
	}

	for (int i = broj1; i <= broj2; i+=2)
	{
		for (int j = 10; j <= i / 2; j++)
		{
			if (isPrime(j) && isPrime(i - j))
			{
				cout << i << " = " << j << " + " << i - j << endl;
				break;
			}
		}
	}
}

int main() {
	int n1, n2;
	do
	{
		cout << "Unesite n1: ";
		cin >> n1;
		cout << "Unesite n2: ";
		cin >> n2;
	} while (n1 > n2);

	goldbach(n1, n2);
}
