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
	Recepta(int i, string prz_lek):id(i),przepisane_lekarstwo(prz_lek),data_wystawienia(){
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
	Data termin[10];
	static int i;
	Harmonogram(Data d) {
		termin[i] = d;
		i++;
		if (i == 9)i = 1;
	}

};
//int Harmonogram::i = 0;

class Wizyta {
	int id_kart_pacj;
	int id_lekarz;
	Data data_wizyty;

	Wizyta(int id,int l):id_kart_pacj(id),id_lekarz(l),data_wizyty(){
	}

};