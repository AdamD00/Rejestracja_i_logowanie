#include "Klient.h"

bool Klient::logowanie()
{
    string login, haslo, dane, temp;
    bool is_login;
    cout<<"LOGIN:";
    cin>>login;
    cout<<"PASSWORD:";
    cin>>haslo;
    fstream plik;
    plik.open("klienci.txt",ios::in);
    if(plik.good()==true)
    {

    do
    {
        getline(plik,dane,'-');
        int dlugosc_linii = dane.length();
        int i=0, tymczasowa;


        if(dane == login)
        {
            cout<<"LOGIN POPRAWNY"<<endl;
            is_login=true;
            getline(plik,dane,'-');

            cout<<"----->"<<dane<<"<-----"<<endl;
            if(dane== haslo)
            {

                this->login = login;
                this->haslo = haslo;
                getline(plik,dane,'-');
                this->imie = dane;
                getline(plik,dane);
                this->nazwisko = dane;
                plik.close();
                return true;

            }
            else {
                cout<<"Zle haslo"<<endl;
            }
        }
        else
        {
            getline(plik,dane);
        }
    }while(plik.eof()==false);
        if(is_login==false) cout<<"Brak loginu"<<endl;

        plik.close();
        return false;
    }
}
void Klient::rejestracja()
{
    cout<<"Wpisz login:";
    cin>>this->login;
    cout<<endl<<"Wpisz haslo:";
    cin>>this->haslo;
    cout<<endl<<"Wpisz imie:";
    cin>>this->imie;
    cout<<endl<<"Wpisz nazwisko:";
    cin>>this->nazwisko;
    fstream plik;
    plik.open("klienci.txt",ios::in|ios::app);
    plik<<this->login<<"-"<<this->haslo<<"-"<<this->imie<<"-"<<this->nazwisko;
    plik<<endl;
    plik.close();
};
void Klient::wyswietl()
{
    cout<<"Uzytkownik:"<<this->imie<<" "<<this->nazwisko<<" \nLogin:"<<this->login<<endl;
};
