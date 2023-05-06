#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include<list>
#include<regex>
using namespace std;

/**
* Klasa wirtualna zawierajaca 9 metod wirtualnych wywolywanych w programie.
* @param miasto;
* @param ulica;
* @param numer;
* @param czygotowe zawierajace stan gotowosci wyceny;
* @param powierzchnia;
**/

class Bazowa
{
protected:
	string miasto;
	string ulica;
	string numer;
	bool czygotowe;
	int powierzchnia;
public:
	Bazowa(string miasto, string ulica, string numer, bool czygotowe, int powierzchnia)
		: miasto(miasto), ulica(ulica), numer(numer), czygotowe(czygotowe), powierzchnia(powierzchnia) {}
	virtual void wyswietOpis() = 0;
	virtual void zapiszOpis(fstream& plik) = 0;
	virtual void zapiszOpis2(ofstream& plik) = 0;
	virtual string miastoWyc() = 0; 
	virtual string ulicaWyc() = 0;
	virtual string numerWyc() = 0;
	virtual bool czygotoweWyc() = 0;
	virtual int powWyc() = 0;
	virtual string zamienBool() = 0;

 
};

