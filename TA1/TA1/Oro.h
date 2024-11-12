//Oro.h
#pragma once
#include<iostream>
#include "Caraecteristicas.h"
class Oro : public Caracteristicas
{
public:
	Oro();
	~Oro();
	void Imprimir();
	int Devolver_x();
	int Devolver_y();
private:
	char caracter;
};

Oro::Oro()
{
	x = rand() % 90 + 1;
	y = rand() % 22 + 1;
	alto = 1;
	ancho = 1;
	caracter = (char)219;
}

Oro::~Oro()
{
}
void Oro::Imprimir()
{
	Console::ForegroundColor = ConsoleColor::Yellow;
	Console::SetCursorPosition(x, y);  cout << caracter;
}
int  Oro::Devolver_x() { return x; }
int  Oro::Devolver_y() { return y; }

