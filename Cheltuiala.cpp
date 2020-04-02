#include "Cheltuiala.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

std::ostream& operator<<(std::ostream& os, const Cheltuiala& c )
{
    os<<c.apartament<<" "<<c.suma<<" "<<c.tip;
    return os;
}

std::istream& operator>>(std::istream& is,Cheltuiala& c)
{
    int ok=1;
    char ap[6], s[10];
    int intAp, intS;
    char* tip= new char[10];
    while(ok==1)
    {
        std::cout<<"Dati numarul apartamentului: ";
        std::cin>>ap;
        for(int i=0; i<strlen(ap);i++)
            if(!isdigit(ap[i]))
            {
                std::cout<<"Numarul aprtamentului trebuie sa fie int!";
                ok = 0;
            }
            else
                {
                    intAp = atoi(ap);
                    if(intAp < 0)
                    {
                        std::cout<<"Nr apartamentului trebuie sa fie pozitiv!";
                        ok = 0;
                    }
                    else
                    {
                        std::cout<<"Dati suma: ";
                        std::cin>>s;
                        for(int i=0; i<strlen(s);i++)
                            if(!isdigit(s[i]))
                            {
                                std::cout<<"Suma trebuie sa fie int!";
                                ok = 0;
                            }
                            else
                            {
                                intS = atoi(s);
                                if(intS < 0)
                                {
                                    std::cout<<"Suma trebuie sa fie nr pozitiv!";
                                    ok = 0;
                                }
                                else
                                {
                                    std::cout<<"Dati tipul cheltuielii: ";
                                    is>>tip;
                                    c.setApartament(intAp);
                                    c.setSuma(intS);
                                    c.setTip(tip);
                                    delete[]tip;
                                    return is;
                                }
                            }

                }

        }


    }
}

/*std::istream& operator>>(std::istream& is,Cheltuiala& c)
{
    int ap, s;
    std::cout<<"Dati numarul apartamentului: ";
    std::cin>>ap;
    std::cout<<"Dati suma: ";
    std::cin>>s;
    char* tip= new char[10];
    std::cout<<"Dati tipul cheltuielii: ";
    is>>tip;
    c.setApartament(ap);
    c.setSuma(s);
    c.setTip(tip);
    delete[]tip;
    return is;


}*/




