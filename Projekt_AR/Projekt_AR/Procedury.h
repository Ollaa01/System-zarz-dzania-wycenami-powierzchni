#pragma once
#include "Bazowa.h"
#include "Budowlane.h"
#include "Grunty.h"
#include "Lokale.h"
#include "Mieszkalne.h"
#include "Rolne.h"
#include <ranges>
#include<filesystem>

namespace fs = std::filesystem;
using namespace std;

/** Klasa zawierajaca elementy klasy Bazowa, sluzy do dodawania, wyswietlania, usuwania wpisow.
* @param lista zawiera elementy klasy Bazowa.
**/
class Procedury
{
	vector<Bazowa* > lista;
public:
	~Procedury();
	void dodaj();
	void odczyt();
	void zapisz();
	void wyswietl();
	void usun();
	void sprawdzRegex(string& dana);
	void sprawdzRegex2(string& dana);
	void powierzchniaSprawdz();
	void zapisz2();
	void sprawdz_int(string str, int& x);
};

