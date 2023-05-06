#pragma once
#include "Lokale.h"

/**
* Klasa zawierajaca metody wirtualne oraz inne metody dotyczace dzialek z kategorii Lokale, dziedziczy po klasie Lokale.
**/
class Mieszkalne :
    public Lokale
{
public:
    Mieszkalne(string miasto, string ulica, string numer, bool czygotowe, int powierzchnia, int stan_tech, int kondygnacja) :
        Lokale(miasto, ulica, numer, czygotowe, powierzchnia, stan_tech, kondygnacja) {};
	void wyswietOpis();
	void zapiszOpis(fstream& plik);
	void zapiszOpis2(ofstream& plik);
	string miastoWyc();
	string ulicaWyc();
	string numerWyc();
	bool czygotoweWyc();
	int powWyc();
	int stan_techWyc();
	int kondygnacjaWyc();
	string zamienBool();
	string zamienstan();
};

