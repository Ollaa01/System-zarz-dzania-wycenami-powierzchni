#pragma once
#include "Grunty.h"

/**
* Klasa zawierajaca metody wirtualne  oraz inne metody dotyczace dzialek z kategorii Budowlane, dziedziczy po klasie Grunty.
**/
class Budowlane :
    public Grunty
{
public:
    Budowlane(string miasto, string ulica, string numer, bool czygotowe, int powierzchnia, int stan_gruntu, int uzbrojenie) :
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

