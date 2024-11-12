#include "pch.h"
#include <iostream>
#include <conio.h>
using namespace System;
using namespace std;


int main() {
    char tecla;
    int x = 8;
    int y = 9;

    Console::CursorVisible = false;
    Console::SetCursorPosition(x, y);
    cout << char(219);

    while (tecla != char(27)) {
        tecla = getch();
        tecla = toupper(tecla); //-> A MAYUSCULAS
        Console::SetCursorPosition(x, y);
        cout << " ";
      
        // (Tomando en cuenta q el plano empieza desde la esquina superior izquierda de la consola.)
        if (tecla == char(65)) --x; //A
        if (tecla == char(68)) ++x; //D
        if (tecla == char(87)) --y;//W
        if (tecla == char(83)) ++y;//S

        Console::SetCursorPosition(x, y);
        cout << char(219);
    }
    return 0;
}
