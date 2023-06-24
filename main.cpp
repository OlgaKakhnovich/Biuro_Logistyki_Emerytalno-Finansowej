#include<iostream>
#include<fstream>
#include<stdexcept>
#include"lista.h"
#include"dane.h"
using namespace std;

int main()
{
    ListaSort<Osoba> L;

    ifstream pl_osoby;
    ifstream pl_pesele;

    pl_osoby.open("osoby.txt");
    pl_pesele.open("pesele.txt");

    if (!pl_osoby || !pl_pesele) throw runtime_error("Brak pliku wejsciowego");

     while(true)
     {
         string imie_, nazwisko_, pesel_;
         pl_osoby>>nazwisko_;
         pl_osoby.ignore();
         getline(pl_osoby, imie_);
         getline(pl_pesele, pesel_);
         try
         {
             Osoba W(imie_, nazwisko_, pesel_);
             L.wstaw(W);
         }
         catch (exception &e)
            {
                cout<<e.what()<<" ("<<nazwisko_<<") "<<endl;
            }
        if (pl_osoby.peek()==EOF || pl_pesele.peek()==EOF) break;
     }

      ofstream pl_wyniki;
      pl_wyniki.open("wyniki.txt",ios::trunc);

     while (true)
     {

         Osoba z;
         try
         {
             z=L.zdejmij_z_poczatku();
         }
         catch (exception &e)
         {
             break;
         }
         pl_wyniki<<z<<endl;
     }

     pl_wyniki.close();
     pl_osoby.close();
     pl_pesele.close();

     return 0;
}
