#include<iostream>
#include<string>
using namespace std;

int main() {
    const int brojTekstova = 3;
    int ukupnaVelicina = 0;
    char** tekstovi = new char* [brojTekstova];

    for (int i = 0; i < brojTekstova; i++)
    {
        char temp[200] = "";
        cout << "Unesite tekst " << i + 1 << " : ";
        cin.getline(temp, sizeof(temp));
        int size = strlen(temp) + 1;
        tekstovi[i] = new char[size];
        strcpy_s(tekstovi[i], size, temp);
        ukupnaVelicina += strlen(temp) + 1;
    }

    char* noviTekst = new char[ukupnaVelicina];
    noviTekst[0] = '\0';

    for (int i = 0; i < brojTekstova; i++)
    {
        strcat_s(noviTekst, ukupnaVelicina, tekstovi[i]);
        if (i != brojTekstova - 1)
        {
            strcat_s(noviTekst, ukupnaVelicina, " ");
        }
    }

    // Postavljanje svakog prvog slova u rečenici kao veliko slovo
    bool prvoSlovo = true;
    for (int i = 0; i < ukupnaVelicina; i++) {
        if (isalpha(noviTekst[i])) {
            if (prvoSlovo) {
                noviTekst[i] = toupper(noviTekst[i]);
                prvoSlovo = false;
            }
        }
        else {
            prvoSlovo = true;
        }
    }

    cout << "Rezultat: " << noviTekst << endl;

    delete[] noviTekst;

    for (int i = 0; i < brojTekstova; i++)
    {
        delete[] tekstovi[i];
        tekstovi[i] = nullptr;
    }
    delete[] tekstovi;
    tekstovi = nullptr;

    return 0;
}
