#include "Funkcje.h"

Klient::Klient()
{
    cout<<"Tworzenie obiektu nieprzeciazonego"<<endl;
}

Klient::Klient(string l, string h,string i, string n) : login(l), haslo(h), imie(i), nazwisko(n)
{
    cout<<"Tworzenie obiektu przeciazonego"<<endl;
}


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
void Klient::rejestracja(string** tab, int il_uzytkownikow, string nazwa_pliku)
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
    plik.open(nazwa_pliku,ios::out | ios::app);
    plik.seekp(-1,ios_base::end);
    }
    else plik.open(nazwa_pliku,ios::out);

    plik<<login<<";"<<haslo<<";"<<imie<<";"<<nazwisko<<";";
    plik.close();
}
void Klient::wyswietl()
{
    cout<<"Uzytkownik:"<<this->imie<<" "<<this->nazwisko<<" \nLogin:"<<this->login<<endl;
    cin.sync();
    cin.get();
}
bool Klient::usun_konto(string** tab, int il_uzytkownikow, string nazwa_pliku)
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
               plik.open(nazwa_pliku,ios::out);
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


void Admin::wyswietl_wszystkich(string** tab, int il_uzytkownikow)
{
    system("cls");
    for(int i=0;i<il_uzytkownikow;i++)
    {
        cout<<"Login: "<<tab[i][0]<<" Haslo: "<<tab[i][1]<<" Imie: "<<tab[i][2]<<"  Nazwisko: "<<tab[i][3]<<endl;
    }
    cin.sync();
    cin.get();
}
void Admin::znajdz_uzytkownika(string** tab, int il_uzytkownikow,string nazwa_pliku)
{
    char szukaj, wybor;
    string szukane;
    vector <int> znalezieni;
    cout<<"Po czym szukac uzytkownika"<<endl
    <<"(L)ogin, (I)mie, (N)azwisko: ";
    cin>>szukaj;
    bool znaleziony, check;
    switch (szukaj)
    {
        case 'L':

            cout<<"Wpisz szukany login: ";
            cin>>szukane;
           for(int i=0;i<il_uzytkownikow;i++)
            {
                if(tab[i][0]==szukane)
                {
                   znalezieni.push_back(i);
                    znaleziony = true;
                }
            }
            break;
        case 'I':
            cout<<"Wpisz szukane imie: ";
            cin>>szukane;
             for(int i=0;i<il_uzytkownikow;i++)
            {
                if(tab[i][2]==szukane)
                {
                    znalezieni.push_back(i);
                    znaleziony = true;
                }
            }
            break;
        case 'N':
        cout<<"Wpisz szukane nazwisko: ";
            cin>>szukane;
             for(int i=0;i<il_uzytkownikow;i++)
            {
                if(tab[i][3]==szukane)
                {
                    znalezieni.push_back(i);
                    znaleziony = true;
                }
            }
        break;
    }
    if(znaleziony)
    {
        int ilosc = znalezieni.size();

        if(ilosc>1)
        {
            cout<<"Znalazlem "<<ilosc<<" uzytkownikow"<<endl;
            for(int i = 0; i<ilosc; i++)
            {
                cout<<"Login: "<<tab[znalezieni.at(i)][0]<<" Haslo: "<<tab[znalezieni.at(i)][1]<<" Imie: "<<tab[znalezieni.at(i)][2]<<"  Nazwisko: "<<tab[znalezieni.at(i)][3]<<endl;
            }
        }
        else if(ilosc == 1)
        {
            cout<<"Login: "<<tab[znalezieni[0]][0]<<" Haslo: "<<tab[znalezieni[0]][1]<<" Imie: "<<tab[znalezieni[0]][2]<<"  Nazwisko: "<<tab[znalezieni[0]][3]<<endl;
            cout<<"Czy chcesz edytowac uzytkownika "<<tab[znalezieni.back()][0]<<"?"<<endl;
            cin.sync();
            cin>>wybor;
            if(wybor == 'Y')
            {
                Klient aktualny(tab[znalezieni[0]][0],tab[znalezieni[0]][1],tab[znalezieni[0]][2],tab[znalezieni[0]][3]);
                do
                {

                    system("cls");
                    cout<<"Usun konto (U)\n Wyjscie (X)\n";
                    cin.sync();
                    cin>>wybor;
                    switch(wybor)
                    {
                    case 'U':
                       check= aktualny.usun_konto(tab,il_uzytkownikow,nazwa_pliku);
                        break;
                    default:
                        cout<<"Wychodze"<<endl;
                        break;
                    }
                }while(wybor!= 'X' && check == false);

            }

        }
    }
    else cout<<"Brak znalezionych"<<endl;


    znalezieni.~vector();
}
 void Admin::stworz_konto()
 {
        string plik_wczytujacy;
        plik_wczytujacy = wybor_bazy();
        if(plik_wczytujacy == "Error")
        {
            cout<<"Nie mozliwe otworzenie spisu baz\n";
        }
        else
        {


                system("cls");
                cout<<"=======================Sprawdzanie ilosci uzytkownikow=============================="<<endl;
                int ilosc =sprawdzenie_ilosc_uzyt(plik_wczytujacy);
                cout<<"=======================Wczytanie danych z pliku do tablicy=============================="<<endl;
                string** tablica=wczytanie_bazy(plik_wczytujacy,ilosc);
                tablica=wczytanie_bazy(plik_wczytujacy,ilosc);
                Klient tymczasowy;
                tymczasowy.rejestracja(tablica,ilosc,plik_wczytujacy);
                delete_array(tablica,ilosc);


     }
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
string wybor_bazy()
{
    string plik_conf = "input.txt", dane;
    int nr_bazy;
    cout<<"=========Wybierz BAZE===========\n";
    map <int,string> m;
    ifstream conf (plik_conf);
    if (conf)
    {
        int i = 1;
        while(!conf.eof())
        {
            getline(conf,dane);
            cout<<i<<"-"<<dane<<endl;
            m.insert(pair<int, string>(i,dane));
            i++;
        }
    conf.close();
    cin>>nr_bazy;
    auto it = m.find(nr_bazy);
    string end = it->second;
    cout<<end<<endl;
    return end;
    }
    else
    {
        return "Error";
    }
}
/*struct BAZA
{
    string plik_wczytujace=wybor_bazy();
    int ilosc=sprawdzenie_ilosc_uzyt(plik_wczytujacy);;
    string** tablica=wczytanie_bazy(plik_wczytujacy,ilosc);

};
*/
