#pragma once
#include "functii.h"
using namespace std;

void sol1() {
	//(31) Sa se stearga din vectorul A de lungime n, un numar de elemente astfel incat la final sa se obtina un sir strict crescator de elemente. Primul element din vectorul initial nu se va sterge.
	int v[100], d = 0;
	citire(v, d);
	stergereCrescator(v, d);
	afisare(v, d);
}
void sol2() {
	//Se considera un vector cu n elemente naturale. Sa se afiseze pe linii, elementele din A grupate dupa cifra dominanta (prima in scrierea zecoimala). Pe aceeasi linie vor fi scrise elementele cu acceasi cifra dominanta.
	int v[100], d = 0;
	citire(v, d);
	afisareElementeCuCifraDominantaComuna(v,d);
}