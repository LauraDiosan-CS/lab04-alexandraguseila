#include "Service.h"
#include "Repo.h"

Service::Service()
{
    this->repository = Repo();
}

Service::Service(Repo repository)
{
    this->repository = repository;
}

Service::~Service()
{

}

void Service::add(int ap, int s, char* tip)
{
    Cheltuiala c(ap, s, tip);
    repository.addCheltuiala(c);
}

void Service::update(Cheltuiala c,int newAp,int newSuma,char* newTip)
{
    repository.updateCheltuiala(c, newAp, newSuma, newTip);
}

int Service::del(Cheltuiala c)
{
    return repository.deleteCheltuiala(c);
}

Cheltuiala* Service::getAll()
{
    return repository.getAll();
}

int Service::getNrCheltuieli()
{
    return this->repository.getNrCheltuieli();
}

