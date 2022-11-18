#ifndef Klient_h
#define Klient_h
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
    bool logowanie();
    void rejestracja();
    void wyswietl();
};

#endif
