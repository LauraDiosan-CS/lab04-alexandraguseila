#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED
#include "Service.h"

void menu();
void menuAfisare();
void menuFiltrare();
void menuStergere();
void console(Service& s);
void addCheltuiala(Service& s);
void removeCheltuiala(Service& s);
void updateCheltuiala(Service& s);
void showAll(Service &s);
void removeCheltuialaByAp(Service& s);
void removeCheltuialaBySum(Service& s);
void removeCheltuialaByType(Service& s);
void showAllByApartament(Service& s);
void showAllBySum(Service& s);
void showAllEqualToSum(Service& s);
void getSumaByTip(Service& s);
void maxCheltuialaPerAp(Service& s);
void sortCheltuieliByType(Service& s);
void filterByType(Service& s);
void filterByCond(Service& s);
void undo(Service& s);


#endif // UI_H_INCLUDED
