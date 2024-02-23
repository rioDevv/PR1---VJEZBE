#include<iostream>
using namespace std;

int main() {
	float g = 9.81;

	for (int i = 3; i < 20; i+=3)
	{
		cout << "Situacija u " << i << "-oj sekundi je : " << endl;
		cout << "Brzina: " << g * i << endl;
		cout << "Predjeni put: " << (g / 2) * pow(i, 2) << endl;
		cout << "----------------------" << endl;
	}
}