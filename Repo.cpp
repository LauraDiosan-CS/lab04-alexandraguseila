#include "Repo.h"

Repo::Repo()
{
	this->nrCheltuieli = 0;
}

Repo::~Repo()
{

}

void Repo::addCheltuiala(Cheltuiala& c)
{
	this->cheltuieli[this->nrCheltuieli++] = c;
}

Cheltuiala Repo::getCheltuiala(int pozitie)
{
	return this->cheltuieli[pozitie];
}

int Repo::getNrCheltuieli()
{
	return this->nrCheltuieli;
}
