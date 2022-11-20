#include <vector>

#include "Klient.h"
char wybor;
int main()
{

    int uzyt = 0, cechy = 0;
    string plik_wczytujacy="klienci.txt", dane;
    cout<<"=======================Sprawdzanie ilosci uzytkownikow=============================="<<endl;
        fstream plik;
        plik.open(plik_wczytujacy,ios::in);
        if(plik.good())
        {
            while(plik.eof()==false)
            {
                getline(plik,dane,';');
                cechy++;
                if(cechy%4 == 0)
              {

                  uzyt++;
                  cechy = 0;
              }
            }
        }
        else
        {
            cout<<"PROBLEM Z PLIKIEM\nPRZERYWAM DZIALANIE";
        }
        plik.close();
        cout<<"ILOSC UZYTKOWNIKOW\t"<<uzyt<<endl;
         cout<<"=======================Tworzenie tabeli uzytkownikow=============================="<<endl;
         string tablica[uzyt][4];


    cout<<"=======================Wczytanie danych z pliku do tablicy=============================="<<endl;

        plik.open(plik_wczytujacy,ios::in);
        if(plik.good())
        {
             for(auto i = 0; i<uzyt; i++)
                for (auto j = 0; j<4; j++)
                    getline(plik,tablica[i][j],';');
        }
        else
        {
            cout<<"PROBLEM Z PLIKIEM\nPRZERYWAM DZIALANIE";
        }
        plik.close();

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
                cout<<uzyt<<endl;
                if(aktualny.logowanie(tablica,uzyt))
                {
                    cout<<"Wyswietlanie (W)"<<endl
                    <<"Wyjscie (X)\t"<<endl;
                    cin>>wybor;
                    if(wybor == 'W') aktualny.wyswietl();
                }
            }
        }
    }while(wybor!= 'X');
    delete tablica;
    return 0;
}
