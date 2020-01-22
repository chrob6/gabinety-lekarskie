#ifndef PACJENT_H
#define PACJENT_H

class Pacjent : Osoba {

private:
	int pesel;
	int nr_karty_pacjenta;

public:
	boolean umow_wizyte();

	void odwolaj_wizyte();

	void Dodaj();

	boolean zaplac_za_wizyte();
};

#endif
