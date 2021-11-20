/*
AUTOR: Oscar Noe Ortiz Barba
CURSO: Diseño y análisis de algoritmos
PROGRAMA: Vector dinamico
FECHA: 28/10/2021
*/

#include <iostream>
#include <ctime>
#include "vector.h"

using namespace std;

int main() {
	srand((unsigned)time(nullptr));

	vector* v = new vector(1);

	int n;
	cout << "n: ";
	cin >> n;

	for (int i = 0; i < (4 * n); i++) {
		int insOrOut = rand() % 2;
		int newData = rand() % (10 * n) + 1;
		if (insOrOut) {
			v->push(newData);
			cout << "ins  " << newData << " : ";
		}
		else {
			cout << "out  " << v->pop() << " : ";
			if ((v->currentCapacity() / 4) == v->currentData() && v->currentData() >= 1) {
				vector* aux = new vector(v->currentCapacity() / 4);
				for (int j = 0; j < aux->currentCapacity(); j++) {
					aux->push(v->pop());
				}
				v = new vector(v->currentCapacity()/2);
				for (int j = 0; j < aux->currentCapacity(); j++) {
					v->push(aux->pop());
				}
			}
			else if ((v->currentCapacity() == 2 && v->currentData() == 0)) {
				v = new vector(1);
			}
		}
		 v->printPile();
	}

	return 0;
}