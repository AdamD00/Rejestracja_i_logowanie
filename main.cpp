#include <vector>
#include "Funkcje.h"
char wybor;
int main()
{
    string dane;
    BAZA* UsedDataBase = new BAZA();
    if(UsedDataBase->plik_wczytujace=="Error")
    {
        return EXIT_FAILURE;
    }
    else
    {
        do
        {
            UsedDataBase->ArrayUpdate();

            system("cls");
            if (UsedDataBase->ilosc == 0)
            {
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
                        aktualny.rejestracja(UsedDataBase->tablica,UsedDataBase->ilosc,UsedDataBase->plik_wczytujace);

                    }
                }
            }
            else if(UsedDataBase->ilosc>0)
            {
                do
                {
                    UsedDataBase->ArrayUpdate();
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
                            aktualny.rejestracja(UsedDataBase->tablica,UsedDataBase->ilosc,UsedDataBase->plik_wczytujace);
                        }
                        else if(wybor == 'L')
                        {
                            Klient aktualny;
                            if(aktualny.logowanie(UsedDataBase->tablica,UsedDataBase->ilosc))
                            {
                                bool check;
                                do
                                {
                                    system("cls");
                                    cout<<"BAZA DANYCH 2000"<<endl;
                                    cout<<"User: "<<aktualny.getImie()<<endl;
                                    cout<<"Wyswietlanie (W)"<<endl
                                    <<"Zmiana danych (Z)"<<endl
                                    <<"Usun konto (U)"<<endl
                                    <<"Wyjscie (X)\t"<<endl;
                                    cin>>wybor;
                                    switch (wybor)
                                    {
                                        case 'W':
                                            aktualny.wyswietl();
                                            break;
                                        case 'U':
                                           check=aktualny.usun_konto(UsedDataBase->tablica,UsedDataBase->ilosc,UsedDataBase->plik_wczytujace);
                                            break;
                                        case 'Z':
                                            check=aktualny.usun_konto(UsedDataBase->tablica,UsedDataBase->ilosc,UsedDataBase->plik_wczytujace);
                                            break;
                                        default:
                                            cout<<"Wyjscie"<<endl;
                                            break;
                                    }
                                }while(wybor!= 'X' && check == false);
                            }
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

                                    system("cls");
                                   cout<<"BAZA DANYCH 2000 - Root Mode"<<endl;
                                   cout<<"Operacje na Bazie "<<UsedDataBase->plik_wczytujace<<" zamiana bazy (C)"<<endl;
                                   cout<<"Stworz konto (S)"<<endl;

                                   if(UsedDataBase->ilosc>0)
                                   {
                                       cout<<"Wyswietl wszystkich (W)"<<endl
                                       <<"Znajdz konto(Z)"<<endl
                                        <<"Wyjscie (X)\t"<<endl;
                                        cin>>wybor;
                                        if(wybor =='C')
                                        {
                                            UsedDataBase->DataBaseUpdate();
                                        }
                                        switch (wybor)
                                        {
                                            case 'W':
                                               admin.wyswietl_wszystkich(UsedDataBase->tablica,UsedDataBase->ilosc);
                                                break;

                                            case 'Z':
                                                admin.znajdz_uzytkownika(UsedDataBase->tablica,UsedDataBase->ilosc,UsedDataBase->plik_wczytujace);
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
                    }

                }while(wybor!= 'X');
            }
        }while(wybor!= 'X');
    }

    return EXIT_SUCCESS;
}

