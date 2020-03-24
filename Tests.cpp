#include "Tests.h"
#include "Cheltuiala.h"
#include "Repo.h"
#include "Service.h"
#include <assert.h>
#include <string.h>
#include <iostream>
using namespace std;

void testCheltuiala()
{
	char* gaz = new char[10];
	strcpy(gaz,"gaz");
	Cheltuiala c1(1, 100, gaz);
		assert(c1.getApartament() == 1);
		assert(c1.getSuma()== 100);
		assert(strcmp(c1.getTip(), gaz)==0);
		c1.setApartament(2);
		c1.setSuma(46);
		char* lumina = new char[10];
		strcpy(lumina, "lumina");
        c1.setTip(lumina);
        assert(c1.getApartament() == 2);
		assert(c1.getSuma()== 46);
		assert(strcmp(c1.getTip(), lumina)==0);
		//cout<<c1;

}

void testRepo()
{
    //Adaugare
    char* gaz = new char[10];
    char* lumina = new char[10];
    strcpy(gaz, "gaz");
    strcpy(lumina, "lumina");
    Cheltuiala c1(1, 100, gaz);
    Cheltuiala c2(2, 50, lumina);
    Repo r;
    r.addCheltuiala(c1);
    r.addCheltuiala(c2);
    assert(r.getNrCheltuieli()==2);
    assert(r.getCheltuiala(0).getApartament()==c1.getApartament());
    assert(r.getCheltuiala(0).getSuma()==c1.getSuma());
    assert(strcmp(r.getCheltuiala(0).getTip(),c1.getTip())==0);

    //Operatorul ==
    assert(c1==c1);

    //getAll()
    Cheltuiala* lista= new Cheltuiala[10];
    lista = r.getAll();
    assert(lista[0]==c1);
    assert(lista[1]==c2);

    //Modificare
    char* newTip = new char[5];
    strcpy(newTip, "caldura");
    r.updateCheltuiala(c1, 2, 200, newTip);
    assert(r.getAll()[0].getApartament()==2);
    assert(r.getAll()[0].getSuma()==200);
    assert(strcmp(r.getAll()[0].getTip(), newTip)==0);

    //getNrCheltuieli
    assert(r.getNrCheltuieli()==2);

    //Stergere
    int stergere = r.deleteCheltuiala(c2);
    assert(stergere == 1);
    assert(r.getNrCheltuieli()==1);
    stergere = r.deleteCheltuiala(c2);
    assert(stergere == -1);
    assert(r.getNrCheltuieli()==1);
}

void testService()
{
    Service s;
    //Adaugare
    char* gaz = new char[10];
	strcpy(gaz,"gaz");
	s.add(1, 100, gaz);
    assert(s.getAll()[0].getApartament()==1);
    assert(s.getAll()[0].getSuma()==100);
    assert(strcmp(s.getAll()[0].getTip(), gaz)==0);

    //Modificare
    s.update(s.getAll()[0], 1, 200, gaz);
    assert(s.getAll()[0].getSuma() == 200);

    //getNrCheltuieli()
    assert(s.getNrCheltuieli()==1);

    //Stergere
    assert(s.del(s.getAll()[0])==1);
    assert(s.getNrCheltuieli()==0);


}

