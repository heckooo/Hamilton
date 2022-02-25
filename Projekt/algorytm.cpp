#include <limits>

#include "algorytm.h"

using namespace std;

Sciezka sciezka_hamiltona(const Graf& graf)
{
	int ilosc_wierzcholkow = graf.size();

	vector<bool> odwiedzone(ilosc_wierzcholkow, false);
	Sciezka sciezka_temp;
	Sciezka sciezka_min;

	sciezka_temp.trasa.reserve(ilosc_wierzcholkow);
	sciezka_min.trasa.reserve(ilosc_wierzcholkow);

	sciezka_min.suma_wag = numeric_limits<int>::max();  // Maksymalna wartosc inta

	for (int i = 0; i < ilosc_wierzcholkow; i++)
	{
		znajdz_sciezke(i, graf, odwiedzone, sciezka_temp, sciezka_min);
	}

	return sciezka_min;
}

void znajdz_sciezke(int nr_wierzcholka, const Graf& graf, vector<bool>& odwiedzone, Sciezka& sciezka_temp, Sciezka& sciezka_min)
{
	if (sciezka_temp.suma_wag > sciezka_min.suma_wag) return;  // Optymalizacja - trasa na pewno nie bedzie lepsza

	odwiedzone[nr_wierzcholka] = true;
	sciezka_temp.trasa.push_back(nr_wierzcholka);

	if (sciezka_temp.trasa.size() == graf.size()) // Jesli true - wszystkie wierzcholki zostaly odwiedzone
	{
		if (sciezka_temp.suma_wag < sciezka_min.suma_wag || sciezka_min.trasa.empty()) // Znaleziona lepsza sciezka lub sciezka_min jest pusta
		{
			sciezka_min = sciezka_temp;
		}

		odwiedzone[nr_wierzcholka] = false;  // Backtracking

		sciezka_temp.trasa.pop_back();	// Backtracking
		
		return;
	}

	for (int i = 0; i < graf[nr_wierzcholka].size(); i++)
	{
		int nr_sasiada = graf[nr_wierzcholka][i].next;
		int waga_sasiada = graf[nr_wierzcholka][i].waga;
		if (odwiedzone[nr_sasiada]) continue; // Jesli odwiedzony nic nie robimy

		sciezka_temp.suma_wag += waga_sasiada;
		
		znajdz_sciezke(nr_sasiada, graf, odwiedzone, sciezka_temp, sciezka_min);

		sciezka_temp.suma_wag -= waga_sasiada;  // Backtracking
	}

	odwiedzone[nr_wierzcholka] = false;  // Backtracking

	sciezka_temp.trasa.pop_back();	// Backtracking
}
