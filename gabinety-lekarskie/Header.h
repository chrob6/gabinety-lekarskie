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

