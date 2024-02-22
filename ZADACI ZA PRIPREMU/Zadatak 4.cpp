#include<iostream>
using namespace std;

int brojPojavljivanjaRijeci(const char* recenica, const char* rijec) {
    int brojPojavljivanja = 0;

    const char* pozicija = strstr(recenica, rijec);

    while (pozicija != nullptr) {
        brojPojavljivanja++;
        pozicija = strstr(pozicija + 1, rijec);
    }

    return brojPojavljivanja;
}

int main() {
    char recenica[200] = "Most u Mostaru je Stari most a pored njega je jos jedan most. ";
    char rijec[5] = "most";

    int rezultat = brojPojavljivanjaRijeci(recenica, rijec);

    cout << "Broj ponavljanja rijeci most u recenici ima: " << rezultat << endl;
}