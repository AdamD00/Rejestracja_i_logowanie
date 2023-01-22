#ifndef Funkcje_h
#define Funkcje_h
#include <string>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdio.h>
#include <map>
#include <vector>
using namespace std;
class Klient
{
    protected:
        string login, haslo,imie,nazwisko;

    public:
        Klient();
        Klient(string l, string h, string i, string n);

        bool logowanie(string** tab, int il_uzytkownik);
        void rejestracja(string** tab, int il_uzytkownikow, string nazwa_pliku);
        void wyswietl();
        void zmiana_danych(string** tab, int il_uzytkownikow, string nazwa_pliku);
        bool usun_konto(string** tab, int il_uzytkownikow, string nazwa_pliku);
        string getImie();
    };
class Admin: public Klient
{
    public:
        void znajdz_uzytkownika(string** tab, int il_uzytkownikow,string nazwa_pliku);
        void wyswietl_wszystkich(string** tab, int il_uzytkownikow);
        void wyswietl_wszystkich(Admin a);
        void stworz_konto();


};
struct BAZA
{
    string plik_wczytujace;
    int ilosc;
    string** tablica;

    void ArrayUpdate();
    void DataBaseUpdate();

    BAZA();
    ~BAZA();

};
string** wczytanie_bazy(string nazwa_pliku,int k);
void kopia_bazy(string nazwa_pliku);
int sprawdzenie_ilosc_uzyt(string nazwa_pliku);
void delete_array(string** tab, int il_uzytkownikow);
string wybor_bazy();

#endif
