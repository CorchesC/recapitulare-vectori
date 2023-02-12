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
void bubbleSort(int v[], int dim) {
	bool aff = true;
	do {
		aff = true;
		for (int j = 0; j < dim - 1; j++) {
			if (v[j] > v[j + 1]) {
				int aux = v[j];
				v[j] = v[j + 1];
				v[j + 1] = aux;
				aff = false;
			}
		}
	} while (aff == false);
}
void bubbleSortDescDupaFractie(int v[], int dim) {
	bool aff = true;
	do {
		aff = true;
		for (int j = 0; j < dim - 1; j++) {
			if ((v[j] % 10) < (v[j + 1] % 10)) {
				int aux = v[j];
				v[j] = v[j + 1];
				v[j + 1] = aux;
				aff = false;
			}
		}
	} while (aff == false);
}
void sortareSol4(int v[], int dim) {
	bubbleSort(v, dim);
	bubbleSortDescDupaFractie(v, dim);
}
int elementMaximPoz(int v[], int dim) {
	int eMax = -1;
	int poz = 0;
	for (int i = 0; i < dim; i++) {
		if (v[i] > eMax) {
			eMax = v[i];
			poz = i;
		}
	}
	return poz;
}
int elementMinimPoz(int v[], int dim) {
	int eMin = 9999;
	int poz = 0;
	for (int i = 0; i < dim; i++) {
		if (v[i] < eMin) {
			eMin = v[i];
			poz = i;
		}
	}
	return poz;
}
void numaratorNumintor(int v[], int dim) {
	while (dim > 0) {
		int max = elementMaximPoz(v, dim);
		int min = elementMinimPoz(v, dim);
		cout << v[max] << " " << v[min] << endl;
		stergere(v, dim, max);
		stergere(v, dim, min);
	}
}
int nrCifre(int n) {
	int nrc = 0;
	while (n != 0) {
		nrc++;
		n = n / 10;
	}
	return nrc;
}
int alipireDouaNumerePozitive(int n, int m) {
	if (n < 0) {
		n = n * (-1);
	}
	if (m < 0) {
		m = m * (-1);
	}
	int nrM = nrCifre(m); 
	int pwr = pow(10, nrM);
	int nrNou = (n * pwr) + m;
	return nrNou;
}
void alipireSol6(int v[], int& dim) {
	for (int i = 0; i < dim-1; i++) {
		if (v[i] < 0 && v[i + 1] > 0) {
			inserare(v, dim, i+1, alipireDouaNumerePozitive(v[i], v[i + 1]));
			i++;
		}
		if (v[i] > 0 && v[i + 1] < 0) {
			inserare(v, dim, i+1, alipireDouaNumerePozitive(v[i], v[i + 1]));
			i++;
		}
	}
}
int sumaElemente(int v[], int dim) {
	int s = 0;
	for (int i = 0; i < dim; i++) {
		s += v[i];
	}
	return s;

}


void stergereSol7(int v[], int&dim,int k) {
	int smax = -1;
	int poz = 0;
	int ct = 0;
	int n = dim;
	while (ct < n) {
		for (int i = k; i < dim; i += k) {
			stergere(v, dim, i);
		}
		afisare(v, dim);
		//logica suma
		int s = sumaElemente(v, dim);
		if (s > smax) {
			smax = s;
			poz = ct;
		}
		ct++;
	}
	cout << smax << " " << poz << endl;
}