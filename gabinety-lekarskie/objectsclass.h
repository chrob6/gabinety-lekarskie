#pragma once
#include "string"
#include "Header.h"

using namespace std;

class Data {
public:
	int dzien;
	int miesiac;
	int rok;
	int godzina;
	int minuta;
	Data() {
		cin >> dzien;
		cin >> miesiac;
		cin >> rok;
		cin >> godzina;
		cin >> minuta;
	}
	friend ostream& operator<<(ostream& os, const Data& dt);
};

ostream& operator<<(ostream& os, const Data& dt) {
	os << dt.dzien << "," << dt.miesiac << "," << dt.rok << " " << dt.godzina << ":" << dt.minuta;
	return os;
}


class KartaPacjenta {
public:
	int id_karty;
	string opis;
	//wizyta wizyta;
	//Data data_wizyty;
	int il_wizyt=0;
	
	KartaPacjenta(int id_k, string o):id_karty(id_k),opis(o) {	
		il_wizyt++;
	}
};
//int KartaPacjenta::il_wizyt = 0;

class Recepta {
public:
	int id;
	string przepisane_lekarstwo;
	//Pacjent pacjent;
	Data data_wystawienia;
	int id_pacj;
	int id_lek;
	//Data data_wystawienia;
	Recepta() :id(0), przepisane_lekarstwo("brak"), id_lek(0), id_pacj(0), data_wystawienia() {}
	Recepta(int i, string prz_lek, int id_p, int id_l) :id(i), przepisane_lekarstwo(prz_lek), data_wystawienia(), id_pacj(id_p), id_lek(id_l) {
		//data_wystawienia = d;
		//pacjent = pac;
	}
};

class Platnosc {
public:
	bool typ_platnosci;
	double kwota;

	Platnosc(bool pl, double kw):typ_platnosci(pl),kwota(kw){}
};


/*
class Ubezpieczenie : public Platnosc {
	int nr_ubezp;
	//Pacjent osoba_ubez;
	Ubezpieczenie(bool pl,double kw, int nr):Platnosc(pl,kw),nr_ubezp(nr){
	}
};

class Prywatne : public Platnosc {
	//double kwota;
	Prywatne(bool pl, double kw) :Platnosc(pl, kw){
	}
};
*/

class Paragon {
public:
	int kwota;

	Paragon(int kw) {
		kwota = kw;
	}

	void PrintParagon() {

		cout << "Paragon" << endl;
		cout << kwota << endl;
		cout << "1 stycznia";
	}
};

class Harmonogram {
public:
	int termin[5][2];
	int id;
	Harmonogram(int id_lek) {
		int j = 0;
		//int czas;
		for (int i = 0; i = 4; i++) {
			for (j; j = 1; j++) {
				cin >> termin[i][j];
			}
			j = 0;
		}
		id = id_lek;
	}
	friend ostream& operator<<(ostream& os, const Harmonogram& H);
};

ostream& operator<<(ostream& os, const Harmonogram& H) {
	os << H.id << endl;
	os << "poniedzia³ek" << H.termin[0][0] << "/" << H.termin[0][1] << endl;
	os << "Wtorek" << H.termin[1][0] << "/" << H.termin[1][1] << endl;
	os << "Œroda" << H.termin[2][0] << "/" << H.termin[2][1] << endl;
	os << "czwartekk" << H.termin[3][0] << "/" << H.termin[3][1] << endl;
	os << "piatek" << H.termin[4][0] << "/" << H.termin[4][1] << endl;
	return os;
}

class Wizyta {
public:
	int id_kart_pacj;
	int id_lekarz;
	Data data_wizyty;

	Wizyta(int id,int l):id_kart_pacj(id),id_lekarz(l),data_wizyty(){
	}

};