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
                    if(wybor!='R' && wybor != 'Z')system("cls");
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
                        if(wybor!= 'L' && wybor!='R' && wybor != 'Z')system("cls");
                        if(wybor=='R')
                        {
                            Klient aktualny;
                            aktualny.rejestracja(tablica,ilosc,plik_wczytujacy);
                            delete_array(tablica,ilosc);
                            ilosc =sprawdzenie_ilosc_uzyt(plik_wczytujacy);
                        }
                        else if(wybor == 'L')
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
                        else if(wybor == 'Z')
                        {
                            int iloscA =sprawdzenie_ilosc_uzyt("admin.txt");
                            string** tablicaA=wczytanie_bazy("admin.txt",iloscA);

                            Admin admin;
                           if(admin.logowanie(tablicaA,iloscA))
                           {
                               do
                               {


                                   cout<<"BAZA DANYCH 2000 - Root Mode"<<endl;
                                   cout<<"Stworz konto (S)"<<endl;

                                   if(ilosc>0)
                                   {
                                       cout<<"Usun konto (U) - nie dziala"<<endl
                                       <<"Wyswietl wszystkich (W)"<<endl
                                       <<"Znajdz konto(Z)"<<endl
                                        <<"Wyjscie (X)\t"<<endl;
                                        cin>>wybor;
                                        switch (wybor)
                                        {
                                            case 'W':
                                               admin.wyswietl_wszystkich(admin);
                                                break;
                                            case 'Z':
                                                admin.znajdz_uzytkownika(tablica,ilosc);
                                                break;
                                            default:
                                                cout<<"Wyjscie"<<endl;
                                                break;
                                        }
                                   }
                                   else
                                   {
                                      cout<<"Wyjscie (X)\t"<<endl;
                                      cin>>wybor;
                                   }
                                   if (wybor == 'S') admin.stworz_konto();
                               }while(wybor!= 'X');
                           }
                           delete_array(tablicaA,iloscA);
                        }
                        else  delete_array(tablica,ilosc);
                    }

                }while(wybor!= 'X');
            }
        }while(wybor!= 'X');
    }

    return 0;
}

