#include<iostream>
#include<time.h>
using namespace std;

int getRandomValue(int from, int to) {
    return rand() % (to - from + 1) + from;
}

int imaUzastopneBrojeve(int niz[], int velicina) {
    int brojac = 0;
    int uzastopni = 0;

    for (int i = 0; i < velicina - 3; i++) {
        if (niz[i] + 1 == niz[i + 1] &&
            niz[i + 1] + 1 == niz[i + 2] &&
            niz[i + 2] + 1 == niz[i + 3]) {
            return niz[i] * 1000 + niz[i + 1] * 100 + niz[i + 2] * 10 + niz[i + 3];
        }
    }

    return false;
}

int main() {
    srand(time(0));
    const int vel = 50;
    int niz[vel];

    for (int i = 0; i < vel; i++)
    {
        niz[i] = getRandomValue(1, 10);
    }

    for (int i = 0; i < vel; i++)
    {
        cout << niz[i] << " ";
    }
    cout << endl;

    int result = imaUzastopneBrojeve(niz, vel);
    if (result) {
        cout << "Prva sekvencija od minimalno 4 uzastopna broja: " << result << endl;
    }
    else {
        cout << "Nema sekvenci od minimalno 4 uzastopna broja." << endl;
    }

    return 0;
}