#include "Cheltuiala.h"
#include <string.h>


Cheltuiala::Cheltuiala()
{
	this->apartament = 0;
	this->suma = 0;
	this->tip = NULL;
}

Cheltuiala::Cheltuiala(int ap, int suma, char* tip)
{
	this->apartament = ap;
	this->suma = suma;
	this->tip = new char[strlen(tip)+1];
	strcpy(this->tip, tip);
}

Cheltuiala::Cheltuiala(const Cheltuiala &c)
{
	this->apartament = c.apartament;
	this->suma = c.suma;
	this->tip = new char[strlen(c.tip) + 1];
	strcpy(this->tip, c.tip);
}

Cheltuiala::~Cheltuiala()
{
	if (this->tip)
	{
		delete[] this->tip;
		this->tip = NULL;
	}
}

int Cheltuiala::getApartament()
{
	return this->apartament;
}

int Cheltuiala::getSuma()
{
	return this->suma;
}

char* Cheltuiala::getTip()
{
	return this->tip;
}

void Cheltuiala::setApartament(int newAp)
{
	this->apartament = newAp;
}

void Cheltuiala::setSuma(int newSuma)
{
	this->suma = newSuma;
}

void Cheltuiala::setTip(char* newTip)
{
	if (this->tip)
		delete[] this->tip;
	this->tip = new char[strlen(newTip) + 1];
	strcpy(this->tip, newTip);
}

bool Cheltuiala::operator==(const Cheltuiala &c)
{
    return ((this->apartament==c.apartament) && (this->suma==c.suma) && (strcmp(this->tip, c.tip)==0));
}

/*void Cheltuiala::afiseaza(Cheltuiala &c)
{
    printf("Cheltuiala %d:%d:%d", c.apartament, c.suma, c.tip);

}*/

std::ostream& operator<<(std::ostream& os, const Cheltuiala& c )
{
    os<<c.apartament<<" "<<c.suma<<" "<<c.tip;
    return os;
}


