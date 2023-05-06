#include "Rolne.h"

/**
* Metoda wyswietlajaca opis dla elementow konkretnej klasy.
**/
void Rolne::wyswietOpis() {

	cout << "Rolne " << "Gotowosc wyceny: " << zamienBool() << " Adres: " << miastoWyc() << " " << ulicaWyc() << " " << numerWyc() << " Powierzchnia w metrach kwadratowych: " << powWyc() << " Stan gruntu: " << zamienstan() << " Uzbrojenie: " << zamienUzbr() << " " << endl;
}

/**
* Metoda zapisajaca opis obiektu konkretnej klasy do pliku w celu odczytu przez program.
**/
void Rolne::zapiszOpis(fstream& plik) {
	plik << "-Rolne-" << czygotoweWyc() << "-" << miastoWyc() << "-" << ulicaWyc() << "-" << numerWyc() << "-" << powWyc() << "-" << stan_gruntuWyc() << "-" << uzbrojenieWyc() << endl;
}

/**
* Metoda zapisajaca opis obiektu konkretnej klasy do pliku w celu odczytu przez uzytkownika.
**/
void Rolne::zapiszOpis2(ofstream& plik) {

	plik << "Rolna " <<  " Gotowosc wyceny: " << zamienBool() << " Adres: " << miastoWyc() << " " << ulicaWyc() << " " << numerWyc() << " Powierzchnia w metrach kwadratowych: " << powWyc() << " Stan gruntu: " << zamienstan() << " Uzbrojenie: " << zamienUzbr() << " " << endl;

}

/**
* Metoda zwracaja zmienna czygotowe.
**/
bool Rolne::czygotoweWyc() {
	return czygotowe;
}

/**
* Metoda zwracaja zmienna miasto.
**/
string Rolne::miastoWyc() {
	return miasto;
}

/**
* Metoda zwracaja zmienna ulica.
**/
string Rolne::ulicaWyc() {
	return ulica;
}

/**
* Metoda zwracaja zmienna numer.
**/
string Rolne::numerWyc() {
	return numer;
}

/**
* Metoda zwracaja zmienna powierzchnia.
**/
int Rolne::powWyc() {
	return powierzchnia;
}

/**
* Metoda zwracaja zmienna stan_gruntu.
**/
int Rolne::stan_gruntuWyc() {
	return stan_gruntu;
}

/**
* Metoda zwracaja zmienna uzbrojenie.
**/
int Rolne::uzbrojenieWyc() {
	return uzbrojenie;
}

/**
* Metoda zamieniajaca zmienna czygotowe na jej wartosc tekstowa true=TAK, false=NIE w celu przejrzystego wyswietlania dla uzytkownika.
**/
string Rolne::zamienBool() {
	string stan;
	if (czygotoweWyc() == 0)
	{
		stan = "NIE";
	}
	else { stan = "TAK"; }
	return stan;
}

/**
* Metoda zamieniajaca zmienna stan_gruntu/stan_tech na jej wartosc tekstowa w celu przejrzystego wyswietlania dla uzytkownika.
**/
string Rolne::zamienstan() {
	string stan;
	if (stan_gruntuWyc() == 1) { stan = "zly"; }
	if (stan_gruntuWyc() == 2) { stan = "sredni"; }
	if (stan_gruntuWyc() == 3) { stan = "dobry"; }
	if (stan_gruntuWyc() == 4) { stan = "bardzo dobry"; }
	if (stan_gruntuWyc() < 1 || stan_gruntuWyc() > 4) { stan = "niepoprawna dana w bazie"; }
	return stan;
}

/**
* Metoda zamieniajaca zmienna uzbrojenie na jej wartosc tekstowa w celu przejrzystego wyswietlania dla uzytkownika.
**/
string Rolne::zamienUzbr() {
	string stan;
	if (uzbrojenieWyc() == 1) { stan = "brak"; }
	if (uzbrojenieWyc() == 2) { stan = "czesciowe"; }
	if (uzbrojenieWyc() == 3) { stan = "podstawowe"; }
	if (uzbrojenieWyc() == 4) { stan = "pelne"; }
	if (uzbrojenieWyc() < 1 || uzbrojenieWyc() > 4) { stan = "niepoprawna dana w bazie"; }
	return stan;
}