#include "Service.h"
#include "Repo.h"

Service::Service()
{
    this->repository = Repo();
    this->lenLista = 0;
}


Service::Service(Repo repository)
{
    this->repository = repository;
}

Service::~Service()
{

}

void Service::undo()
{
    if(lista[lenLista-1].operation == 1)
    {
        this->del(lista[lenLista-1].undo[lenLista-1]);
        lista[lenLista-1].undo[lenLista-1] = Cheltuiala();
        lenLista--;
    }
    else
        if(lista[lenLista-1].operation == 2)
        {
            this->add(lista[lenLista-1].undo[lenLista-1]);
            lista[lenLista-1].undo[lenLista-1] = Cheltuiala();
            lenLista--;
        }
}

void Service::add(Cheltuiala c)
{
    repository.addCheltuiala(c);
    lista[lenLista].undo[lenLista] = c;
    lista[lenLista].operation = 1;
    lenLista++;
}


void Service::del(Cheltuiala c)
{
    repository.deleteCheltuiala(c);
    lista[lenLista].undo[lenLista] = c;
    lista[lenLista].operation = 2;
    lenLista++;
}


void Service::updateCheltuiala(Cheltuiala initialChelt, Cheltuiala modifiedChelt)
{
    repository.updateCheltuiala(initialChelt, modifiedChelt);
}


Cheltuiala* Service::getAll()
{
    return repository.getAll();
}


int Service::getNrCheltuieli()
{
    return this->repository.getNrCheltuieli();
}


void Service::removeCheltuialaByAp(int ap)
{
    int i;
    for(i=0; i<this->getNrCheltuieli();i++)
       {
           if(this->getAll()[i].getApartament() == ap)
            {
                this->repository.deleteCheltuiala(this->getAll()[i]);
                i--;
            }
       }
}

void Service::removeCheltuialaBySum(int s)
{
    int i;
    for(i=0; i<this->getNrCheltuieli();i++)
        if(this->getAll()[i].getSuma() == s)
            {
                this->repository.deleteCheltuiala(this->getAll()[i]);
                i--;
            }
}

void Service::removeCheltuialaByType(char* tip)
{
    int i = 0;

	while (i < this->getNrCheltuieli())
        {

		if (strcmp(this->getAll()[i].getTip(), tip) == 0)
            {
			this->del(this->getAll()[i]);

            }
		else
			i++;
        }
}

Cheltuiala* Service::showAllByApartament(int ap, int& n)
{
    n=0;
    Cheltuiala* listaCheltuieli = new Cheltuiala[this->getNrCheltuieli()];
    for(int i=0; i<this->getNrCheltuieli();i++)
    {
        if(this->getAll()[i].getApartament()==ap)
        {
            listaCheltuieli[n++]=this->getAll()[i];
        }
    }
    return listaCheltuieli;
}

/*Cheltuiala* Service::getAllWithCondition(int parameter, char sign, int& length)
{
    length = 0;
    Cheltuiala* listaCheltuieli = new Cheltuiala[this->getNrCheltuieli()];
    for(int i=0; i<this->getNrCheltuieli();i++)
    {
        if(this->getAll()[i].getApartament()==ap)
        {
            listaCheltuieli[n++]=this->getAll()[i];
        }
    }
    return listaCheltuieli;

}*/

Cheltuiala* Service::showAllBySum(int sum, int& n)
{
    n=0;
    Cheltuiala* listaCheltuieli = new Cheltuiala[this->getNrCheltuieli()];
    for(int i=0; i<this->getNrCheltuieli();i++)
    {
        if(this->getAll()[i].getSuma()>sum)
        {
            listaCheltuieli[n++]=this->getAll()[i];
        }
    }
    return listaCheltuieli;
}

Cheltuiala* Service::showAllEqualToSum(int sum, int& n)
 {
    n=0;
    Cheltuiala* listaCheltuieli = new Cheltuiala[this->getNrCheltuieli()];
    for(int i=0; i<this->getNrCheltuieli();i++)
    {
        if(this->getAll()[i].getSuma() == sum)
        {
            listaCheltuieli[n++]=this->getAll()[i];
        }
    }
    return listaCheltuieli;
 }

int Service::getSumaByTip(char* tip)
 {
     int s=0;
     for(int i=0; i<this->getNrCheltuieli(); i++)
     {
         if(strcmp(this->getAll()[i].getTip(), tip)==0)
            s+=this->getAll()[i].getSuma();
     }
     return s;
 }

Cheltuiala Service::maxCheltuialaPerAp(int ap)
{
    int n=0, poz=0, i;
    Cheltuiala* listaCheltuieli = this->showAllByApartament(ap, n);
    int maxS = listaCheltuieli[0].getSuma();
    for(i=1; i<n; i++)
    {
        if(listaCheltuieli[i].getSuma()>maxS)
        {
            maxS = listaCheltuieli[i].getSuma();
            poz = i;
        }
    }
    return repository.getCheltuiala(poz);
}

Cheltuiala* Service::sortCheltuieliByType(char* tip, int& length)
{
    Cheltuiala* sortedCheltuieli = new Cheltuiala[this->getNrCheltuieli()];
    length = 0;
    for (int i = 0; i < this->getNrCheltuieli(); i++)
        if(strcmp(this->getAll()[i].getTip(), tip)==0)
            sortedCheltuieli[length++] = this->getAll()[i];

    int done = 1;
	while (done == 1)
        {
            done = 0;
            for(int i=0;i<length-1;i++)
                if (sortedCheltuieli[i].getSuma() < sortedCheltuieli[i + 1].getSuma())
                {
                    Cheltuiala aux;
                    aux = sortedCheltuieli[i];
                    sortedCheltuieli[i]= sortedCheltuieli[i+1];
                   sortedCheltuieli[i + 1] = aux;

                    done=1;
                }
        }
        return sortedCheltuieli;

}

void Service::filterByType(char* type)
{
	int i = 0;
	while (i < this->getNrCheltuieli())
    {
		if (strcmp(this->getAll()[i].getTip(), type) != 0)
		{
			this->del(this->getAll()[i]);

		}
		else
			i++;
	}
}

void Service::filterByCond(int nr)
{
	int i = 0;
	while (i < this->getNrCheltuieli())
    {
		if (this->getAll()[i].getSuma() >= nr)
			this->del(this->getAll()[i]);
		else
			i++;

	}
}

