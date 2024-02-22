#include<iostream>
using namespace std;

int getNajmanji(int broj) {
	int kopijaBroja = broj;
	int najmanji = 9;
	while (broj > 0)
	{
		int trenutniNajmanji = broj % 10;
		if (trenutniNajmanji < najmanji)
		{
			najmanji = trenutniNajmanji;
		}
		broj /= 10;
	}
	return najmanji;
}

int obrniBroj(int broj) {
	int noviBroj = 0;
	while (broj > 0)
	{
		int temp = broj % 10;
		noviBroj = noviBroj * 10 + temp;
		broj /= 10;
	}
	return noviBroj;
}

int getNewBroj(int broj) {
	int najmanji = getNajmanji(broj);
	int noviBroj = 0;
	while (broj > 0)
	{
		int temp = broj % 10;
		if (temp == najmanji)
		{
			temp = 3;
			noviBroj = noviBroj * 10 + temp;
		}
		else
		{
			noviBroj = noviBroj * 10 + temp;
		}
		broj /= 10;
	}
	return obrniBroj(noviBroj);
}

int main() {
	int n;
	
	do
	{
		cout << "Unesite broj: ";
		cin >> n;
	} while (n < 1);

	cout << "Novi broj: " << getNewBroj(n) << endl;
	cout << "Razlika unesenog i novog broja iznosi: " << abs(n - getNewBroj(n)) << endl;
}

