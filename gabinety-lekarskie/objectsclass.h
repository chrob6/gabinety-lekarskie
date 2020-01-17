#pragma once
#include "string"
#include "Header.h"

using namespace std;

class Data {
public:
	int dzien;
	int miesiac;
	int rok;
	//int godzina;
	//int minuta;
	Data() {
		dzien = 1;
		miesiac = 1;
		rok = 2000;
		//godzina = 0;
		//minuta = 0;
	}
	//Data(int d,int mi, int r):dzien(d),miesiac(mi),rok(r){} 
};


class KartaPacjenta {
public:
	int id_karty;
	string opis;
	//Data data_wizyty;
	//int il_wizyt;
	

	KartaPacjenta(int id_k, string o):id_karty(id_k),opis(o) {
	}
};

class Recepta {
	int id;
	string przepisane_lekarstwo;
	//Pacjent pacjent;
	Data data_wystawienia;
	Recepta(int i, string prz_lek, Data d):id(i),przepisane_lekarstwo(prz_lek){
		data_wystawienia = d;
	}
};

class Platnosc {
public:
	bool typ_platnosci;
	double kwota;

	Platnosc(bool pl, double kw):typ_platnosci(pl),kwota(kw){}
};

class Ubezpieczenie : public Platnosc {
	int nr_ubezp;
	//Pacjent osoba_ubez;
	Ubezpieczenie(bool pl,double kw, int nr):Platnosc(pl,kw),nr_ubezp(nr){}
};

class Prywatne : public Platnosc {
	//int kwota;
	Prywatne(bool pl, double kw) :Platnosc(pl, kw){}
};

class Paragon {
	int kwota;
	Data data;
	Paragon(int kw, Data d):kwota(kw),data(d) {
	}
};

class Harmonogram {
	Data termin;

};

class wizyta {
	//Pacjent pacjent;

};