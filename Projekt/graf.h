/**
 * @file graf.h
 *
 * @brief Nagłówek do graf.cpp.
 */
#pragma once
#include <string>
#include <vector>
/**
 * @brief Struktura krawędzi w grafie, zawierająca nr sąsiada oraz wagę
*/
struct Krawedz
{
    int next; /**< Następna krawędź */
    int waga; /**< Waga krawędzi */
};
/**
 * @brief Struktura ścieżki, zawierająca trasę ścieżki Hamiltona oraz sumę wag tej ścieżki
*/
struct Sciezka
{
	std::vector<int> trasa; /**< Trasa ścieżki Hamiltona */
	int suma_wag = 0; /**< Suma wag krawędzi */
};
/**
 * @brief Struktura listy sąsiedztwa
*/
using Graf = std::vector<std::vector<Krawedz>>;

/**
 * @brief Funkcja wczytująca graf z tekstu z pliku wejściowym
 * @param znaki Tekst z pliku wejściowego
 * @return Zwraca strukturę listy sąsiedztwa, bez znaków białych
*/
Graf wczytywanie(std::string& znaki);
/**
 * @brief Funkcja przekształcająca uzyskaną ścieżkę na tekst wygodny w odczycie dla użytkownika(do pliku wyjściowego)
 * @param sciezka Struktra ścieżki, która ma zostać przekształcona
 * @return Zwraca uzyskaną ścieżkę Hamiltona w postaci tekstowej
*/
std::string sciezka_na_string(const Sciezka& sciezka);
