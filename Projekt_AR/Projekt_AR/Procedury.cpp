#include "Procedury.h"

/**
* Metoda sprawdzajaca czy wprowadzona dana jest typu int.
**/
void Procedury::sprawdz_int(string str, int& x) {
	try {
		x = stoi(str);
	}
	catch (exception& e) { cout << "Podaj prawidlowy typ: "; getline(cin, str); sprawdz_int(str, x); }
}

bool x = false;
/**
* Metoda sprawdzajaca czy wprowadzona dana zaczyna sie duza litera, uzywajac regex.
**/
void Procedury::sprawdzRegex(string& dana) {
	regex nazwa("[A-Z]+[a-zA-Z. ]*");
	while (x == false)
	{
		if (regex_match(dana, nazwa)) {
			x = true;
		}
		else {
			cout << "Podaj prawidlowy typ: "; getline(cin, dana); sprawdzRegex(dana); 
		};
	}
}

/**
* Metoda sprawdzajaca czy wprowadzona dana miesci sie w przedziale(1-4), uzywajac regex.
**/
void Procedury::sprawdzRegex2(string& dana) {
	regex nazwa("^([1-4]{1})");
		if (regex_match(dana, nazwa)) {
		}
		else {
			cout << "Podaj prawidlowy typ: "; getline(cin, dana); sprawdzRegex2(dana);
		};
}

/**
* Metoda w sposob interaktywny dodaje z uzytkownikiem nowe dzialki do bazy. Najpierw pyta sie o konkretne dane a pozniej dodaje do wektora "lista"
* przechowujacego obiekty klas konkretny obiekt.
**/
void Procedury::dodaj() {
	string pomocnicza;
	string miasto;
	string ulica;
	string numer;
	bool czygotowe;
	int powierzchnia;
	int stan_tech;
	int kondygnacja;
	int stan_gruntu;
	int uzbrojenie;
	int wybor;

	cout << "Jaki typ chcesz dodac(0-Grunty, 1-Budowlane, 2-Rolne, 3-Lokale, 4-Mieszkalne) ";
	cin >> wybor;

	cout << "Podaj miasto: ";
	cin.ignore();
	getline(cin, pomocnicza);
	sprawdzRegex(pomocnicza);
	miasto = pomocnicza;
	x = false;
	cout << "Podaj ulice: ";
	getline(cin, pomocnicza);
	sprawdzRegex(pomocnicza);
	ulica = pomocnicza;
	x = false;
	cout << "Podaj numer: ";
	getline(cin, numer);
	cout << "Czy wycena jest gotowa? (1-tak, 0-nie): ";
	cin >> czygotowe;
	cout << "Podaj powierzchnie: ";
	cin.ignore();
	getline(cin, pomocnicza);
	sprawdz_int(pomocnicza, powierzchnia);


	if (wybor == 0) {
		cout << "Podaj stan gruntu (1-zly, 2-sredni, 3-dobry, 4-bardzo dobry): ";
		getline(cin, pomocnicza);
		sprawdzRegex2(pomocnicza);
		stan_gruntu = stoi(pomocnicza);
		cout << "Podaj uzbrojenie (1-brak, 2-czesciowe, 3-podstawowe, 4-pelne): ";
		getline(cin, pomocnicza);
		sprawdzRegex2(pomocnicza);
		uzbrojenie= stoi(pomocnicza);
		auto* nowy = new Grunty(miasto, ulica, numer, czygotowe, powierzchnia, stan_gruntu, uzbrojenie);
		lista.push_back(nowy);
	}
	if (wybor == 1) {
		cout << "Podaj stan gruntu (1-zly, 2-sredni, 3-dobry, 4-bardzo dobry): ";
		getline(cin, pomocnicza);
		sprawdzRegex2(pomocnicza);
		stan_gruntu = stoi(pomocnicza);
		cout << "Podaj uzbrojenie (1-brak, 2-czesciowe, 3-podstawowe, 4-pelne): ";
		getline(cin, pomocnicza);
		sprawdzRegex2(pomocnicza);
		uzbrojenie = stoi(pomocnicza);
		auto* nowy = new Budowlane(miasto, ulica, numer, czygotowe, powierzchnia, stan_gruntu, uzbrojenie);
		lista.push_back(nowy);
	}
	if (wybor == 2) {
		cout << "Podaj stan gruntu (1-zly, 2-sredni, 3-dobry, 4-bardzo dobry): ";
		getline(cin, pomocnicza);
		sprawdzRegex2(pomocnicza);
		stan_gruntu = stoi(pomocnicza);
		cout << "Podaj uzbrojenie (1-brak, 2-czesciowe, 3-podstawowe, 4-pelne): ";
		getline(cin, pomocnicza);
		sprawdzRegex2(pomocnicza);
		uzbrojenie = stoi(pomocnicza);
		auto* nowy = new Rolne(miasto, ulica, numer, czygotowe, powierzchnia, stan_gruntu, uzbrojenie);
		lista.push_back(nowy);
	}
	if (wybor == 3) {
		cout << "Podaj stan techniczny (1-zly, 2-sredni, 3-dobry, 4-bardzo dobry):";
		getline(cin, pomocnicza);
		sprawdzRegex2(pomocnicza);
		stan_tech = stoi(pomocnicza);
        cout << "Podaj kondygnacje: ";
		cin >> kondygnacja;
		auto* nowy = new Lokale(miasto, ulica, numer, czygotowe, powierzchnia, stan_tech, kondygnacja);
		lista.push_back(nowy);
	}
	if (wybor == 4) {
		cout << "Podaj stan techniczny (1-zly, 2-sredni, 3-dobry, 4-bardzo dobry): ";
		getline(cin, pomocnicza);
		sprawdzRegex2(pomocnicza);
		stan_tech = stoi(pomocnicza);
		cout << "Podaj kondygnacje: ";
		cin >> kondygnacja;
		auto* nowy = new Mieszkalne(miasto, ulica, numer, czygotowe, powierzchnia, stan_tech, kondygnacja);
		lista.push_back(nowy);
	}

	cout << endl;
}

/**
* Metoda odczytuje dane i dodaje je do wektora "lista" przechowujacego obiekty klas.
**/
void Procedury::odczyt() {
	lista.clear();
	string wybor;
	string miasto;
	string ulica;
	string numer;
	bool czygotowe;
	int powierzchnia;
	int stan;
	int konUzbr;
	string linia;
	vector <string> el;

	ifstream plik;
	plik.open("baza.txt");
	while (!plik.eof()) {
		getline(plik, linia, '-');
		el.push_back(linia);
	}
	plik.close();


	for (vector<string> ::iterator it = (el.begin() + 1); it != el.end(); ++it)
	{
		wybor = (*it);
		++it;
		czygotowe = stoi((*it).c_str());
		++it;
		miasto = (*it);
		++it;
		ulica = (*it);
		++it;
		numer = (*it);
		++it;
		powierzchnia = atoi((*it).c_str());
		++it;
		stan = atoi((*it).c_str());
		++it;
		konUzbr = atoi((*it).c_str());
		if (wybor == "Grunty") {
			auto* nowy = new Grunty(miasto, ulica, numer, czygotowe, powierzchnia, stan, konUzbr);
			lista.push_back(nowy);
		}
		if (wybor == "Budowlane") {
			auto* nowy = new Budowlane(miasto, ulica, numer, czygotowe, powierzchnia, stan, konUzbr);
			lista.push_back(nowy);
		}
		if (wybor == "Rolne") {
			auto* nowy = new Rolne(miasto, ulica, numer, czygotowe, powierzchnia, stan, konUzbr);
			lista.push_back(nowy);
		}
		if (wybor == "Lokale") {
			auto* nowy = new Lokale(miasto, ulica, numer, czygotowe, powierzchnia, stan, konUzbr);
			lista.push_back(nowy);
		}
		if (wybor == "Mieszkalne") {
			auto* nowy = new Mieszkalne(miasto, ulica, numer, czygotowe, powierzchnia, stan, konUzbr);
			lista.push_back(nowy);
		}

	}

	el.clear();
}

/**
* Destruktor klasy Procedury.
**/
Procedury::~Procedury() {
	for (auto& bazowa : lista) delete bazowa;
	lista.clear();
}

/**
* Metoda sluzaca do wyswietlania obiektow wektora przechowujacego obiekty klas, wewnatrz wywoluje wirtualna funkcje dla kazdego obiektu.
**/
void Procedury::wyswietl() {
	for (auto it = lista.begin(); it != lista.end(); ++it) {
		(*it)->wyswietOpis();
	}
}

/**
* Metoda sluzaca do zapisywania do pliku w celu pozniejszego odczytu przez program
* obiektow wektora przechowujacego obiekty klas, wewnatrz wywoluje wirtualna funkcje dla kazdego obiektu.
**/
void Procedury::zapisz() {
	fstream("baza.txt", std::ios::trunc | std::ios::out).flush();
	fstream plik;
	plik.open("baza.txt");
	for (auto it = lista.begin(); it != lista.end(); ++it) {
		(*it)->zapiszOpis(plik);
	}
	plik.close();
}

/**
* Metoda sluzaca do zapisywania do pliku w celu odczytu przez uzytkownika obiektow wektora przechowujacego obiekty klas,
* wewnatrz wywoluje wirtualna funkcje dla kazdego obiektu. Uzywa filesystem.
**/
void Procedury::zapisz2() {
	string nazwaP;
	cout << "Podaj nazwe pliku: ";
	cin.ignore();
	getline(cin, nazwaP);
	nazwaP = nazwaP + ".txt";
	fs::path nazwa{ "Zapisy" };
	fs::create_directory(nazwa);
	nazwa.append(nazwaP);
	ofstream plik(nazwa);
	for (auto it = lista.begin(); it != lista.end(); ++it) {
		(*it)->zapiszOpis2(plik);
	}
	plik.close();
	
}

/**
* Metoda sluzaca do usuwania dzialek z wektora w sposob interaktywny z uzytkownikiem. 
**/
void Procedury::usun() {
	string miastoU;
	string numerU;
	string ulicaU;

	cout << "Podaj miasto do usuniecia: ";
	cin >> miastoU;
	cout << "Podaj ulice: ";
	cin >> ulicaU;
	cout << "Podaj numer do usuniecia: ";
	cin >> numerU;


	for (auto it = lista.begin(); it != lista.end(); ++it) {
		if ((*it)->miastoWyc() == miastoU && (*it)->ulicaWyc() == ulicaU && (*it)->numerWyc() == numerU) {
			(*it)->wyswietOpis();
			it = lista.erase(it);
			break;
		}
	}

}

/**
* Funkcja sluzaca do usuwania duplikatow w wektorze.
**/
void remove(vector<int>& v)
{
	auto end = v.end();
	for (auto it = v.begin(); it != end; ++it) {
		end = remove(it + 1, end, *it);
	}

	v.erase(end, v.end());
}

/**
* Metoda sluzaca do sortowania dzialek wzgledem ich powierchni. Uzywa ranges.
**/
void Procedury::powierzchniaSprawdz() {


	vector <int> powi;
	for (auto it = lista.begin(); it != lista.end(); ++it) {
		powi.push_back((*it)->powWyc());
	}

	remove(powi);
	ranges::sort(powi);

		for (int i = 0; i < powi.size(); ++i) {
			for (auto it = lista.begin(); it != lista.end(); ++it) {
				if ((*it)->powWyc() == powi[i]) { (*it)->wyswietOpis(); }
			}
		
		}

	powi.clear();
}