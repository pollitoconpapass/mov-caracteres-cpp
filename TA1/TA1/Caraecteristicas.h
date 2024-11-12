//Caraecteristicas.h
#pragma once
#include <iostream>
using namespace std;
using namespace System;

class Caracteristicas {
protected:
	int x, y;
	int velx, vely;
	int ancho, alto;
public:
	Caracteristicas() {}
	~Caracteristicas() {}

	//esta clase heredara todos los atributos a los demás. 
};
