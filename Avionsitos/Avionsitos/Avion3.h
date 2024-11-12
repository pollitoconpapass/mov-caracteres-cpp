#pragma once
#include "Entidad.h"

class Avion3 : public Entidad {
public:
	Avion3() : Entidad() {
		ancho = 7; alto = 2;
		x = rand() % (ANCHO - ancho);
		y = rand() % (ALTO - alto);
	}

	void Mostrar() {
		Console::ForegroundColor = color;
		Console::SetCursorPosition(x, y + 0); cout << "   |   ";
		Console::SetCursorPosition(x, y + 1); cout << "--=o=--";
	}
};
