#include "Repo.h"
#include <iostream>
using namespace std;

Repo::Repo()
{
	this->nrCheltuieli = 0;
}

Repo::~Repo()
{

}

Cheltuiala Repo::getCheltuiala(int pozitie)
{
	return this->cheltuieli[pozitie];
}

int Repo::getNrCheltuieli()
{
	return this->nrCheltuieli;
}

Cheltuiala* Repo::getAll()
{
    Cheltuiala* listaCheltuieli = new Cheltuiala[this->nrCheltuieli];
    for(int i=0; i<this->nrCheltuieli; i++)
        listaCheltuieli[i] = this->cheltuieli[i];
    return listaCheltuieli;
}

void Repo::addCheltuiala(Cheltuiala& c)
{
	this->cheltuieli[this->nrCheltuieli++] = c;
}

void Repo::updateCheltuiala(Cheltuiala c,int newAp, int newSuma, char* newTip)
{
    for(int i=0; i<this->nrCheltuieli; i++)
        if(this->cheltuieli[i] == c)
        {
            cheltuieli[i].setApartament(newAp);
            cheltuieli[i].setSuma(newSuma);
            cheltuieli[i].setTip(newTip);
        }
}

int Repo::deleteCheltuiala(Cheltuiala &c)
{
    for(int i=0;i<this->nrCheltuieli;i++)
        if(this->cheltuieli[i]== c)
        {
            for(int j=i; j<this->nrCheltuieli; j++)
                this->cheltuieli[i] = this->cheltuieli[i+1];
            this->nrCheltuieli--;
            return 1;
        }
    return -1;
}
