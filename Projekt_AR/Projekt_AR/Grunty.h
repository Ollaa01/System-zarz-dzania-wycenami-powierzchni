#pragma once
#include "Bazowa.h"

/**
* Klasa zawierajaca metody wirtualne oraz inne metody dotyczace dzialek z kategorii Grunty, dziedziczy po klasie Bazowa.
* @param stan_gruntu zawiera stan gruntu;
* @param uzbrojenie;
**/

class Grunty :
    public Bazowa
{
protected:
    int stan_gruntu;
    int uzbrojenie;
public:
    Grunty(string miasto, string ulica, string numer, bool czygotowe, int powierzchnia, int stan_gruntu, int uzbrojenie) :
        Bazowa(miasto, ulica, numer, czygotowe, powierzchnia), stan_gruntu(stan_gruntu), uzbrojenie(uzbrojenie) {};
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

