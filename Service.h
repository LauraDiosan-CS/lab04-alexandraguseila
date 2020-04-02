#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED

#include "Repo.h"

class Service
{
private:
    Repo repository;
    struct undoStruct
    {
        Cheltuiala undo[100];
        int operation;
    }lista[100];
    int lenLista;
public:
    Service();
    Service(Repo repository);
    ~Service();
    void add(Cheltuiala c);
    void del(Cheltuiala c);
    void updateCheltuiala(Cheltuiala initialChelt, Cheltuiala modifiedChelt);
    Cheltuiala* getAll();
    int getNrCheltuieli();

    void removeCheltuialaByAp(int ap);
    void removeCheltuialaBySum(int suma);
    void removeCheltuialaByType(char* tip);

    Cheltuiala* showAllByApartament(int ap, int& n);
    Cheltuiala* showAllBySum(int sum, int& n);
    Cheltuiala* showAllEqualToSum(int sum, int& n);

    int getSumaByTip(char* tip);
    Cheltuiala maxCheltuialaPerAp(int ap);
    Cheltuiala* sortCheltuieliByType(char* tip, int& length);

    void filterByType(char* type);
    void filterByCond(int nr);

    void undo();
};

#endif // SERVICE_H_INCLUDED
