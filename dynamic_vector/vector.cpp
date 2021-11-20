#include "vector.h"

vector::vector(int _c): c(_c), s(0), data(new int[_c]) {
	for (int i = 0; i < c; i++) {
		data[i] = 0;
	}
}

vector::~vector() {
	int* z = nullptr;
	data = z;
	delete[] data; 
}

void vector::push(int x) { 
	if (currentCapacity() == currentData()) {
		vector copy(currentCapacity());
		for (int i = 0; i < currentCapacity(); i++) {
			copy.push(pop());
		}
		data = new int[currentCapacity() * 2];
		c = currentCapacity() * 2;
		s = 0;
		for (int i = 0; i < currentCapacity() / 2; i++) {
			data[i] = 0;
			push(copy.pop());
		}
	}
	data[s++] = x;
}

int vector::pop() {
	int x = data[s-1];
	data[s - 1] = 0;
	if (x && !isEmpty()) {
		s--;
		return x;
	}
	return 0;
}

bool vector::isEmpty() { return (s == 0) ? true : false; }

int vector::currentData() { return s; }

int vector::currentCapacity() { return c; }

void vector::printPile() { 
	std::cout << "[ ";
	for (int i = 0; i < c; i++) {
		if (data[i] && i < s) std::cout << "  " << data[i];
		else std::cout << "    ";
	}
	std::cout << " ]\n";
}