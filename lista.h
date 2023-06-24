#ifndef ZNAM_LISTE
#define ZNAM_LISTE
#include<iostream>
#include"dane.h"
using namespace std;





template<typename JakisTyp>
struct ListaSort
{
private:
    struct Node
    {
        JakisTyp dane;
        Node *nast;
        Node(JakisTyp A, Node *N=nullptr);
    };
    Node *pocz;
    int IleJest;
public:
    ListaSort();
    ~ListaSort();
    JakisTyp zdejmij_z_poczatku();
    void wstaw(JakisTyp A );//wstawianie osob do listy, tak zeby bylo posortowane
};

template<typename JakisTyp>
ListaSort<JakisTyp>::Node::Node(JakisTyp A, Node *N)
{
    dane=A;
    nast=N;
}

template<typename JakisTyp>
ListaSort<JakisTyp>::ListaSort()
{
    pocz=nullptr;
    IleJest=0;
}

template<typename JakisTyp>
void ListaSort<JakisTyp>::wstaw(JakisTyp A)
{
    Node *nowy;
    nowy=new Node (A);
    if (pocz==nullptr)
        pocz=nowy;
    else if (pocz!=nullptr && (pocz->dane)<=A)
    {
        nowy->nast=pocz;
        pocz=nowy;
    }
    else
    {
        Node *szuk=pocz;
        Node *zaszuk=nullptr;
        while(szuk!=nullptr && A<=(szuk->dane))
        {
            zaszuk=szuk;
            szuk=szuk->nast;
        }
        zaszuk->nast=nowy;
        nowy->nast=szuk;
    }
    IleJest++;
}

template<typename JakisTyp >
ListaSort<JakisTyp>::~ListaSort()
{
    Node *killer;
    while(pocz!=nullptr)
    {
        killer=pocz;
        pocz=killer->nast;
        delete killer;
    }
}


template<typename JakisTyp>
JakisTyp ListaSort<JakisTyp>::zdejmij_z_poczatku()
{
    if (pocz==nullptr) throw runtime_error("Lista pusta, nie mozna zwrocic wartosci ");
    JakisTyp s= (*pocz).dane;
    Node* killer=pocz;
    pocz = (*pocz).nast;
    delete killer;
    IleJest--;
    return s;

}
#endif // ZNAM_LISTE
