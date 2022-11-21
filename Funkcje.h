#ifndef Funkcje_h
#define Funkcje_h
#include <string>
#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdio.h>
using namespace std;
class Klient
{
private:
    std::string login, haslo,imie,nazwisko;

public:
    bool logowanie(string** tab, int il_uzytkownik);
    void rejestracja();
    void wyswietl();
    void usun_konto(string** tab, int il_uzytkownikow);
};


string** wczytanie_bazy(string nazwa_pliku,int k);
void zapis_bazy(string nazwa_pliku);
int sprawdzenie_ilosc_uzyt(string nazwa_pliku);
#endif
