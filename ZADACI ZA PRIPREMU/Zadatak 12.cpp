#include <iostream>
using namespace std;

bool imaNeparniBrojCifara(int broj) {
    int brojCifara = 0;
    while (broj != 0) {
        broj /= 10;
        brojCifara++;
    }
    return brojCifara % 2 != 0;
}

bool jeParniBroj(int broj) {
    return broj % 2 == 0;
}

void ukloniDjeljiveSaSest(int niz[], int& velicina) {
    int pomak = 0;
    for (int i = 0; i < velicina; i++) {
        if (niz[i] % 6 == 0) {
            for (int j = i; j < velicina - 1; j++) {
                niz[j] = niz[j + 1];
            }
            velicina--;
            i--;
        }
    }
}

int main() {
    const int vel = 3;
    int niz[vel];
    int velicinaNiza = 0;

    while (velicinaNiza < vel) {
        int unos;
        cin >> unos;

        if (imaNeparniBrojCifara(unos) && jeParniBroj(unos)) {
            niz[velicinaNiza] = unos;
            velicinaNiza++;
        }
        else {
            cout << "Neispravan unos! Unesite paran broj sa neparnim brojem cifara.\n";
        }
    }

    cout << "\nUneseni niz:\n";
    for (int i = 0; i < vel; i++) {
        cout << niz[i] << " ";
    }

    ukloniDjeljiveSaSest(niz, velicinaNiza);

    cout << "\nNiz nakon uklanjanja brojeva djeljivih sa 6:\n";
    for (int i = 0; i < velicinaNiza; i++) {
        cout << niz[i] << " ";
    }

    return 0;
}
