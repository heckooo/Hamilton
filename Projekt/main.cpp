#include <iostream>
#include <string>

#include "graf.h"
#include "pliki.h"
#include "algorytm.h"

using namespace std;

bool wykonaj(const Params& parametry)
{
    string dane_wejsciowe;
    if (!wczytaj_plik(parametry.plik_we, dane_wejsciowe))
    {
        cout << "Nie udalo sie wczytac pliku wejsciowego.\n";
        return false;
    }

    Graf graf = wczytywanie(dane_wejsciowe);

    Sciezka min_sciezka = sciezka_hamiltona(graf);

    string dane_wyjsciowe = sciezka_na_string(min_sciezka);

    if (!zapisz_plik(parametry.plik_wy, dane_wyjsciowe))
    {
        cout << "Nie udalo sie zapisac pliku wyjsciowego.\n";
        return false;
    }

    return true;
}

int main(int argc, char* argv[])
{
    Params parametry;

    if (!wczytaj_params(argc, argv, parametry))
    {
        wypisz_pomoc(argv[0]);
        return 1;
    }
    if (!wykonaj(parametry)) return 1;

    return 0;
}