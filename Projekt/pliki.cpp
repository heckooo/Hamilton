#include <iostream>
#include <filesystem>
#include <fstream>
#include <sstream>

#include "pliki.h"

using namespace std;

bool wczytaj_params(int argc, char* argv[], Params& parametry)
{
    if (argc != 5)
    {
        return false;
    }

    for (int i = 1; i < argc; i++)
    {
        if (!strcmp(argv[i], "-i"))
        {
            parametry.plik_we = argv[++i];
        }
        if (!strcmp(argv[i], "-o"))
        {
            parametry.plik_wy = argv[++i];
        }
    }
    // Sprawdzenie czy nie sa puste
    return !(parametry.plik_we == "" || parametry.plik_wy == "");
}

void wypisz_pomoc(char sciezka[])
{
    // Zwraca nazwe pliku jako string
    string nazwa_exe = filesystem::path(sciezka).filename().string();

    cout << "Nieprawidlowe parametry wejsciowe\n";
    cout << "Uzycie: \n";
    cout << nazwa_exe << " -i plik_wejsciowy -o plik_wyjsciowy\n";
}

bool wczytaj_plik(const string& nazwa_pliku, string& zawartosc_pliku)
{
    ifstream plik_we(nazwa_pliku);
    if (!plik_we.is_open()) return false;

    // Zawartosc pliku do temp
    stringstream temp;
    temp << plik_we.rdbuf(); // rdbuf - odczytujemy caly plik
    zawartosc_pliku = temp.str();

    return plik_we.good();
}

bool zapisz_plik(const string& nazwa_pliku, const string& zawartosc_pliku)
{
    ofstream plik_wy(nazwa_pliku);
    if (!plik_wy.is_open()) return false;

    plik_wy << zawartosc_pliku;

    return plik_wy.good();
}