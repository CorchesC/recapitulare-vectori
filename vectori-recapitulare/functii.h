#pragma once
#include <iostream>
#include <fstream>
using namespace std;

void citire(int v[], int& dim) {

	ifstream f("numere.txt");

	f >> dim;
	for (int i = 0; i < dim; i++) {

		f >> v[i];
	}

	f.close();
}
void afisare(int v[], int dim) {
	for (int i = 0; i < dim; i++) {
		cout << v[i] << " ";
	}
	cout << endl;

}
void stergere(int v[], int& dim, int poz) {
	for (int i = poz; i < dim; i++) {
		v[i] = v[i + 1];
	}
	dim--;
}
void inserare(int v[], int& dim, int poz, int nou) {
	for (int i = dim; i >= poz; i--) {
		v[i + 1] = v[i];
	}
	dim++;
	v[poz] = nou;
}
void stergereCrescator(int v[], int& dim) {
	for (int i = 1; i < dim-1; i++) {
		while (v[i] > v[i + 1]) {
			stergere(v, dim, i + 1);
		}
	}
}
