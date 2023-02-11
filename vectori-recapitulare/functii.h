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
int cifraDominanta(int n) {
	int cd = 0;
	while (n != 0) {
		int cifra = n % 10;
		cd = cifra;
		n = n / 10;
	}

	return cd;
}
void afisareElementeCuCifraDominantaComuna(int v[], int dim) {
	for (int i = 0; i < 10; i++) {
		for (int x = 0; x < dim; x++) {
			if (cifraDominanta(v[x]) == i) {
				cout << v[x] << " ";
			}
		}
	}
}
int nrCifreDistincte(int n) {
	int nrc = 0;
	while (n != 0) {
		int cifra = n % 10;
		int nr = n;
		int x = 0;
		for (int i = 0; nr > 0; nr = nr / 10) {
			i = nr % 10;
			if (i == cifra) {
				x++;
			}
		}
		if (x <= 1) {
			nrc++;
		}
		n = n / 10;
	}
	return nrc;
}
void bubbleSortDescDupaNrCifreDistincte(int v[], int dim) {
	bool aff = true;
	do {
		aff = true;
		for (int j = 0; j < dim - 1; j++) {
			if (nrCifreDistincte(v[j]) < nrCifreDistincte(v[j + 1])) {
				int aux = v[j];
				v[j] = v[j + 1];
				v[j + 1] = aux;
				aff = false;
			}
		}
	} while (aff == false);
}