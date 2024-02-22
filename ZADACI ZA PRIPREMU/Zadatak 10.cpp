#include<iostream>
using namespace std;

const int MAX_SIZE = 10;

void unosMatrice(int matrica[MAX_SIZE][MAX_SIZE], int n) {
    cout << "Unesite elemente matrice:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrica[i][j];
        }
    }
}

bool centralnoSimetricna(int matrica[MAX_SIZE][MAX_SIZE], int n) {
    if (n % 2 == 0) {
        return false;
    }

    int sredina = n / 2;

    for (int i = 0; i <= sredina; i++) {
        for (int j = 0; j < n; j++) {
            if (matrica[i][j] != matrica[n - i - 1][n - j - 1]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int n;
    cout << "Unesite dimenziju matrice (n): ";
    cin >> n;

    if (n <= 0 || n > MAX_SIZE || n % 2 == 0) {
        cout << "Neispravna dimenzija matrice." << endl;
        return 1;
    }

    int matrica[MAX_SIZE][MAX_SIZE];

    unosMatrice(matrica, n);

    if (centralnoSimetricna(matrica, n)) {
        cout << "Matrica je centralno simetrična." << endl;
        return 1;
    }
    else {
        cout << "Matrica nije centralno simetrična." << endl;
        return 0;
    }
}
