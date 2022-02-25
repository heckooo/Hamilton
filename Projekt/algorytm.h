/**
 * @file algorytm.h
 *
 * @brief Nagłówek do algorytm.cpp.
 */
#pragma once
#include <vector>

#include "graf.h"
/**
 * @brief Funkcja wywoułąjąca funkcję znajdującą ścieżkę Hamiltona
 * @param graf Struktura grafu - lista sąsiedztwa
 * @return Zwraca ścieżkę Hamiltona o najmniejszej wadze
*/
Sciezka sciezka_hamiltona(const Graf& graf);
/**
 * @brief Funkcja znajdująca ścieżkę Hamiltona o najmniejszej wadze
 * @param nr_wierzcholka Obecny numer wierzchołka w grafie
 * @param graf Struktura grafu - lista sąsiedztwa
 * @param odwiedzone Zmienna przyjmująca wartość true, kiedy dany wierzchołek został odwiedzony
 * @param sciezka_temp Chwilowa ścieżka
 * @param sciezka_min Ścieżka o najmniejszej wadze
*/
void znajdz_sciezke(int nr_wierzcholka, const Graf& graf, std::vector<bool>& odwiedzone, Sciezka& sciezka_temp, Sciezka& sciezka_min);
