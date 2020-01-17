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
		string dane;
		cout << "Logowanie jako pacjent" << endl;

		cout << "1.Rejestracja"<< endl;
		cout << "2.Logowanie" << endl;
		cin >> log;

		if (log == 1) {
			fstream nr_k_p;
			int i=0;
			
			nr_k_p.open("bazapacjentow.txt", ios::in | ios::app);
			if (nr_k_p.good() == true) {
				while (!nr_k_p.eof())
				{	getline(nr_k_p, dane);
					i++;
				}
				nr_k_p.close();
			}
			cout << "Twoj ID to: " << i << endl;

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

			Pacjent nowy_pacjent(imie, nazwisko, adres, nr_tel, pesel, i);
			fstream file;
			file.open("bazapacjentow.txt", ios::out | ios::app);
			file << nowy_pacjent.pesel << "\t";
			file << nowy_pacjent.karta_pacjenta << '\t';
			file << nowy_pacjent.Imie << "\t";
			file << nowy_pacjent.Nazwisko << "\t";
			file << nowy_pacjent.adres << "\t";
			file << nowy_pacjent.nr_tel << endl;
			file.close();
			KartaPacjenta nowa_karta(i, " ");							//Baza kart pacjenta
			fstream kp_baza;
			kp_baza.open("bazakart_pacj.txt", ios::out | ios::app);
			kp_baza << nowa_karta.id_karty << "\t";
			kp_baza << nowa_karta.opis << endl;
			kp_baza.close();
		}
		else if (log == 2) {
			cin >> pesel;
			string linia,pesel2;
			fstream file2;
			int poz1,poz2,dl;
			poz1 = 4;
			Pacjent* ist_pacjent = new Pacjent;					//Aktualnie zalogowany pacjent
			file2.open("bazapacjentow.txt", ios::in | ios::app);
			if (file2.good() == true)
			{													//Pszeszukiwanie pliku
				while (!file2.eof())
				{	getline(file2, linia,'\n');
					pesel2 = linia.substr(0, 3);
					dane = linia.substr(poz1);
					
					if (pesel2 == to_string(pesel)) {			//jezeli pesel sie zgadza to wyswietl 
						pesel = stoi(pesel2);
						ist_pacjent->pesel = pesel;				//przypisanie peselu
						cout << dane << endl;
						//poz2 = dane.find('\t');
						//dl = poz2 - poz1;
						//linia = dane.substr(poz2, dl);
						//cout << dl << poz1 << poz2 << endl;		//Trzeba z reszty stringa wyciac pozostale pola!!!
						break;
					}
					
				}
				//cout << "Pacjenta nie znaleziono" << endl;
				file2.close();
				
			}
		}

		cout << "1.Umow wizyte" << endl;
		cout << "2.Odwolaj wizyte" << endl;
		cout << "3.Zobacz Harmonogram" << endl;
		cin >> log;
		if (log == 1) {
			
		}
		else if (log == 2) {

		}
		else if(log == 3) {

		}
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