//Auto.h
#pragma once
#include"Caraecteristicas.h"
class Auto :public Caracteristicas {
public:
    Auto() {
        x = 3;
        y = 2;
        vely = 1;
        velx = 1;
        ancho = 10;
        alto = 2;

    }
    ~Auto() {

    }
    //Borrar, Mover, Mostrar
    void Borrar() {
        Console::SetCursorPosition(x, y + 0); cout << "          ";
        Console::SetCursorPosition(x, y + 1); cout << "          ";
    }
    void Mover() {
        if (y + alto > 20) {
            vely *= -1;
        }if (y == 0) { vely = 0; }
        y += vely;
    }
    int get_y() {
        return y;
    }
    void Imprimir() {
        Console::ForegroundColor = ConsoleColor::White;
        Console::SetCursorPosition(x, y + 0); cout << "__| p \\__ ";
        Console::SetCursorPosition(x, y + 1); cout << "´-O---O--´";
    }
private:
};

