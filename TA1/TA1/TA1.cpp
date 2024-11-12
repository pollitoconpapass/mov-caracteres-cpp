// Main.cpp
#include"pch.h"
#include <iostream>
#include <conio.h>
#include "Mando.h"
using namespace std;
using namespace System;

//using namespace System; (este pal visual)

int main() {
    Console::SetWindowSize(115, 40);
    Console::CursorVisible = false;
    Mando* obj = new Mando();
    obj->Generar_Oro();
    do {
        obj->Imprimir_vida_oro();
        obj->ComenzarJuego();
        obj->Imprimir_Oro();
        obj->Choque_Oro_nave();
        obj->Recolectar_oro();
        obj->Aparece_Carro();
        if (!obj->Choque_ovni_nave()) break;
        if (obj)
            if (_kbhit()) {
                switch (toupper(_getch())) {
                case 72: obj->Mover_Nave(1); break;
                case 75: obj->Mover_Nave(2); break;
                case 80: obj->Mover_Nave(3); break;
                case 77: obj->Mover_Nave(4); break;
                }
            }
        _sleep(100);
    } while (obj->Get_vidas() > 0);
    system("cls");
    Console::SetCursorPosition(50, 20); cout << "CANTIDAD DE ORO RECOLECTADO:" << obj->get_contador();
    Console::SetCursorPosition(50, 22); cout << "JUEGOS: "; if (obj->get_contador() > 1 || obj->get_contador() <= 5) { cout << "1"; }
    if (obj->get_contador() > 5 && obj->get_contador() <= 10) { cout << "2"; }
    if (obj->get_contador() > 10 && obj->get_contador() <= 15) { cout << "3"; }
    if (obj->get_contador() > 15 && obj->get_contador() <= 20) { cout << "4"; }
    if (obj->get_contador() > 20 && obj->get_contador() <= 25) { cout << "5"; }

    _getch();
    return 0;
}
