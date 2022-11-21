#include <vector>
#include "Funkcje.h"
char wybor;
int main()
{
    string plik_wczytujacy="klienci.txt", dane;
    cout<<"=======================Sprawdzanie ilosci uzytkownikow=============================="<<endl;
    int ilosc =sprawdzenie_ilosc_uzyt(plik_wczytujacy);


    cout<<"=======================Wczytanie danych z pliku do tablicy=============================="<<endl;
   string** tablica=wczytanie_bazy(plik_wczytujacy,ilosc);
    do
    {
        cout<<"BAZA DANYCH 2000"<<endl
        <<"LOGOWANIE (L)"<<endl
        <<"REJESTROWANIE (R)"<<endl
        <<"WYJSCIE (X)"<<endl;
        cin>>wybor;
        if(wybor!='X')
        {
            if(wybor!= 'L' && wybor!='R')system("cls");
            if(wybor=='R')
            {
                Klient aktualny;
                aktualny.rejestracja();
            }
            else
            {
                Klient aktualny;
                if(aktualny.logowanie(tablica,ilosc))
                {
                    cout<<"Wyswietlanie (W)"<<endl
                    <<"Usun konto (U)"<<endl
                    <<"Wyjscie (X)\t"<<endl;
                    cin>>wybor;
                    switch (wybor)
                    {
                    case 'W':
                        aktualny.wyswietl();
                        break;
                    case 'U':
                        aktualny.usun_konto(tablica,ilosc);
                        break;
                    default:
                        cout<<"Wyjscie"<<endl;
                        break;
                    }
                }
            }
        }
    }while(wybor!= 'X');
    for(auto j=0;j<ilosc;j++) delete [] tablica[j];
    delete [] tablica;
    return 0;
}
