#include "Klient.h"
char wybor;

int main()
{
    bool is_it;
    do
    {
    cout<<"BAZA DANYCH 2000"<<endl
    <<"LOGOWANIE (L)"<<endl
    <<"REJESTROWANIE (R)\t"<<endl;
    cin>>wybor;
    if(wybor!= 'L' && wybor!='R')ClearScreen();
    }while(wybor!= 'L' && wybor!='R');
    if(wybor=='R')
    {
   Klient aktualny;
   aktualny.rejestracja();
    }
    else
    {
    Klient aktualny;
   is_it=aktualny.logowanie();
   if(is_it)
   {
      cout<<"BAZA DANYCH 2000"<<endl
    <<"Wyswietlanie (W)"<<endl
    <<"Wyjscie (X)\t"<<endl;
    cin>>wybor;
    if(wybor == 'W') aktualny.wyswietl();
    }
    }

    return 0;
}
