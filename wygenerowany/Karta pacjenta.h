#ifndef KARTA PACJENTA_H
#define KARTA PACJENTA_H

class Karta_pacjenta {

private:
	int id_karty;
	string opis;
	std::vector<Data> data_wizyty;
	int il_wizyt;
	int miesiac;
};

#endif
