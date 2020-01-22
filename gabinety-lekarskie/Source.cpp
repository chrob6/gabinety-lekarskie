#include <iostream>
#include <string>
#include <cstdlib>
#include "Header.h"
#include <fstream>
#include "objectsclass.h"


//int KartaPacjenta::il_wizyt = 0;
//int Harmonogram::i = 0;

using namespace std;

void menu(int p) {

	if (p == 0) {
		// pacjent
		//string imie, nazwisko, adres;
		int log;
		//int nr_tel, pesel, log;
		string dane;
		Pacjent* ist_pacjent = new Pacjent;


		cout << "Logowanie jako pacjent" << endl;

		cout << "1.Rejestracja"<< endl;
		cout << "2.Logowanie" << endl;
		cin >> log;

		if (log == 1) {
			fstream nr_k_p;
			int i=0;
			
			nr_k_p.open("bazapacjentow.txt", ios::in | ios::app);
			if (nr_k_p.good() == true) {
				while (!nr_k_p.eof())
				{	getline(nr_k_p, dane);
					i++;
				}
				nr_k_p.close();
			}
			cout << "Twoj ID to: " << i << endl;

			cout << "Pesel: ";
			cin >> ist_pacjent->pesel;

			cout << "Imie: ";
			cin >> ist_pacjent->Imie;

			cout << "Nazwisko: ";
			cin >> ist_pacjent->Nazwisko;

			cout << "Numer telefonu: ";
			cin >> ist_pacjent->nr_tel;

			cout << "Adres: ";
			cin >> ist_pacjent->adres;

			//Pacjent nowy_pacjent(imie, nazwisko, adres, nr_tel, pesel, i);
			ist_pacjent->Zarejestruj(i);

		/*	fstream file;
			file.open("bazapacjentow.txt", ios::out | ios::app);
			file << nowy_pacjent.pesel << "\t";
			file << nowy_pacjent.karta_pacjenta << '\t';
			file << nowy_pacjent.Imie << "\t";
			file << nowy_pacjent.Nazwisko << "\t";
			file << nowy_pacjent.adres << "\t";
			file << nowy_pacjent.nr_tel << endl;
			file.close();
			KartaPacjenta nowa_karta(i, "opis");							//Baza kart pacjenta
			fstream kp_baza;
			kp_baza.open("bazakart_pacj.txt", ios::out | ios::app);
			kp_baza << nowa_karta.id_karty << "\t";
			kp_baza << nowa_karta.opis << endl;
			kp_baza.close(); */
		}


		else if (log == 2) {

			int pesel;
			cin >> pesel;
			string linia, pesel2;
			fstream file2;
			int poz1,poz2,dl;
			poz1 = 4;
			//Pacjent* ist_pacjent = new Pacjent;					//Aktualnie zalogowany pacjent
			
			file2.open("bazapacjentow.txt", ios::in | ios::app);
			if (file2.good() == true)
			{													//Pszeszukiwanie pliku
				while (!file2.eof())
				{	getline(file2, linia,'\n');
					pesel2 = linia.substr(0, 3);
					dane = linia.substr(poz1);
					
					if (pesel2 == to_string(pesel)) {			//jezeli pesel sie zgadza to wyswietl 
						pesel = stoi(pesel2);
						ist_pacjent->pesel = pesel;				//przypisanie peselu
						cout << dane << endl;
						//poz2 = dane.find('\t');
						//dl = poz2 - poz1;
						//linia = dane.substr(poz2, dl);
						//cout << dl << poz1 << poz2 << endl;		//Trzeba z reszty stringa wyciac pozostale pola!!!
						break;
					}
					
				}
				//cout << "Pacjenta nie znaleziono" << endl;
				file2.close();
				
			} 
		}

		cout << "1.Umow wizyte" << endl;
		string linia;
		fstream plik1;

		plik1.open("bazalekarzynowa.txt", ios::in);
		if (plik1.good() == true)
		{
			while (!plik1.eof())
			{
				getline(plik1, linia);
				cout << linia << " ";
				getline(plik1, linia);
				cout << linia << " ";
				getline(plik1, linia);
				cout << linia << " ";
				getline(plik1, linia);
				cout << linia << endl;
			}
			plik1.close();
		}
		cout << "2.Odwolaj wizyte" << endl;
		cout << "3.Zobacz Harmonogram" << endl;
		cout << "4.Zaplac za wizyte" << endl;


		cin >> log;
		if (log == 1) {
			/*Wizyta nowa_wizyta(id_kp, id_lek);
			fstream wiz_baza;
			wiz_baza.open("baza_wizyt.txt", ios::out | ios::app);
			wiz_baza << nowa_wizyta.id_kart_pacj << "\t";
			wiz_baza << nowa_wizyta.id_lekarz << "\t";
			wiz_baza << nowa_wizyta.data_wizyty << "\t";
			wiz_baza.close();*/
		}
		else if (log == 2) {

		}
		else if(log == 3) {

		}
		else if (log == 4) {
			Obsluga obsluga;
			
			//ist_pacjent->zaplac_za_wizyte();
			int cena = rand() % 100;
			obsluga.potwierdzenie_platnosci(ist_pacjent->zaplac_za_wizyte(cena));
			
			Paragon paragon(cena);
			paragon.PrintParagon();




		}
	}
	else if (p == 1) {
	// lekarz
	cout << "Logowanie jako lekarz" << endl;

	int Dane;
	cin >> Dane;
	string linia;
	fstream lek_baza;
	int poz1 = 4;
	Lekarz* akt_lekarz = new Lekarz;					//Aktualnie zalogowany pacjent
	lek_baza.open("bazalekarzynowa.txt", ios::in | ios::app);
	if (lek_baza.good() == true)
	{													//Pszeszukiwanie pliku
		while (!lek_baza.eof())
		{
			getline(lek_baza, linia, '\n');
			//pesel2 = linia.substr(0, 3);				//porównanie 3 pierwszych znaków
			//dane = linia.substr(poz1);					//czemu 3? to tylko przyk³adowo :D

			if (linia == to_string(Dane)) {			//jezeli pesel sie zgadza to wyswietl 

				akt_lekarz->id_lekarza = Dane;				//przypisanie peselu
				getline(lek_baza, linia, '\n');
				akt_lekarz->Imie = linia;
				getline(lek_baza, linia, '\n');
				akt_lekarz->Nazwisko = linia;
				getline(lek_baza, linia, '\n');
				akt_lekarz->specjalizacja = linia;
				break;
			}

		}
		//cout << "Pacjenta nie znaleziono" << endl;
		lek_baza.close();

	}
	int cos;
	cin >> cos;
	
	cout << "1.Ustaw terminy przyjec" << endl;
	cout << "2.Wypisz recepte" << endl;
	cout << "3.Sprawdz karte pacjenta" << endl;

	
	if(cos==1)akt_lekarz->Ustaw_terminy();
	else if(cos==2)akt_lekarz->Wypisz_recepte();
	else if(cos==3)akt_lekarz->Sprawdz_Karte();
	

	}
	else if (p == 2) {
		// pielegiarka
		cout << "Logowanie jako pielegiarka" << endl;
		cout << "1.Zarejestruj pacjenta" << endl;
		cout << "2.Sprawdz karte pacjenta" << endl;
		cout << "3.Zobacz harmonogram lekarza" << endl;
	}

}

int main(){

	string login;
	int parametr;

	while (1) {

		cout << endl;
		cout << "Logowanie do systemu(male litery!):  ";
		cin >> login;


		if (login == "pacjent") {
			parametr = 0;
		}
		else if (login == "lekarz") {
			parametr = 1;
		}
		else if (login == "pielegiarka") {
			parametr = 2;
		}
		else {
			cout << "zly login" << endl;
			parametr = -1;
		}

		menu(parametr);

	}
	system("pause");
}