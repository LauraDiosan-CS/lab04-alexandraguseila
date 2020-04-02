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
    Cheltuiala c3(2, 200, newTip);
    r.updateCheltuiala(c1, c3);
    assert(r.getAll()[0].getApartament()==2);
    assert(r.getAll()[0].getSuma()==200);
    assert(strcmp(r.getAll()[0].getTip(), newTip)==0);

    //getNrCheltuieli
    assert(r.getNrCheltuieli()==2);

    //Stergere
    r.deleteCheltuiala(c2);
    assert(r.getNrCheltuieli()==1);
    r.deleteCheltuiala(c1);
    assert(r.getNrCheltuieli()==0);
}

void testService()
{
    Service s;
    //Adaugare
    char* gaz = new char[10];
	strcpy(gaz,"gaz");
	Cheltuiala c(1, 100, gaz);
	s.add(c);
    assert(s.getAll()[0].getApartament()==1);
    assert(s.getAll()[0].getSuma()==100);
    assert(strcmp(s.getAll()[0].getTip(), gaz)==0);

    //Modificare
    Cheltuiala c2(1, 200, gaz);
    s.updateCheltuiala(s.getAll()[0], c2);
    assert(s.getAll()[0].getSuma() == 200);

    //getNrCheltuieli()
    assert(s.getNrCheltuieli()==1);

    //Stergere
    s.del(s.getAll()[0]);
    assert(s.getNrCheltuieli()==0);

    //getSumaByTip
    Cheltuiala c3(2, 100, gaz);
    s.add(c3);
    s.add(c);
    assert(s.getSumaByTip(gaz) == 200);

    //maxCheltuialaPerAp
    s.add(c2);
    assert(s.maxCheltuialaPerAp(1) == c);
    assert(s.getNrCheltuieli()==3);

    //showAllByApartament
    //Cheltuiala c(1, 100, gaz);
    //Cheltuiala c2(1, 200, gaz);
    //Cheltuiala c3(2, 100, gaz);
    Cheltuiala* lista = new Cheltuiala[10];
    int lenLista=0;
    lista = s.showAllByApartament(1, lenLista);
    assert(lenLista == 2);
    assert(lista[0] == c);
    assert(lista[1] == c2);
    delete[] lista;

    //showAllBySum
    Cheltuiala* lista2 = new Cheltuiala[10];
    lista2 = s.showAllBySum(100, lenLista);
    assert(lenLista == 1);
    assert(lista2[0] == c2);
    delete[] lista2;

    //showAllEqualToSum
    Cheltuiala* lista3 = new Cheltuiala[10];
    lista3 = s.showAllEqualToSum(100, lenLista);
    assert(lenLista == 2);
    assert(lista3[0] == c3);
    assert(lista3[1] == c);
    delete[] lista3;

    //sortCheltuieliByType
    Cheltuiala* lista4 = new Cheltuiala[10];
    lista4 = s.sortCheltuieliByType(gaz, lenLista);
    assert(lenLista == 3);
    assert(lista4[0] == c2);
    assert(lista4[1] == c3);
    assert(lista4[2] == c);
    delete[] lista4;

    //removeCheltuialaByApartament
    s.removeCheltuialaByAp(1);
    assert(s.getNrCheltuieli()==1);
    assert(s.getAll()[0]==c3);

    //removeCheltuialaByApartament
    s.add(c);
    s.removeCheltuialaBySum(100);
    assert(s.getNrCheltuieli()==0);












}

