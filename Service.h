#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED

#include "Repo.h"

class Service
{
private:
    Repo repository;
public:
    Service();
    Service(Repo repository);
    ~Service();
    void add(int ap, int s, char* tip);
    int del(Cheltuiala c);
    void update(Cheltuiala c, int newAp,int newSuma,char* newTip);
    Cheltuiala* getAll();
    int getNrCheltuieli();
};

#endif // SERVICE_H_INCLUDED
