#ifndef vector_h
#define vector_h

#include <iostream>

class vector
{
	int c;//capacidad 
	int s;//tamaño real
	int* data;

public:
	vector(int);
	~vector();

	void push(int);
	int pop();
	bool isEmpty();
	int currentData();
	int currentCapacity();
	void printPile();
};
#endif
