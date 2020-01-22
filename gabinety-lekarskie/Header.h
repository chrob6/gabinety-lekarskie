#pragma once
#include <string>
#include <iostream>
#include "objectsclass.h"
#include <fstream>


// 

using namespace std;

class Osoba {
public:
	string Imie;
	string Nazwisko;
	string adres;
	int nr_tel;

	Osoba(string Im, string Naz, string adr, int nr_t)
	:Imie(Im),
		Nazwisko(Naz),
			adres(adr),
				nr_tel(nr_t) { }

	Osoba():Imie("Jan"),Nazwisko("Nowak"),adres("brak"),nr_tel(0) {
	}

};


class Pacjent : public Osoba {


public:
	int pesel;
	int karta_pacjenta;

	Pacjent(string Im, string Naz, string adr, int nr_t, int pesel, int k_p)
		: Osoba(Im, Naz, adr, nr_t),
		pesel(pesel),
		karta_pacjenta(k_p)
	{}
	Pacjent() :Osoba(), pesel(111),karta_pacjenta(0){}
	~Pacjent() {
		cout << "Pacjent usuniêty" << endl;
	}

	void Zarejestruj(int i) {

		fstream file;
		file.open("bazapacjentow.txt", ios::out | ios::app);
		file << pesel << "\t";
		file << i << '\t';
		file << Imie << "\t";
		file << Nazwisko << "\t";
		file << adres << "\t";
		file << nr_tel << endl;
		file.close();
		KartaPacjenta nowa_karta(i, "opis");							//Baza kart pacjenta
		fstream kp_baza;
		kp_baza.open("bazakart_pacj.txt", ios::out | ios::app);
		kp_baza << nowa_karta.id_karty << "\t";
		kp_baza << nowa_karta.opis << endl;
		kp_baza.close();
	}

	void logowanie() {




	}

	bool zaplac_za_wizyte(int cena) {
		int kwota;
		
		cout << "Kwota do zaplaty: " << cena << endl;
		cin >> kwota;
		if (kwota == cena) {
			return true;
		}
		return false;
	}

};

class Lekarz : public Osoba {
	int id_lekarza;
	int nr_gabinetu;
	string specjalizacja;

	Lekarz(string Im, string Naz, string adr, int nr_t, int id_l, int nr_g, string spec)
		: Osoba(Im, Naz, adr, nr_t), 
		id_lekarza(id_l), 
			nr_gabinetu(nr_g), 
				specjalizacja(spec){}
	~Lekarz() {
		cout << "Lekarz usuniêty" << endl;
	}

	void Ustaw_terminy() {
		Harmonogram Harm_lek(id_lekarza);
		fstream ter_baza;
		ter_baza.open("baza_Harm.txt", ios::out | ios::app);
		ter_baza << Harm_lek;
		ter_baza.close();
		//return 0;
	}

	void Wypisz_recepte() {
		string linia;
		int id_p;
		cin >> id_p;
		Recepta* nowa_recepta = new Recepta;
		fstream baza_pacj;
		baza_pacj.open("baza_recept.txt", ios::in | ios::app);
		if (baza_pacj.good() == true)
		{													//Pszeszukiwanie pliku
			while (!baza_pacj.eof())
			{
				getline(baza_pacj, linia, '\n');

				if (to_string(id_p) == linia) {			//jezeli pesel sie zgadza to wyswietl 
					baza_pacj.close();
					//Recepta nowa_recepta();
					fstream Rec_baza;
					Rec_baza.open("baza_recept.txt", ios::out | ios::app);
					cin >> nowa_recepta->id;
					Rec_baza << nowa_recepta->id << endl;

					nowa_recepta->id_lek = id_lekarza;
					Rec_baza << nowa_recepta->id_lek << endl;

					nowa_recepta->id_pacj = id_p;
					Rec_baza << nowa_recepta->id_pacj << endl;

					cin >> nowa_recepta->przepisane_lekarstwo;
					Rec_baza << nowa_recepta->przepisane_lekarstwo << endl;

					//nowa_recepta->data_wystawienia;
					Rec_baza << nowa_recepta->data_wystawienia << endl;
					Rec_baza.close();
					break;
				}

			}

		}

	}

	void Sprawdz_Karte() {
		string linia, decyzja;
		int id_p;
		cin >> id_p;
		fstream baza_kart;
		baza_kart.open("bazakart_pacj.txt", ios::in | ios::app | ios::out);
		if (baza_kart.good() == true)
		{													//Pszeszukiwanie pliku
			while (!baza_kart.eof())
			{
				getline(baza_kart, linia, '\n');

				if (to_string(id_p) == linia) {			//jezeli pesel sie zgadza to wyswietl 
					getline(baza_kart, linia, '\n');
					cout << linia << endl;
					cout << "Czy chcesz zmieniæ opis ?(male litery)" << endl;
					cin >> decyzja;
					if (decyzja == "tak") {
						cin >> linia;
						baza_kart << linia
					}
					baza_kart.close();
					break;
				}

			}

		}
	}
};

class Pielegniarka: public Osoba {

	Pielegniarka(string Im, string Naz, string adr, int nr_t)
		: Osoba(Im, Naz, adr,nr_t){}

};



class Obsluga: public Osoba {
public:
	/*
	Obsluga(string Im, string Naz, string adr, int nr_t)
		: Osoba(Im, Naz, adr, nr_t) {}
		*/


	void potwierdzenie_platnosci(bool iftrue) {
		if (iftrue) {
			cout << "potwierdzam zaplate" << endl;
			return;
		}
		else cout << "zla kwota";



	}



	


};

