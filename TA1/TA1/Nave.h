#pragma once
#include <iostream>
#include "Caraecteristicas.h"
using namespace std;

class Nave : public Caracteristicas {
private:
    int vidas;
    // private pq solo hay vidas para la nave 
public:
    Nave() {
        x = 3; y = 10;
        velx = vely = 0;
        alto = 1;
        ancho = 9;
        vidas = 5;
    }
    ~Nave() {}
    Nave(int _x, int _y) {
        this->x = _x;
        this->y = _y;
    }

    //Ahora: Borrar, Mover, Mostrar
    void Borrar() {
        Console::SetCursorPosition(x, y + 0);
        cout << "       ";
    }
    void Mover() {
        if (y + vely < 0 || y + vely + alto > 25) vely = 0; // si excede los limites de la pantalla eje y
        if (x + velx < 0 || x + velx + ancho > 110) velx = 0; // si excede los limites de la pantalla eje x
        y += vely;
        x += velx;
    }
    void Mostrar() {
        Console::SetCursorPosition(x, y);
        Console::ForegroundColor = ConsoleColor::DarkMagenta;
        cout << "<<'@'>>";
    }

    // Otras funciones de la nave
    void EliminarVida() {
        vidas--;
    }
    void Direccion(int _x, int _y) {
        velx = _x; vely = _y;
    }
    void pos_inicial() {
        x = 5; y = 20;
    }

    //Metodos get
    int get_x() { return x; }
    int get_x1() { return x + 1; }
    int get_x2() { return x + 2; }
    int get_x3() { return x + 3; }
    int get_x4() { return x + 4; }
    int get_x5() { return x + 5; }
    int get_x6() { return x + 6; }
    int get_x7() { return x + 7; }
    int get_x8() { return x + 8; }
    int get_y() { return y; }
    int get_vidas() { return vidas; }

};

