#pragma once
#include "Caraecteristicas.h"
class Ovni :public Caracteristicas {
public:
	Ovni(int dx, int dy) {
		velx = dx;
		vely = dy;
		x = rand() % 90 + 1;
		y = rand() % 22 + 1;
		alto = 3;
		ancho = 9;
	}
	~Ovni() {}
	void borrar() {
		Console::SetCursorPosition(x, y + 0); cout << "         ";
		Console::SetCursorPosition(x, y + 1); cout << "         ";
		Console::SetCursorPosition(x, y + 2); cout << "         ";

	}
	void mover() {
		if (x + velx < 0 || x + velx + ancho > 110) { velx *= -1; }
		x += velx;
	}

	void imprimir() {
		Console::ForegroundColor = ConsoleColor::Cyan;
		Console::SetCursorPosition(x, y + 0); cout << ".-WWWWW-.";
		Console::SetCursorPosition(x, y + 1); cout << " WO---OW ";
		Console::SetCursorPosition(x, y + 2); cout << "   ***   ";

	}
	int devolver_x() {
		return x;
	}
	int devolver_x1() {
		return x + 9;
	}

	int devolver_y() {
		return y;
	}
	int devolver_y1() { return y + 1; }
	int devolver_y2() { return y + 2; }

};

