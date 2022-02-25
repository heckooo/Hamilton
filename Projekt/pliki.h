/**
 * @file pliki.h
 *
 * @brief Nagłówek do pliki.cpp.
 */
#pragma once
#include <string>

/**
 * @brief Struktura przechowująca parametry z wiersza poleceń
*/
struct Params
{
	std::string plik_we; /**< Scieżka do pliku wejściowego */
	std::string plik_wy; /**< Scieżka do pliku wyjściowego */
};
/**
 * @brief Funkcja wczytująca parametry z wiersza poleceń
 * @param argc Liczba argumentów
 * @param argv Tablica argumentów
 * @param parametry Strukura, do której parametry zostaną zapisane
 * @return True jeśli parametry są poprawne, w innym przypadku zwraca false
*/
bool wczytaj_params(int argc, char* argv[], Params& parametry);
/**
 * @brief Funkcja wypisująca pomoc
 * @param sciezka Ścieżka do pliku .exe
*/
void wypisz_pomoc(char sciezka[]);
/**
 * @brief Funkcja wczytująca plik wejściowy
 * @param nazwa_pliku Nazwa pliku wejściowego
 * @param zawartosc_pliku Zawartość pliku wejściowego - lista sąsiedztwa
 * @return True jeśli dane pliku wejściowego są poprawne, w innym przypadku zwraca false
*/
bool wczytaj_plik(const std::string& nazwa_pliku, std::string& zawartosc_pliku);
/**
 * @brief Funkcja zapisująca minimalną ścieżkę Hamiltona do pliku wyjściowego
 * @param nazwa_pliku Nazwa pliku wejściowego
 * @param zawartosc_pliku Zawartość pliku wejściowego
 * @return True jeśli udało zapisać się ścieżkę Hamiltona do Pliku wyjściowego
*/
bool zapisz_plik(const std::string& nazwa_pliku, const std::string& zawartosc_pliku);
