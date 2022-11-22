#include "Funkcje.h"

bool Klient::logowanie(string** tab, int il_uzytkownikow)
{
    bool is_login=false;
    int i;
    string login, haslo;
    cout<<"LOGIN:";
    cin>>login;
    for(i = 0; i<il_uzytkownikow; i++)
        if(login == tab[i][0])
        {
            is_login = true;
            break;
        }

    if(!is_login)
    {
        cout<<"BRAK LOGINU\n";
        cin.sync();
        cin.get();
        return false;
    }
    cout<<"PASSWORD:";
    cin>>haslo;
    if(haslo == tab[i][1] )
    {
        cout<<"Witaj "<<tab[i][2]<<endl;
        this->login = tab[i][0];
        this->haslo = tab[i][1];
        this->imie = tab[i][2];
        this->nazwisko= tab[i][3];
        return true;
    }
    else
    {
        cout<<"ZLE HASLO\n";
        return false;
    }
}
void Klient::rejestracja(string** tab, int il_uzytkownikow)
{
    string login, haslo, imie, nazwisko;
    bool powtorzenie;
    do
    {
        powtorzenie = false;
        cout<<"Wpisz login:";
        cin>>login;
        for(int i = 0; i<il_uzytkownikow; i++)
        if(login == tab[i][0])
        {
            powtorzenie = true;
            break;
        }
        if(powtorzenie) cout<<"Login zajety\n";
    }while(powtorzenie);
    cout<<"Wpisz haslo:";
    cin>>haslo;
    cout<<"Wpisz imie:";
    cin>>imie;
    cout<<"Wpisz nazwisko:";
    cin>>nazwisko;
    fstream plik;
    if(il_uzytkownikow>0)
    {
    plik.open("klienci.txt",ios::out | ios::app);
    plik.seekp(-1,ios_base::end);
    }
    else plik.open("klienci.txt",ios::out);

    plik<<login<<";"<<haslo<<";"<<imie<<";"<<nazwisko<<";";
    plik.close();
}
void Klient::wyswietl()
{
    cout<<"Uzytkownik:"<<this->imie<<" "<<this->nazwisko<<" \nLogin:"<<this->login<<endl;
    cin.sync();
    cin.get();
}
bool Klient::usun_konto(string** tab, int il_uzytkownikow)
{
    bool udane=false;
    cout<<"Zeby usunac konto wpisz \"Usun "<<this->login<<"\""<<endl;
    string potwierdzenie;
    cin.sync();
    getline(cin, potwierdzenie);
    cout<<potwierdzenie<<endl;
    if(potwierdzenie == "Usun "+this->login)
    {
        for(int i=0; i<il_uzytkownikow;i++)
        {
            if(this->login == tab[i][0])
            {
                udane = true;
               fstream plik;
               plik.open("klienci.txt",ios::out);
               for(int j=0; i<il_uzytkownikow;i++)
                {
                    if(j==i) continue;
                    else plik<<tab[j][0]<<";"<<tab[j][1]<<";"<<tab[j][2]<<";"<<tab[j][3]<<";";
                }
                plik.close();

            }
        }

    }
    return udane;
}
int sprawdzenie_ilosc_uzyt(string nazwa_pliku)
{
    fstream plik;
    string dane;
    int uzyt = 0, cechy = 0;
        plik.open(nazwa_pliku,ios::in);
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
        return uzyt;
}

string** wczytanie_bazy(string nazwa_pliku,int k)
{
    string** tab;
    tab = new string*[k];
    for(auto j=0;j<k;j++)
        tab[j] = new string[4];
    fstream plik;
    plik.open(nazwa_pliku,ios::in);
        if(plik.good())
        {
             for(auto i = 0; i<k; i++)
                for (auto j = 0; j<4; j++)
                    getline(plik,tab[i][j],';');
        }
        else
        {
            cout<<"PROBLEM Z PLIKIEM\nPRZERYWAM DZIALANIE";
        }
        plik.close();
        return tab;
}
void kopia_bazy(string nazwa_pliku)
{
}
void delete_array(string** tab, int il_uzytkownikow)
{
     for(auto j=0;j<il_uzytkownikow;j++) delete [] tab[j];
        delete [] tab;
}
