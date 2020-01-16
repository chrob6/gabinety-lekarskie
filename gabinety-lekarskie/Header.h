#pragma once
#include <string>
#include <iostream>
#include "objectsclass.h"

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

};


class Pacjent : public Osoba {


public:
	int pesel;
	int karta_pacjenta;

	Pacjent(string Im, string Naz, string adr, int nr_t, int pesel)
		: Osoba(Im, Naz, adr, nr_t),
		pesel(pesel)
			{
	karta_pacjenta = 1;
	}
	~Pacjent() {
		cout << "Pacjent usuniêty" << endl;
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

	Obsluga(string Im, string Naz, string adr, int nr_t)
		: Osoba(Im, Naz, adr, nr_t) {}

};

