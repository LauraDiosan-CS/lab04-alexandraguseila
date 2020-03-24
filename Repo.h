#ifndef REPO_H_INCLUDED
#define REPO_H_INCLUDED

#pragma once
#include "Cheltuiala.h"

class Repo
{
private:
	Cheltuiala cheltuieli[50];
	int nrCheltuieli;
public:
	Repo();
	~Repo();
	Cheltuiala getCheltuiala(int pozitie);
	int getNrCheltuieli();
	Cheltuiala* getAll();
	void addCheltuiala(Cheltuiala &c);
	void updateCheltuiala(Cheltuiala c, int newAp, int newSuma, char* newTip);
	int deleteCheltuiala(Cheltuiala &c);

};

#endif // REPO_H_INCLUDED
