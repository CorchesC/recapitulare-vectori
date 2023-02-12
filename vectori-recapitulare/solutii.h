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
	//(32) Se considera un vector cu n elemente naturale. Sa se afiseze pe linii, elementele din A grupate dupa cifra dominanta (prima in scrierea zecoimala). Pe aceeasi linie vor fi scrise elementele cu acceasi cifra dominanta.
	int v[100], d = 0;
	citire(v, d);
	afisareElementeCuCifraDominantaComuna(v,d);
}
void sol3() {
	//(33) Fie un tablou unidimensional cu n elemente valori naturale. Sa se ordoneze descrescator aceste valor dupa numarul de cifre distincte pe care le contin.
	int v[100], d = 0;
	citire(v, d);
	bubbleSortDescDupaNrCifreDistincte(v, d);
	afisare(v, d);
}
void sol4() {
	//(34) Se considera un vector cu n elemente numere reale. Sa se orodneze elementele crescator dupa valoarea partiilor intregi a elementelor, iat la valori cu partea intreaga egala, oronarea se va face descrescator dupa partea fractionara.
	int v[100], d = 0;
	citire(v, d);
	sortareSol4(v, d);
	afisare(v, d);
}
void sol5() {
	//(35) Consideram un tablu unidimensional ce contine un numar par de eleemnte (2*n). Creati cu aceste valori un sir de n fractii a caror suma este maxima. Fiecare fractie se va afisa pe cate o linie printr-0 pereche de numere reprezentand in ordine "numarator- numitor"
	int v[100], d = 0;
	citire(v, d);
	numaratorNumintor(v, d);
}
void sol6() {
	//(36) Se considera un vector ce contine n elemente inregi. In fata orcarui element precedat de un element se semn contar se introduce un element pozitiv, a carui valaore este obtinuta prin alipriea cifrelor celor doua numere de semne contrare in ordine.
	//Sa se afiseze continutul vectorului dupa efectuarea operatiilor cerute.
	int v[100], d = 0;
	citire(v, d);
	alipireSol6(v, d);
	afisare(v, d);
}
void sol7() {
	//Fie un tablou unidimensional cu 2*n elemente valori naturale. Din vector sunt sterse pe rand elemente din k in k pozitii. Numararea pozitiilor se va face cu revenire la prima in cazul in care indicele curent este mai mare decat n. Operatia se repeta de n ori.
	//Determinati pozitia de inceput a numaratorii, astfel incat elementele ramase sa aiba suma maxima. Se va afisa pozitia de inceput a numaratorii si suma elementelor ramse in vector.
	int v[100], d = 0;
	citire(v, d);
	cout << "Introduceti k: " << endl;
	int k;
	cin >> k;
	stergereSol7(v,d,k);
}