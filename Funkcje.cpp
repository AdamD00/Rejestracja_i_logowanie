#include "Funkcje.h"

Klient::Klient()
{
}

Klient::Klient(string l, string h,string i, string n) : login(l), haslo(h), imie(i), nazwisko(n)
{
}
string Klient::getImie()
{
    return this->imie;
}

bool Klient::logowanie(string** tab, int il_uzytkownikow)
{
    bool is_login=false;
    int i;
    string login, haslo;
    system("cls");
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
        system("cls");
        cout<<"BRAK LOGINU\n";
        cin.sync();
        cin.get();
        return false;
    }
    cout<<"PASSWORD:";
    cin>>haslo;
    if(haslo == tab[i][1] )
    {
        system("cls");
        cout<<"Witaj "<<tab[i][2]<<endl;
        this->login = tab[i][0];
        this->haslo = tab[i][1];
        this->imie = tab[i][2];
        this->nazwisko= tab[i][3];
        return true;
    }
    else
    {
        system("cls");
        cout<<"Z£E HAS£O\n";
        Sleep(3000);
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
        system("cls");
        cout<<"Wpisz login:";
        cin>>login;
        for(int i = 0; i<il_uzytkownikow; i++)
        if(login == tab[i][0])
        {
            powtorzenie = true;
            break;
        }
        system("cls");
        if(powtorzenie) cout<<"Login zajety\n";
    }while(powtorzenie);
    system("cls");
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
    system("cls");
    cout<<"Uzytkownik:"<<this->imie<<" "<<this->nazwisko<<" \nLogin:"<<this->login<<endl;
    cin.sync();
    cin.get();
}
bool Klient::usun_konto(string** tab, int il_uzytkownikow, string nazwa_pliku)
{
    system("cls");
    bool udane=false;
    cout<<"Zeby usunac konto wpisz \"Usun "<<this->login<<"\""<<endl;
    string potwierdzenie;
    cin.sync();
    getline(cin, potwierdzenie);
    if(potwierdzenie == "Usun "+this->login)
    {
        for(int i=0; i<il_uzytkownikow;i++)
        {
            if(this->login == tab[i][0])
            {
                udane = true;
               fstream plik;
               plik.open(nazwa_pliku,ios::out);
               for(int j=0; j<il_uzytkownikow;j++)
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
bool Klient::zmiana_danych(string** tab, int il_uzytkownikow, string nazwa_pliku)
{
    bool udanaZmiana = false, powtorzenieHasla;
    char wybor, potwierdzenie;
    string noweUstawienie, noweUstawienie2;
    system("cls");
    cout<<"Co chcialbys zmienic?"<<endl
    <<"(L)ogin, (I)mie, (N)azwisko, (H)aslo: ";
    cin>>wybor;
    system("cls");
    switch (wybor)
    {
        case 'L':
             for(int i=0; i<il_uzytkownikow;i++)
             {
                 if(this->login==tab[i][0])
                 {
                     cout<<"Stary login: "<<tab[i][0]<<endl
                     <<"Podaj nowy login:";
                     cin>>noweUstawienie;
                     cout<<"Nowy login to:"<<noweUstawienie<<endl;
                     cout<<"Wpisz Y by potwierdzic:";
                     cin>>potwierdzenie;
                     if(potwierdzenie=='Y')
                     {
                        this->login = noweUstawienie;
                        tab[i][0]=noweUstawienie;
                        udanaZmiana = true;
                     }
                    else
                        cout<<"Cofam zmiany"<<endl;
                     break;
                 }
             }

            break;
        case 'I':
            for(int i=0; i<il_uzytkownikow;i++)
             {
                 if(this->imie==tab[i][2])
                 {
                     cout<<"Stare imie: "<<tab[i][2]<<endl
                     <<"Podaj nowe imie:";
                     cin>>noweUstawienie;
                     cout<<"Nowe imie to:"<<noweUstawienie<<endl;
                     cout<<"Wpisz Y by potwierdzic: ";
                     cin>>potwierdzenie;
                     if(potwierdzenie=='Y'){
                        this->imie = noweUstawienie;
                        tab[i][2]=noweUstawienie;
                        udanaZmiana = true;
                     }
                    else
                        cout<<"Cofam zmiany"<<endl;
                     break;
                 }
             }

            break;
        case 'N':
            for(int i=0; i<il_uzytkownikow;i++)
             {
                 if(this->nazwisko==tab[i][3])
                 {
                     cout<<"Stare nazwisko to: "<<tab[i][3]<<endl
                     <<"Podaj nowe nazwisko:";
                     cin>>noweUstawienie;
                     cout<<"Nowe nazwisko to: "<<noweUstawienie<<endl;
                     cout<<"Wpisz Y by potwierdzic:";
                     cin>>potwierdzenie;
                     if(potwierdzenie=='Y')
                        {
                            this->nazwisko = noweUstawienie;
                            tab[i][3]=noweUstawienie;
                            udanaZmiana = true;
                        }
                    else
                        cout<<"Cofam zmiany"<<endl;
                     break;
                 }
             }
            break;
        case 'H':
            for(int i=0; i<il_uzytkownikow;i++)
             {
                 if(this->haslo==tab[i][1])
                 {

                     cout<<"Stare haslo: "<<tab[i][1]<<endl;
                     do
                    {
                         powtorzenieHasla=false;
                         cout<<"Podaj nowe haslo: ";
                         cin>>noweUstawienie;
                         cout<<"Powtorz nowe haslo: ";
                         cin>>noweUstawienie2;
                         if(noweUstawienie2==noweUstawienie) powtorzenieHasla= true;
                         if(powtorzenieHasla == false) cout<<"Hasla nie takie same"<<endl;
                     }while(powtorzenieHasla == false);
                     cout<<"Nowe haslo to:"<<noweUstawienie<<endl;
                     cout<<"Wpisz Y by potwierdzic:";
                     cin>>potwierdzenie;
                     if(potwierdzenie=='Y')
                        {
                            this->haslo = noweUstawienie;
                            tab[i][1]=noweUstawienie;
                            udanaZmiana = true;
                        }
                    else
                        cout<<"Cofam zmiany"<<endl;
                     break;
                 }
             }
            break;
    }

    if(udanaZmiana)
    {
        fstream plik;
        plik.open(nazwa_pliku,ios::out);
        for(int i=0; i<il_uzytkownikow;i++) plik<<tab[i][0]<<";"<<tab[i][1]<<";"<<tab[i][2]<<";"<<tab[i][3]<<";";
        plik.close();

    }
    return udanaZmiana;
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
    bool znaleziony, check, zmienioneDane;
    string szukane;
    vector <int> znalezieni;

    system("cls");
    cout<<"Po czym szukac uzytkownika"<<endl
    <<"(L)ogin, (I)mie, (N)azwisko: ";
    cin>>szukaj;
    system("cls");

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
                    cout<<"Usun konto (U)\n Zmiana danych (Z)\n Wyjscie (X)\n";
                    cin.sync();
                    cin>>wybor;
                    switch(wybor)
                    {
                    case 'U':
                       check= aktualny.usun_konto(tab,il_uzytkownikow,nazwa_pliku);
                        break;
                    case 'Z':
                        zmienioneDane=aktualny.zmiana_danych(tab,il_uzytkownikow,nazwa_pliku);
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
        if(plik_wczytujacy == "Error" or plik_wczytujacy.empty())
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
BAZA::BAZA()
{


        plik_wczytujace = wybor_bazy();
        if(plik_wczytujace == "Error" || plik_wczytujace.empty())
        {
            plik_wczytujace = "Error";
        }
        else
        {
            ilosc=sprawdzenie_ilosc_uzyt(plik_wczytujace);
            tablica=wczytanie_bazy(plik_wczytujace,ilosc);
        }



}
BAZA::~BAZA()
{

        delete_array(tablica,ilosc);

}
void BAZA::ArrayUpdate()
{

    this->ilosc=sprawdzenie_ilosc_uzyt(this->plik_wczytujace);
    this->tablica=wczytanie_bazy(this->plik_wczytujace,this->ilosc);

}
void BAZA::DataBaseUpdate()
{
        this->plik_wczytujace = wybor_bazy();
        if(this->plik_wczytujace == "Error" || this->plik_wczytujace.empty())
        {
           this-> plik_wczytujace = "Error";
        }
        else
        {
            this->ilosc=sprawdzenie_ilosc_uzyt(this->plik_wczytujace);
            this->tablica=wczytanie_bazy(this->plik_wczytujace,this->ilosc);
        }
        cin.sync();
        cin.get();
}
