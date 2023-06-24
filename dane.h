#ifndef ZNAM_DANE
#define ZNAM_DANE
#include <string>
using namespace std;


struct Osoba
{
private:
    string imie;
    string nazwisko;
    int pesel[11];
    // data_urodzenia;
    int dzien, miesiac, rok;
    bool wer;
public:
    Osoba()=default;
    ~Osoba()=default;
    Osoba(string i, string n, string p);
    //gettery
    string wezImie() const;
    string wezNazwisko() const;
    int* wezPesel();
    int wezDzien() const;
    int wezMiesiac() const;
    int wezRok() const;
    bool getWer() const;
    //settery
    void dajImie(string i);
    void dajNazwisko(string n);
    void dajPesel(string p);


    bool operator<=(const Osoba &o);//porowna daty urodzenia
    bool Werifikacja(string i, string n);
};

bool CzyNapisToPesel(string p);
int wytnijDzien(string p);
int wytnijMiesiac(string p);
int wytnijRok(string p);
ostream &operator<<(ostream &os, Osoba &Q);


#endif //ZNAM_DANE
