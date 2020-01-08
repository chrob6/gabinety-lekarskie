#pragma once
#include <string>
#include <iostream>

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
	int pesel;
	int nr_karty_pacjenta;

	Pacjent(string Im, string Naz, string adr, int nr_t , int pesel,int nr_k)
		: Osoba( Im, Naz, adr, nr_t), 
			pesel(pesel),
				nr_karty_pacjenta(nr_k) 
			{}
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