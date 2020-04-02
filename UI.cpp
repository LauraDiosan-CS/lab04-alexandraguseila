#include "UI.h"
#include <iostream>
using namespace std;


void menu()
{
    cout<<endl;
    cout<<"Optiunile disponibile sunt:"<<endl<<endl;
    cout<<"                              1.Adauga cheltuiala"<<endl;
    cout<<"                              2.Sterge cheltuiala"<<endl;
    cout<<"                              3.Modifica cheltuiala"<<endl;
    cout<<"                              4.Afiseaza cheltuielile"<<endl;
    cout<<"                              5.Filtrari"<<endl;
    cout<<"                              6.Undo"<<endl;
    cout<<"                              x.Exit"<<endl;

}

void menuStergere()
{
    cout<<"                             a.o singura cheltuiala"<<endl;
    cout<<"                             b.dupa apartament"<<endl;
    cout<<"                             c.dupa suma"<<endl;
    cout<<"                             d.dupa tip"<<endl;
}

void menuAfisare()
{
    cout<<"                              a.Afiseaza toate cheltuielile"<<endl;
    cout<<"                              b.Afiseaza cheltuielile unui apartament dat"<<endl;
    cout<<"                              c.Afiseaza cheltuielile care au suma mai mare decat o suma data"<<endl;
    cout<<"                              d.Afiseaza cheltuielile care au suma egala cu o suma data"<<endl;
    cout<<"                              e.Afiseaza suma tuturor cheltuieilor de tipul introdus"<<endl;
    cout<<"                              f.Afiseaza cheltuiala maxima a unui apartament introdus"<<endl;
    cout<<"                              g.Sorteaza cheltuielile de acelasi tip"<<endl;
}

void menuFiltrare()
{
    cout<<"                              a.Pastreaza cheltuielile dupa tipul lor"<<endl;
    cout<<"                              b.Pastreaza cheltuielile cu suma mai mica decat o valoare data"<<endl;
}


void console(Service& s)
{
    char optiune, optiune2;
    while(true)
    {
        menu();
        cout<<"Optiunea dvs este:";
        cin>>optiune;
        if(optiune == '1')
            addCheltuiala(s);
        else
            if(optiune == '2')
                {
                    menuStergere();
                    cout<<"Optiunea dvs este:";cin>>optiune2;
                    if(optiune2 == 'a')
                        removeCheltuiala(s);
                    else
                        if(optiune2 == 'b')
                            removeCheltuialaByAp(s);
                        else
                            if(optiune2 == 'c')
                                removeCheltuialaBySum(s);
                            else
                                if(optiune2 == 'd')
                                    removeCheltuialaByType(s);
                }
            else
                if(optiune == '3')
                    updateCheltuiala(s);
                else
                    if(optiune == '4')
                        {
                            menuAfisare();
                            cout<<"Optiunea dvs este:";cin>>optiune2;
                            if(optiune2 == 'a')
                                showAll(s);
                            else
                                if(optiune2 == 'b')
                                    showAllByApartament(s);
                                else
                                    if(optiune2 == 'c')
                                        showAllBySum(s);
                                    else
                                        if(optiune2 == 'd')
                                            showAllEqualToSum(s);
                                        else
                                            if(optiune2 == 'e')
                                                getSumaByTip(s);
                                            else
                                                if(optiune2 == 'f')
                                                    maxCheltuialaPerAp(s);
                                                else
                                                    if(optiune2 == 'g')
                                                        sortCheltuieliByType(s);
                        }
                        else
                            if(optiune == '5')
                            {
                                menuFiltrare();
                                cout<<"Optiunea dvs este:";cin>>optiune2;
                                if(optiune2 == 'a')
                                    filterByType(s);
                                else
                                    if(optiune2 == 'b')
                                        filterByCond(s);

                            }
                            else
                                if(optiune == 'x')
                                    break;
                                else
                                    if(optiune == '6')
                                        undo(s);

    }
}




void addCheltuiala(Service& s)
{
    Cheltuiala c;
    cout<<"Dati cheltuiala"<<endl;
    cin>>c;
    s.add(c);
    cout<<"Cheltuiala a fost adaugata!"<<endl;
}

void removeCheltuiala(Service& s)
{
    Cheltuiala c;
    cout<<"Introduceti datele cheltuielii de sters "<<endl;
    cin>>c;
    s.del(c);
    //if(ok == 0)
    //    cout<<"Nu exista cheltuieli aferente acestui apartament"<<endl;
}

void updateCheltuiala(Service& s)
{
    Cheltuiala cheltDeModificat;
    Cheltuiala cheltModificata;
    cout<<"Introduceti datele cheltuielii  pe care doriti sa o modificati"<<endl;
    cin>>cheltDeModificat;
    cout<<endl;
    for(int i=0; i<s.getNrCheltuieli(); i++)
        if(s.getAll()[i] == cheltDeModificat)
        {
            cout<<"Introduceti noile date"<<endl;
            cin>>cheltModificata;
            s.updateCheltuiala(cheltDeModificat, cheltModificata);
        }
        else
            cout<<"Cheltuiala pe care doriti sa o modificati nu exista!"<<endl;

}


void showAll(Service &s)
{
    cout<<"Cheltuielile adaugate sunt:"<<endl;
    Cheltuiala* listaCheltuieli= new Cheltuiala[25];
    listaCheltuieli = s.getAll();
    if(s.getNrCheltuieli() ==0)
        cout<<"                               Nu exista cheltuieli!"<<endl;
    else
       {
           for(int i=0; i<s.getNrCheltuieli(); i++)
        {
            cout<<"                            Cheltuiala "<<i+1<<": "<<listaCheltuieli[i]<<endl;
        }
           //delete[] listaCheltuieli;}

        }
}


void removeCheltuialaByAp(Service& s)
{
    int ap;
    cout<<"Apartamentul ale carui cheltuieli doriti sa le stergeti este: "<<endl;
    cin>>ap;
    s.removeCheltuialaByAp(ap);
    cout<<"Cheltuielile apartamentului "<<ap<<" au fost sterse!"<<endl;
    //    cout<<"Apartamentul "<<ap<<"nu exista!"<<endl;
}

void removeCheltuialaBySum(Service& s)
{
    int suma;
    cout<<"Vor fi sterse cheltuielile in valoare de: "<<endl;
    cin>>suma;
    //int ok;
    s.removeCheltuialaBySum(suma);
    //if(ok == 1)
    cout<<"Cheltuielile in valoare de "<<suma<<" lei au fost sterse!"<<endl;
    //else
    //    cout<<"Nu exista cheltuieli in valoare de "<<suma<<"lei!"<<endl;
}


void removeCheltuialaByType(Service& s)
{
    char* tip = new char[9];
    cout<<"Introduceti tipul cheltuielii:"<<endl;
    cin>>tip;
    //int ok;
    s.removeCheltuialaByType(tip);
    //if(ok == 1)
    cout<<"Cheltuielile care includ "<<tip<<" au fost sterse!"<<endl;
    //else
    //    cout<<"Nu exista astfel de cheltuieli!"<<endl;

}

void showAllByApartament(Service& s)
{
    int n, ap;
    cout<<"Dati apartamentul:"<<endl;
    cin>>ap;
    Cheltuiala* listaCheltuieli = s.showAllByApartament(ap, n);
    for(int i=0; i<n;i++)
        cout<<listaCheltuieli[i]<<endl;
}

void showAllBySum(Service& s)
{
    int n, sum;
    cout<<"Dati suma:"<<endl;
    cin>>sum;
    Cheltuiala* listaCheltuieli = s.showAllBySum(sum, n);
    for(int i=0; i<n;i++)
        cout<<listaCheltuieli[i]<<endl;
}

void showAllEqualToSum(Service& s)
{
    int n, sum;
    cout<<"Dati suma:"<<endl;
    cin>>sum;
    Cheltuiala* listaCheltuieli = s.showAllEqualToSum(sum, n);
    for(int i=0; i<n;i++)
        cout<<listaCheltuieli[i]<<endl;
}

void getSumaByTip(Service& s)
{
    char* tip = new char[10];
    cout<<"Dati tipul cheltuielii:"<<endl;
    cin>>tip;
    cout<<s.getSumaByTip(tip);
}

void maxCheltuialaPerAp(Service& s)
{
    int ap;
    cout<<"Dati apartamentul:"<<endl;
    cin>>ap;
    cout<<"Cheltuiala maxima a apartamentului "<<ap<<" este:"<<endl<<s.maxCheltuialaPerAp(ap);
}


void sortCheltuieliByType(Service& s)
{
    int n;
    char* tip = new char[10];
    cout<<"Dati tipul"<<endl;
    cin>>tip;
    Cheltuiala* listaCheltuieli = s.sortCheltuieliByType(tip,n);
    for(int i=0; i<n;i++)
        cout<<listaCheltuieli[i]<<endl;
}

void filterByType(Service& s)
{
    cout<<"Dati tipul: ";
    char* type = new char[10];
    cin>>type;
    s.filterByType(type);
}


void filterByCond(Service& s)
{
    int nr;
    cout<<"Dati numarul: ";
    cin>>nr;
    s.filterByCond(nr);
}

void undo(Service& s)
{
    s.undo();
}
