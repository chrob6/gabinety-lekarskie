#pragma once
#include "string"
#include "Header.h"

using namespace std;

class Data {
	int dzien;
	int rok;
	int godzina;
	int minuta;
};


class KartaPacjenta {
	int id_karty;
	string opis;
	Data data_wizyty;
	int il_wizyt;
	int miesiac;
};

class Recepta {
	int id;
	string przepisane_lekarstwo;
	Pacjent pacjnet;
	Data data_wystawienia;
};

class Platnosc {
	bool typ_platnosci;
	double kwota;
};

class Ubezpieczenie : public Platnosc {
	int nr_ubezp;
	Pacjent osoba_ubez;
};

class Prywatne : public Platnosc {
	int kwota;
};

class Paragon {
	int kwota;
	Data data;
};

class Harmonogram {
	Data termin;

};

class wizyta {
	Pacjent pacjent;
};