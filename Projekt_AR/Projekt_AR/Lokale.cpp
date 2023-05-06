#include "Lokale.h"

/**
* Metoda wyswietlajaca opis dla elementow konkretnej klasy.
**/
void Lokale::wyswietOpis() {

	cout << "Lokale " << " Gotowosc wyceny: " << zamienBool() << " Adres: " << miastoWyc() << " " << ulicaWyc() << " " << numerWyc() << " Powierzchnia w metrach kwadratowych: " << powWyc() << " Stan techniczny: " << zamienstan() << " Kondygnacja:  " << kondygnacjaWyc() << " " << endl;
}

/**
* Metoda zapisajaca opis obiektu konkretnej klasy do pliku w celu odczytu przez program.
**/
void Lokale::zapiszOpis(fstream& plik) {
	plik << "-Lokale-" << czygotoweWyc() << "-" << miastoWyc() << "-" << ulicaWyc() << "-" << numerWyc() << "-" << powWyc() << "-" << stan_techWyc() << "-" << kondygnacjaWyc() << endl;
}

/**
* Metoda zapisajaca opis obiektu konkretnej klasy do pliku w celu odczytu przez uzytkownika.
**/
void Lokale::zapiszOpis2(ofstream& plik) {

	plik << "Lokal " << "Gotowosc wyceny: " << zamienBool() << " Adres: " << miastoWyc() << " " << ulicaWyc() << " " << numerWyc() << " Powierzchnia w metrach kwadratowych: " << powWyc() << " Stan techniczny: " << zamienstan() << " Kondygnacja:  " << kondygnacjaWyc() << " " << endl;

}

/**
* Metoda zwracaja zmienna czygotowe.
**/
bool Lokale::czygotoweWyc() {
	return czygotowe;
}

/**
* Metoda zwracaja zmienna miasto.
**/
string Lokale::miastoWyc() {
	return miasto;
}

/**
* Metoda zwracaja zmienna ulica.
**/
string Lokale::ulicaWyc() {
	return ulica;
}

/**
* Metoda zwracaja zmienna numer.
**/
string Lokale::numerWyc() {
	return numer;
}

/**
* Metoda zwracaja zmienna powierzchnia.
**/
int Lokale::powWyc() {
	return powierzchnia;
}

/**
* Metoda zwracaja zmienna stan_tech.
**/
int Lokale::stan_techWyc() {
	return stan_tech;
}

/**
* Metoda zwracaja zmienna kondygnacja.
**/
int Lokale::kondygnacjaWyc() {
	return kondygnacja;
}

/**
* Metoda zamieniajaca zmienna czygotowe na jej wartosc tekstowa true=TAK, false=NIE w celu przejrzystego wyswietlania dla uzytkownika.
**/
string Lokale::zamienBool() {
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
string Lokale::zamienstan() {
	string stan;
	if (stan_techWyc() == 1) { stan = "zly"; }
	if (stan_techWyc() == 2) { stan = "sredni"; }
	if (stan_techWyc() == 3) { stan = "dobry"; }
	if (stan_techWyc() == 4) { stan = "bardzo dobry"; }
	if (stan_techWyc() < 1 || stan_techWyc() > 4) { stan = "niepoprawna dana w bazie"; }
	return stan;
}