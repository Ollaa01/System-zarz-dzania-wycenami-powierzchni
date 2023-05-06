#pragma once
#include "Grunty.h"

/**
* Klasa zawierajaca metody wirtualne oraz inne metowdy dotyczace dzialek z kategorii Rolne, dziedziczy po klasie Grunty.
**/
class Rolne :
    public Grunty
{
public:
    Rolne(string miasto, string ulica, string numer, bool czygotowe, int powierzchnia, int stan_gruntu, int uzbrojenie) :
        Grunty(miasto, ulica, numer, czygotowe, powierzchnia, stan_gruntu, uzbrojenie) {};
	void wyswietOpis();
	void zapiszOpis(fstream& plik);
	void zapiszOpis2(ofstream& plik);
	string miastoWyc();
	string ulicaWyc();
	string numerWyc();
	bool czygotoweWyc();
	int powWyc();
	int stan_gruntuWyc();
	int uzbrojenieWyc();
	string zamienBool();
	string zamienstan();
	string zamienUzbr();
};

