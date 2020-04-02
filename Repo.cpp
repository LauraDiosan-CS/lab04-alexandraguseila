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
    /*Cheltuiala* listaCheltuieli = new Cheltuiala[this->nrCheltuieli];
    for(int i=0; i<this->nrCheltuieli; i++)
        listaCheltuieli[i] = this->cheltuieli[i];
    return listaCheltuieli;*/
    return this->cheltuieli;
}

void Repo::addCheltuiala(Cheltuiala& c)
{
	this->cheltuieli[this->nrCheltuieli++] = c;
}

void Repo::updateCheltuiala(Cheltuiala initialChelt, Cheltuiala modifiedChelt)
{
    for(int i=0; i<this->nrCheltuieli; i++)
        if(this->cheltuieli[i] == initialChelt)
        {
            this->cheltuieli[i] = modifiedChelt;
        }
}

void Repo::deleteCheltuiala(Cheltuiala &c)
{
    /*for(int i=0;i<this->nrCheltuieli;i++)
        if(this->cheltuieli[i]== c)
        {
            for(int j=i; j<this->nrCheltuieli-1; j++)
                this->cheltuieli[i] = this->cheltuieli[i+1];
            this->nrCheltuieli--;
            i--;
        }*/
    int pos;
    int nr = this->nrCheltuieli;
	for (int i = 0; i < nr; i++)
		if (this->cheltuieli[i] == c)
		{
			pos = i;
			break;
		}
	for (int i = pos; i < nr - 1; i++)
		this->cheltuieli[i] = this->cheltuieli[i + 1];
	this->nrCheltuieli--;
}
