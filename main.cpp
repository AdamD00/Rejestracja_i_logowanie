#include <vector>
#include "Funkcje.h"
char wybor;
int main()
{
    string plik_wczytujacy, dane;
    plik_wczytujacy = wybor_bazy();
    if(plik_wczytujacy == "Error")
    {
        cout<<"Nie mozliwe otworzenie spisu baz\n";
    }
    else
    {
        do
        {

            system("cls");
            cout<<"=======================Sprawdzanie ilosci uzytkownikow=============================="<<endl;
            int ilosc =sprawdzenie_ilosc_uzyt(plik_wczytujacy);
             cout<<"=======================Wczytanie danych z pliku do tablicy=============================="<<endl;
            string** tablica=wczytanie_bazy(plik_wczytujacy,ilosc);
            if (ilosc == 0)
            {
                tablica=wczytanie_bazy(plik_wczytujacy,ilosc);
                cout<<"BAZA DANYCH 2000"<<endl
                <<"REJESTROWANIE (R)"<<endl
                <<"WYJSCIE (X)"<<endl;
                cin>>wybor;
                if(wybor!='X')
                {
                    if(wybor!='R')system("cls");
                    if(wybor=='R')
                    {
                        Klient aktualny;
                        aktualny.rejestracja(tablica,ilosc,plik_wczytujacy);
                    }
                }
                 delete_array(tablica,ilosc);
            }
            else if(ilosc>0)
            {
                do
                {
                    tablica=wczytanie_bazy(plik_wczytujacy,ilosc);
                    system("cls");
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
                            aktualny.rejestracja(tablica,ilosc,plik_wczytujacy);
                            delete_array(tablica,ilosc);
                            ilosc =sprawdzenie_ilosc_uzyt(plik_wczytujacy);
                        }
                        else
                        {
                            Klient aktualny;
                            if(aktualny.logowanie(tablica,ilosc))
                            {
                                bool check;
                                do
                                {
                                    system("cls");
                                    cout<<"BAZA DANYCH 2000"<<endl;
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
                                           check=aktualny.usun_konto(tablica,ilosc,plik_wczytujacy);
                                            break;
                                        default:
                                            cout<<"Wyjscie"<<endl;
                                            break;
                                    }
                                }while(wybor!= 'X' && check == false);
                            }
                            delete_array(tablica,ilosc);
                        }
                    }

                }while(wybor!= 'X');
            }
        }while(wybor!= 'X');
    }

    return 0;
}

