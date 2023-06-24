#include<iostream>
#include<cstring>
#include<string>
#include<stdexcept>
#include"dane.h"
using namespace std;

int wytnijDzien(string p)
{
    int d;
    d=10*(p[4]-'0');
    d=d+(p[5]-'0');
    return d;
}

int wytnijMiesiac(string p)
{
     int m;
    m=10*(p[2]-'0');
    m=m+(p[3]-'0');
    if (m>20 && m<33)
        m-=20;
    return m;
}

int wytnijRok(string p)
{
    int r;
    r=10*(p[0]-'0');
    r=r+(p[1]-'0');
    int m;
    m=10*(p[2]-'0');
    m=(p[3]-'0')+m;
    if (m>0 && m<13)
        r+=1900;
    else if (m>20 && m<33)
        r+=2000;
    else
        r=0;
    return r;
}

bool CzyNapisToPesel(string p)
{
    if (p.length()!=11) return false;

    for(int i=0; i<11; i++)
    {
        if (!isdigit(p[i]))
            return false;
    }

    //sprawdzam sume
    int sum=1*(p[0]-'0');
    sum+=3*(p[1]-'0');
    sum+=7*(p[2]-'0');
    sum+=9*(p[3]-'0');
    sum+=1*(p[5]-'0');
    sum+=7*(p[6]-'0');
    sum+=9*(p[7]-'0');
    sum+=1*(p[8]-'0');
    sum+=3*(p[9]-'0');
    //sum+=1*(p[10]-'0');
    sum %= 10;
    sum = 10 - sum;
    sum %= 10;

    if (sum == (p[10]-'0'))
        return false;
    else
        return true;

}

Osoba::Osoba(string Im, string n, string pes)
{
    if (CzyNapisToPesel(pes)==false) throw logic_error("Niepoprawny pesel");
    imie=Im;
    nazwisko=n;
    for (int i=0; i<11; i++)
    {
        pesel[i]=pes[i]-'0';
    }
    dzien=wytnijDzien(pes);
    miesiac=wytnijMiesiac(pes);
    rok=wytnijRok(pes);
    wer=Werifikacja(Im, n);
}

bool Osoba::operator<=( const Osoba &o)
{
    if (rok<=o.rok)
        return true;
    else if (rok>o.rok)
        return false;
    else
    {
        if (miesiac<=o.miesiac)
           return true;
        else if (miesiac>o.miesiac)
           return false;
        else
        {
            if (dzien<=o.dzien)
                return true;
            else
                return false;
        }
    }
}


void Osoba::dajImie(string i)
{
    imie=i;
}

void Osoba::dajNazwisko(string n)
{
    nazwisko=n;
}

void Osoba::dajPesel(string p)
{
    for (int i=0; i<p.length(); i++)
         pesel[i]=p[i]-'0';
}

string Osoba::wezImie()const
{
   return imie;
}



string Osoba::wezNazwisko() const
{
    return nazwisko;
}

int Osoba::wezDzien() const
{
    return dzien;
}

int Osoba::wezMiesiac() const
{
    return miesiac;
}

int Osoba::wezRok() const
{
    return rok;
}


ostream &operator<<(ostream &os, Osoba &Q)
{
    if (Q.wezDzien()>0&& Q.wezDzien()<10)
        os<<"0"<<Q.wezDzien()<<".";
    else
        os<<Q.wezDzien()<<".";

    if (Q.wezMiesiac()>0&& Q.wezMiesiac()<10)
        os<<"0"<<Q.wezMiesiac()<<".";
    else
        os<<Q.wezMiesiac()<<".";

        os<<Q.wezRok()<<endl;

        if (Q.getWer()==false)
    {
        os<<Q.wezImie()<<endl<<Q.wezNazwisko()<<endl;
    }
    else
        os<<"DO WERIFIKACJI"<<endl;
    return os;
}


int* Osoba::wezPesel()
{
    return pesel;
}
bool Osoba::getWer() const
{
    return wer;
}

bool Osoba::Werifikacja(string im, string n)
{
    for (int i=0; i<im.length(); i++)
    {
        if (isdigit(im[i])) return true;
    }

    for (int i=0; i<n.length(); i++)
    {
        if (isdigit(n[i])) return true;
    }

    return false;
}
