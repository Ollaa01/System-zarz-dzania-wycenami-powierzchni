#pragma once
#include "Bazowa.h"

/**
* Klasa zawierajaca metody wirtualne oraz inne metody dotyczace dzialek z kategorii Lokale, dziedziczy po klasie Bazowa.
* @param stan_tech zawiera stan techniczny;
* @param kondygancja;
**/
class Lokale :
    public Bazowa
{
protected:
    int stan_tech;
    int kondygnacja;
public:
    Lokale(string miasto, string ulica, string numer, bool czygotowe, int powierzchnia, int stan_tech, int kondygnacja) :
        Bazowa(miasto, ulica, numer, czygotowe, powierzchnia), stan_tech(stan_tech), kondygnacja(kondygnacja) {};
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

