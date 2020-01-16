#include <iostream>
#include <string>
#include <cstdlib>
#include "Header.h"
#include <fstream>
#include "objectsclass.h"



using namespace std;

void menu(int p) {

	if (p == 0) {
		// pacjent
		string imie, nazwisko, adres;
		int nr_tel, pesel, log;

		cout << "Logowanie jako pacjent" << endl;

		cout << "1.Rejestracja"<< endl;
		cout << "2.Logowanie" << endl;
		cin >> log;

		if (log == 1) {
			


			cout << "Pesel: ";
			cin >> pesel;

			cout << "Imie: ";
			cin >> imie;

			cout << "Nazwisko: ";
			cin >> nazwisko;

			cout << "Numer telefonu: ";
			cin >> nr_tel;

			cout << "Adres: ";
			cin >> adres;

			Pacjent nowy_pacjent(imie, nazwisko, adres, nr_tel, pesel);
			fstream file;
			file.open("bazapacjentow.txt", ios::out | ios::app);
			file << nowy_pacjent.pesel << endl;
			//file << nowy_pacjent.karta_pacjenta << endl;
			file << nowy_pacjent.Imie << "\t";
			file << nowy_pacjent.Nazwisko << "\t";
			file << nowy_pacjent.adres << "\t";
			file << nowy_pacjent.nr_tel << "\t";
			file.close();
		}
		else if (log == 2) {
			cin >> pesel;

		}

		cout << "1.Umow wizyte" << endl;
		cout << "2.Odwolaj wizyte wizyte" << endl;
		cout << "3.Zobacz Harmonogram" << endl;
	}
	else if (p == 1) {
		// lekarz
		cout << "Logowanie jako lekarz" << endl;
		cout << "1.Ustaw terminy przyjec" << endl;
		cout << "2.Wypisz recepte" << endl;
		cout << "3.Sprawdz karte pacjenta" << endl;
	}
	else if (p == 2) {
		// pielegiarka
		cout << "Logowanie jako pielegiarka" << endl;
		cout << "1.Zarejestruj pacjenta" << endl;
		cout << "2.Sprawdz karte pacjenta" << endl;
		cout << "3.Zobacz harmonogram lekarza" << endl;
	}

}

int main(){

	string login;
	int parametr;

	while (1) {

		cout << endl;
		cout << "Logowanie do systemu(male litery!):  ";
		cin >> login;


		if (login == "pacjent") {
			parametr = 0;
		}
		else if (login == "lekarz") {
			parametr = 1;
		}
		else if (login == "pielegiarka") {
			parametr = 2;
		}
		else {
			cout << "zly login" << endl;
			parametr = -1;
		}

		menu(parametr);

	}
	system("pause");
}