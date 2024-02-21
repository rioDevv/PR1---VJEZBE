#include<iostream>
using namespace std;

void printLettersInReverse(char a, char b) {
	if (!isupper(a) || !isupper(b))
	{
		return;
	}
	if (a > b)
	{
		return;
	}
	cout << a;
	printLettersInReverse(a + 1, b);
}

int main() {
	char slovo1, slovo2;
	do
	{
		do
		{
			cout << "Unesite prvo slovo: ";
			cin >> slovo1;
			cout << "Unesite drugo slovo: ";
			cin >> slovo2;
		} while (!isupper(slovo1) || !isupper(slovo2));
	} while (slovo1 > slovo2);

	printLettersInReverse(slovo1, slovo2);
}