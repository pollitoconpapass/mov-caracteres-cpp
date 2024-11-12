#pragma once
#include "Entidad.h"

class Avion9 : public Entidad {
public:
	Avion9() : Entidad() {
		ancho = 16; alto = 4;
		x = rand() % (ANCHO - ancho);
		y = rand() % (ALTO - alto);
	}

	void Mostrar() {
		Console::ForegroundColor = color;
		Console::SetCursorPosition(x, y + 0); cout << "        ..        ";
		Console::SetCursorPosition(x, y + 1); cout << "._______||________.";
		Console::SetCursorPosition(x, y + 2); cout << "     \\(**)/       ";
		Console::SetCursorPosition(x, y + 3); cout << "      o/ \\o      ";

	}
};