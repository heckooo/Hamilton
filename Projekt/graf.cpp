#include <algorithm>
#include <cctype>
#include <sstream>

#include "graf.h"
// Traktujemy wagi jako absolute value ||

using namespace std;

// procedura wczytujaca dane z pliku do tablic z danymi

Graf wczytywanie(string& znaki)
{
	Graf nowy_graf; // Lista siasiedztwa na poczatku pusta

	auto nie_liczba = [](char c) // Lambda - funkcja pomocnicza
	{
		return !isdigit(c);  // Zwaraca true jesli c nie jest cyfra
	};

	replace_if(znaki.begin(), znaki.end(), nie_liczba, ' '); // Zmieniamy znaki nie liczbowe na spacje

	int krawedz, sasiad, waga;

	stringstream dane_wejsciowe(znaki);

	while (dane_wejsciowe >> krawedz >> sasiad >> waga) // Dopoki udaje sie wczytywac liczby - True
	{
		if (krawedz >= nowy_graf.size() || sasiad >= nowy_graf.size())
		{
			nowy_graf.resize(max(krawedz, sasiad) + 1);
		}
		
		nowy_graf[krawedz].push_back(Krawedz(sasiad, waga));
	}

	return nowy_graf;
}

string sciezka_na_string(const Sciezka& sciezka)
{
	if (sciezka.trasa.size() == 0)  return "Dla tego grafu nie istnieje sciezka Hamiltona."; // Wypisanie do pliku komunikatu o pustej sciezce

	string wynik;
	const vector<int>& trasa = sciezka.trasa;


	for (int i = 0; i < trasa.size(); i++)
	{
		wynik += to_string(trasa[i]) + " -> "; // Konkatenacja
	}

	wynik.erase(wynik.size() - 4);

	wynik += "\nSuma wag: " + to_string(sciezka.suma_wag);

	return wynik;
}