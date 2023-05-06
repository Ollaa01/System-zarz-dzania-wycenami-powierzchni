
#include <iostream>
#include <list>
#include <string>
#include <iostream>
#include <windows.h>
#include <thread>
#include "Procedury.h"
#include "Budowlane.h"
#include "Rolne.h"
#include "Mieszkalne.h"

namespace fs = std::filesystem;

/**
* Funckja sluzaca do liczenia i wyswietlania ile trwala sesja.
**/
void licznik(bool& zmienna, int& liczba) {

    while (zmienna == true) {
        Sleep(1000);
        liczba++;
    }
    cout << "Sesja trwala " << liczba << " sekund";
}

/**
* Funkcja posrednio sluzaca do liczenia i wyswietlania ile trwala sesja. Przekazuje i uzywa thread.
**/
void stop(thread& i, bool& zmienna) {
    zmienna = false;
    i.join();
}

int main()
{
    int i = 0;
	class Procedury* procedury = new Procedury();
	procedury->odczyt();

    bool zmienna = true;
    string wybor1;
    int wybor2;

    thread licz(licznik, ref(zmienna), ref(i));

    while (true) {
        try {
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << "Baza dzialek\n";
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cout << " 1 - Dodaj nowa dzialke" << endl;
            cout << " 2 - Wyswietl" << endl;
            cout << " 3 - Zapisz aktualna baze do pliku" << endl;
            cout << " 4 - Usun dzialke" << endl;
            cout << " 5 - Wyjdz" << endl;
            cout << " 6 - Zapisz aktualna baze do druku: " << endl;
            cout << " 7 - Wyswietl od najmniejszej powierzchni: " << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
            cin >> wybor2;
            switch (wybor2) {
            case 1:
                procedury->dodaj();
                break;
            case 2:
                procedury->wyswietl();
                break;
            case 3:
                procedury->zapisz();
                break;
            case 4:
                procedury->usun();
                break;
            case 5:
                stop(licz, zmienna);
                return 0;
            case 6:
                procedury->zapisz2();
                break;
            case 7:
                procedury->powierzchniaSprawdz();
                break;

            }
            cout << "Nacisnij 0 aby wrocic do pola wyboru: ";
            cin >> wybor1;
            system("cls");
        }
        catch (const out_of_range& e) {
            cout << "Zly indeks: " << e.what() << endl;
        }
    }
    delete procedury;
    return 0;

}
