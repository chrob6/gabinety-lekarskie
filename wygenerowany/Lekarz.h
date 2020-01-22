#ifndef LEKARZ_H
#define LEKARZ_H

class Lekarz : Osoba {

public:
	int id_lekarza;
	int nr_gabinetu;
private:
	string imie;
	string nazwisko;
	string specjalizacja;

public:
	void wybierz_termin();

	void wypisz_recepte();

	void dodaj_termin_do_harmonogramu();

	Karta_pacjenta pobierz_dane_pacjenta();
};

#endif
