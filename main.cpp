#include <vector>
#include "Funkcje.h"
char wybor;
int main()
{
    setlocale(LC_ALL,"");
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
                <<"ZAREJESTRUJ SIĘ (R)"<<endl
                <<"WYJŚCIE (X)"<<endl;
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
                    <<"ZALOGUJ SIÊ (L)"<<endl
                    <<"ZAREJESTRUJ SIÊ (R)"<<endl
                    <<"WYJŒCIE (X)"<<endl;
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
                                bool usunienteKonto, zmienioneDane;
                                do
                                {
                                    system("cls");
                                    cout<<"BAZA DANYCH 2000"<<endl;
                                    cout<<"User: "<<aktualny.getImie()<<endl;
                                    cout<<"Wyœwietlanie (W)"<<endl
                                    <<"Zmiana danych (Z)"<<endl
                                    <<"Usuœ konto (U)"<<endl
                                    <<"Wyjœcie (X)\t"<<endl;
                                    cin>>wybor;
                                    switch (wybor)
                                    {
                                        case 'W':
                                            aktualny.wyswietl();
                                            break;
                                        case 'U':
                                           usunienteKonto=aktualny.usun_konto(UsedDataBase->tablica,UsedDataBase->ilosc,UsedDataBase->plik_wczytujace);
                                            break;
                                        case 'Z':
                                            zmienioneDane=aktualny.zmiana_danych(UsedDataBase->tablica,UsedDataBase->ilosc,UsedDataBase->plik_wczytujace);
                                            break;
                                        default:
                                            cout<<"Wyjscie"<<endl;
                                            break;
                                    }
                                    if(zmienioneDane)
                                    {
                                        UsedDataBase->ArrayUpdate();
                                    }
                                }while(wybor!= 'X' && usunienteKonto == false);
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
                                   cout<<"Stwórz konto (S)"<<endl;

                                   if(UsedDataBase->ilosc>0)
                                   {
                                       cout<<"Wyœwietl wszystkich (W)"<<endl
                                       <<"ZnajdŸ konto(Z)"<<endl
                                        <<"Wyjœcie (X)\t"<<endl;
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
                                                UsedDataBase->ArrayUpdate();
                                                break;

                                            default:
                                                cout<<"Wyjœcie"<<endl;
                                                break;
                                        }
                                   }
                                    else
                                   {
                                      cout<<"Wyjście (X)\t"<<endl;
                                      cin>>wybor;
                                   }
                                   if (wybor == 'S')
                                   {
                                       admin.stworz_konto();
                                       UsedDataBase->ArrayUpdate();
                                   }

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

