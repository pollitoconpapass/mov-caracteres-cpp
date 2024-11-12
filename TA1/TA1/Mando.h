//Mando.h
#pragma once
#include <iostream>
#include<vector>
#include"Nave.h"
#include"Auto.h"
#include"Oro.h"
#include"Ovni.h"
using namespace std;

class Mando {
private:	
	   Ovni* ovniO1;
	   Ovni* ovniO2;
	   Ovni* ovniO3;
	   Nave* estrelladelamuerte;
	   Auto* Mccuinkuchau;
	   //xdd ya queda
	   vector<Oro*>vecO;
	   int cont;
public:
	Mando() {
		ovniO1 = new Ovni(-1, 0);
		ovniO2 = new Ovni(1, 0);
		ovniO3 = new Ovni(-1, 0);
		estrelladelamuerte = new Nave();
		Mccuinkuchau = new Auto();
		vecO = vector<Oro*>();
		cont = 0;
	}
	~Mando() {}
	int Get_vidas() {
		return estrelladelamuerte->get_vidas();
	}
	void ComenzarJuego() {
		//ovni 1 
		ovniO1->borrar();
		ovniO1->mover();
		ovniO1->imprimir();
		//ovni 2
		ovniO2->borrar();
		ovniO2->mover();
		ovniO2->imprimir();
		//ovni 3
		ovniO3->borrar();
		ovniO3->mover();
		ovniO3->imprimir();

		//Nave
		estrelladelamuerte->Borrar();
		estrelladelamuerte->Mover();
		estrelladelamuerte->Mostrar();


	}
	void Generar_Oro() {
		for (int i = 0; i < 5; i++) {
			Oro* aux = new Oro();
			vecO.push_back(aux);
		}
	}
	void Imprimir_Oro() {
		for (int i = 0; i < vecO.size(); i++) {
			vecO[i]->Imprimir();
		}
	}
	void Mover_Nave(int tecla) {
		switch (tecla) {
		case 1: estrelladelamuerte->Direccion(0, -1); break;
		case 2: estrelladelamuerte->Direccion(-1, 0); break;
		case 3: estrelladelamuerte->Direccion(0, 1); break;
		case 4: estrelladelamuerte->Direccion(1, 0); break;
		}
	}
	void Imprimir_vida_oro() {
		Console::SetCursorPosition(3, 30);
		cout << "Cantidad de vidas: "; for (int i = 0; i < estrelladelamuerte->get_vidas(); i++) { Console::ForegroundColor = ConsoleColor::Red; cout << char(3) << " "; };
		Console::SetCursorPosition(70, 30);
		cout << "Cantidad de oro: " << cont;
	}

	bool Choque_Oro_nave() {
		for (int i = 0; i < vecO.size(); i++) {
			if ((vecO[i]->Devolver_x() == estrelladelamuerte->get_x() && vecO[i]->Devolver_y() == estrelladelamuerte->get_y())
				|| (vecO[i]->Devolver_x() == estrelladelamuerte->get_x1() && vecO[i]->Devolver_y() == estrelladelamuerte->get_y())
				|| (vecO[i]->Devolver_x() == estrelladelamuerte->get_x2() && vecO[i]->Devolver_y() == estrelladelamuerte->get_y())
				|| (vecO[i]->Devolver_x() == estrelladelamuerte->get_x3() && vecO[i]->Devolver_y() == estrelladelamuerte->get_y())
				|| (vecO[i]->Devolver_x() == estrelladelamuerte->get_x4() && vecO[i]->Devolver_y() == estrelladelamuerte->get_y())
				|| (vecO[i]->Devolver_x() == estrelladelamuerte->get_x5() && vecO[i]->Devolver_y() == estrelladelamuerte->get_y())
				|| (vecO[i]->Devolver_x() == estrelladelamuerte->get_x6() && vecO[i]->Devolver_y() == estrelladelamuerte->get_y())
				|| (vecO[i]->Devolver_x() == estrelladelamuerte->get_x7() && vecO[i]->Devolver_y() == estrelladelamuerte->get_y())
				|| (vecO[i]->Devolver_x() == estrelladelamuerte->get_x8() && vecO[i]->Devolver_y() == estrelladelamuerte->get_y())) {
				vecO.erase(vecO.begin() + i);
				cont++;
			}
		}

		return vecO.size() > 0;
	}

	bool Choque_ovni_nave() {
		//x=1;y=1
		if ((estrelladelamuerte->get_x() == ovniO1->devolver_x() && estrelladelamuerte->get_y() == ovniO1->devolver_y())
			|| (estrelladelamuerte->get_x() == ovniO2->devolver_x() && estrelladelamuerte->get_y() == ovniO2->devolver_y())
			|| (estrelladelamuerte->get_x() == ovniO3->devolver_x() && estrelladelamuerte->get_y() == ovniO3->devolver_y()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=2;y=1
		if ((estrelladelamuerte->get_x1() == ovniO1->devolver_x() && estrelladelamuerte->get_y() == ovniO1->devolver_y())
			|| (estrelladelamuerte->get_x1() == ovniO2->devolver_x() && estrelladelamuerte->get_y() == ovniO2->devolver_y())
			|| (estrelladelamuerte->get_x1() == ovniO3->devolver_x() && estrelladelamuerte->get_y() == ovniO3->devolver_y()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=3 y=1
		if ((estrelladelamuerte->get_x2() == ovniO1->devolver_x() && estrelladelamuerte->get_y() == ovniO1->devolver_y())
			|| (estrelladelamuerte->get_x2() == ovniO2->devolver_x() && estrelladelamuerte->get_y() == ovniO2->devolver_y())
			|| (estrelladelamuerte->get_x2() == ovniO3->devolver_x() && estrelladelamuerte->get_y() == ovniO3->devolver_y()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=4  y=1
		if ((estrelladelamuerte->get_x3() == ovniO1->devolver_x() && estrelladelamuerte->get_y() == ovniO1->devolver_y())
			|| (estrelladelamuerte->get_x3() == ovniO2->devolver_x() && estrelladelamuerte->get_y() == ovniO2->devolver_y())
			|| (estrelladelamuerte->get_x3() == ovniO3->devolver_x() && estrelladelamuerte->get_y() == ovniO3->devolver_y()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=5 y=1
		if ((estrelladelamuerte->get_x4() == ovniO1->devolver_x() && estrelladelamuerte->get_y() == ovniO1->devolver_y())
			|| (estrelladelamuerte->get_x4() == ovniO2->devolver_x() && estrelladelamuerte->get_y() == ovniO2->devolver_y())
			|| (estrelladelamuerte->get_x4() == ovniO3->devolver_x() && estrelladelamuerte->get_y() == ovniO3->devolver_y()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=6 y=1
		if ((estrelladelamuerte->get_x5() == ovniO1->devolver_x() && estrelladelamuerte->get_y() == ovniO1->devolver_y())
			|| (estrelladelamuerte->get_x5() == ovniO2->devolver_x() && estrelladelamuerte->get_y() == ovniO2->devolver_y())
			|| (estrelladelamuerte->get_x5() == ovniO3->devolver_x() && estrelladelamuerte->get_y() == ovniO3->devolver_y()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=7  y=1
		if ((estrelladelamuerte->get_x6() == ovniO1->devolver_x() && estrelladelamuerte->get_y() == ovniO1->devolver_y())
			|| (estrelladelamuerte->get_x6() == ovniO2->devolver_x() && estrelladelamuerte->get_y() == ovniO2->devolver_y())
			|| (estrelladelamuerte->get_x6() == ovniO3->devolver_x() && estrelladelamuerte->get_y() == ovniO3->devolver_y()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=8 y=1
		if ((estrelladelamuerte->get_x7() == ovniO1->devolver_x() && estrelladelamuerte->get_y() == ovniO1->devolver_y())
			|| (estrelladelamuerte->get_x7() == ovniO2->devolver_x() && estrelladelamuerte->get_y() == ovniO2->devolver_y())
			|| (estrelladelamuerte->get_x7() == ovniO3->devolver_x() && estrelladelamuerte->get_y() == ovniO3->devolver_y()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=9
		if ((estrelladelamuerte->get_x8() == ovniO1->devolver_x() && estrelladelamuerte->get_y() == ovniO1->devolver_y())
			|| (estrelladelamuerte->get_x8() == ovniO2->devolver_x() && estrelladelamuerte->get_y() == ovniO2->devolver_y())
			|| (estrelladelamuerte->get_x8() == ovniO3->devolver_x() && estrelladelamuerte->get_y() == ovniO3->devolver_y()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}

		//choque de segunda esquina
		//x=1;  y=1
		if ((estrelladelamuerte->get_x() == ovniO1->devolver_x1() && estrelladelamuerte->get_y() == ovniO1->devolver_y())
			|| (estrelladelamuerte->get_x() == ovniO2->devolver_x1() && estrelladelamuerte->get_y() == ovniO2->devolver_y())
			|| (estrelladelamuerte->get_x() == ovniO3->devolver_x1() && estrelladelamuerte->get_y() == ovniO3->devolver_y()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=2;y=1
		if ((estrelladelamuerte->get_x1() == ovniO1->devolver_x1() && estrelladelamuerte->get_y() == ovniO1->devolver_y())
			|| (estrelladelamuerte->get_x1() == ovniO2->devolver_x1() && estrelladelamuerte->get_y() == ovniO2->devolver_y())
			|| (estrelladelamuerte->get_x1() == ovniO3->devolver_x1() && estrelladelamuerte->get_y() == ovniO3->devolver_y()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=3 y=1
		if ((estrelladelamuerte->get_x2() == ovniO1->devolver_x1() && estrelladelamuerte->get_y() == ovniO1->devolver_y())
			|| (estrelladelamuerte->get_x2() == ovniO2->devolver_x1() && estrelladelamuerte->get_y() == ovniO2->devolver_y())
			|| (estrelladelamuerte->get_x2() == ovniO3->devolver_x1() && estrelladelamuerte->get_y() == ovniO3->devolver_y()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=4  y=1
		if ((estrelladelamuerte->get_x3() == ovniO1->devolver_x1() && estrelladelamuerte->get_y() == ovniO1->devolver_y())
			|| (estrelladelamuerte->get_x3() == ovniO2->devolver_x1() && estrelladelamuerte->get_y() == ovniO2->devolver_y())
			|| (estrelladelamuerte->get_x3() == ovniO3->devolver_x1() && estrelladelamuerte->get_y() == ovniO3->devolver_y()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=5 y=1
		if ((estrelladelamuerte->get_x4() == ovniO1->devolver_x1() && estrelladelamuerte->get_y() == ovniO1->devolver_y())
			|| (estrelladelamuerte->get_x4() == ovniO2->devolver_x1() && estrelladelamuerte->get_y() == ovniO2->devolver_y())
			|| (estrelladelamuerte->get_x4() == ovniO3->devolver_x1() && estrelladelamuerte->get_y() == ovniO3->devolver_y()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=6 y=1
		if ((estrelladelamuerte->get_x5() == ovniO1->devolver_x1() && estrelladelamuerte->get_y() == ovniO1->devolver_y())
			|| (estrelladelamuerte->get_x5() == ovniO2->devolver_x1() && estrelladelamuerte->get_y() == ovniO2->devolver_y())
			|| (estrelladelamuerte->get_x5() == ovniO3->devolver_x1() && estrelladelamuerte->get_y() == ovniO3->devolver_y()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=7  y=1
		if ((estrelladelamuerte->get_x6() == ovniO1->devolver_x1() && estrelladelamuerte->get_y() == ovniO1->devolver_y())
			|| (estrelladelamuerte->get_x6() == ovniO2->devolver_x1() && estrelladelamuerte->get_y() == ovniO2->devolver_y())
			|| (estrelladelamuerte->get_x6() == ovniO3->devolver_x1() && estrelladelamuerte->get_y() == ovniO3->devolver_y()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=8 y=1
		if ((estrelladelamuerte->get_x7() == ovniO1->devolver_x1() && estrelladelamuerte->get_y() == ovniO1->devolver_y())
			|| (estrelladelamuerte->get_x7() == ovniO2->devolver_x1() && estrelladelamuerte->get_y() == ovniO2->devolver_y())
			|| (estrelladelamuerte->get_x7() == ovniO3->devolver_x1() && estrelladelamuerte->get_y() == ovniO3->devolver_y()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=9
		if ((estrelladelamuerte->get_x8() == ovniO1->devolver_x1() && estrelladelamuerte->get_y() == ovniO1->devolver_y())
			|| (estrelladelamuerte->get_x8() == ovniO2->devolver_x1() && estrelladelamuerte->get_y() == ovniO2->devolver_y())
			|| (estrelladelamuerte->get_x8() == ovniO3->devolver_x1() && estrelladelamuerte->get_y() == ovniO3->devolver_y()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//Choque con tercer punto
	   //x=1;y=1
		if ((estrelladelamuerte->get_x() == ovniO1->devolver_x() && estrelladelamuerte->get_y() == ovniO1->devolver_y1())
			|| (estrelladelamuerte->get_x() == ovniO2->devolver_x() && estrelladelamuerte->get_y() == ovniO2->devolver_y1())
			|| (estrelladelamuerte->get_x() == ovniO3->devolver_x() && estrelladelamuerte->get_y() == ovniO3->devolver_y1()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=2;y=1
		if ((estrelladelamuerte->get_x1() == ovniO1->devolver_x() && estrelladelamuerte->get_y() == ovniO1->devolver_y1())
			|| (estrelladelamuerte->get_x1() == ovniO2->devolver_x() && estrelladelamuerte->get_y() == ovniO2->devolver_y1())
			|| (estrelladelamuerte->get_x1() == ovniO3->devolver_x() && estrelladelamuerte->get_y() == ovniO3->devolver_y1()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=3 y=1
		if ((estrelladelamuerte->get_x2() == ovniO1->devolver_x() && estrelladelamuerte->get_y() == ovniO1->devolver_y1())
			|| (estrelladelamuerte->get_x2() == ovniO2->devolver_x() && estrelladelamuerte->get_y() == ovniO2->devolver_y1())
			|| (estrelladelamuerte->get_x2() == ovniO3->devolver_x() && estrelladelamuerte->get_y() == ovniO3->devolver_y1()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=4  y=1
		if ((estrelladelamuerte->get_x3() == ovniO1->devolver_x() && estrelladelamuerte->get_y() == ovniO1->devolver_y1())
			|| (estrelladelamuerte->get_x3() == ovniO2->devolver_x() && estrelladelamuerte->get_y() == ovniO2->devolver_y1())
			|| (estrelladelamuerte->get_x3() == ovniO3->devolver_x() && estrelladelamuerte->get_y() == ovniO3->devolver_y1()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=5 y=1
		if ((estrelladelamuerte->get_x4() == ovniO1->devolver_x() && estrelladelamuerte->get_y() == ovniO1->devolver_y1())
			|| (estrelladelamuerte->get_x4() == ovniO2->devolver_x() && estrelladelamuerte->get_y() == ovniO2->devolver_y1())
			|| (estrelladelamuerte->get_x4() == ovniO3->devolver_x() && estrelladelamuerte->get_y() == ovniO3->devolver_y1()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=6 y=1
		if ((estrelladelamuerte->get_x5() == ovniO1->devolver_x() && estrelladelamuerte->get_y() == ovniO1->devolver_y1())
			|| (estrelladelamuerte->get_x5() == ovniO2->devolver_x() && estrelladelamuerte->get_y() == ovniO2->devolver_y1())
			|| (estrelladelamuerte->get_x5() == ovniO3->devolver_x() && estrelladelamuerte->get_y() == ovniO3->devolver_y1()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=7  y=1
		if ((estrelladelamuerte->get_x6() == ovniO1->devolver_x() && estrelladelamuerte->get_y() == ovniO1->devolver_y1())
			|| (estrelladelamuerte->get_x6() == ovniO2->devolver_x() && estrelladelamuerte->get_y() == ovniO2->devolver_y1())
			|| (estrelladelamuerte->get_x6() == ovniO3->devolver_x() && estrelladelamuerte->get_y() == ovniO3->devolver_y1()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=8 y=1
		if ((estrelladelamuerte->get_x7() == ovniO1->devolver_x() && estrelladelamuerte->get_y() == ovniO1->devolver_y1())
			|| (estrelladelamuerte->get_x7() == ovniO2->devolver_x() && estrelladelamuerte->get_y() == ovniO2->devolver_y1())
			|| (estrelladelamuerte->get_x7() == ovniO3->devolver_x() && estrelladelamuerte->get_y() == ovniO3->devolver_y1()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=9
		if ((estrelladelamuerte->get_x8() == ovniO1->devolver_x() && estrelladelamuerte->get_y() == ovniO1->devolver_y1())
			|| (estrelladelamuerte->get_x8() == ovniO2->devolver_x() && estrelladelamuerte->get_y() == ovniO2->devolver_y1())
			|| (estrelladelamuerte->get_x8() == ovniO3->devolver_x() && estrelladelamuerte->get_y() == ovniO3->devolver_y1()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//Choque con 4 punto 
		//x=1;y=1
		if ((estrelladelamuerte->get_x() == ovniO1->devolver_x() && estrelladelamuerte->get_y() == ovniO1->devolver_y())
			|| (estrelladelamuerte->get_x() == ovniO2->devolver_x() && estrelladelamuerte->get_y() == ovniO2->devolver_y())
			|| (estrelladelamuerte->get_x() == ovniO3->devolver_x() && estrelladelamuerte->get_y() == ovniO3->devolver_y()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=2;y=1
		if ((estrelladelamuerte->get_x1() == ovniO1->devolver_x1() && estrelladelamuerte->get_y() == ovniO1->devolver_y1())
			|| (estrelladelamuerte->get_x1() == ovniO2->devolver_x1() && estrelladelamuerte->get_y() == ovniO2->devolver_y1())
			|| (estrelladelamuerte->get_x1() == ovniO3->devolver_x1() && estrelladelamuerte->get_y() == ovniO3->devolver_y1()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=3 y=1
		if ((estrelladelamuerte->get_x2() == ovniO1->devolver_x1() && estrelladelamuerte->get_y() == ovniO1->devolver_y1())
			|| (estrelladelamuerte->get_x2() == ovniO2->devolver_x1() && estrelladelamuerte->get_y() == ovniO2->devolver_y1())
			|| (estrelladelamuerte->get_x2() == ovniO3->devolver_x1() && estrelladelamuerte->get_y() == ovniO3->devolver_y1()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=4  y=1
		if ((estrelladelamuerte->get_x3() == ovniO1->devolver_x1() && estrelladelamuerte->get_y() == ovniO1->devolver_y1())
			|| (estrelladelamuerte->get_x3() == ovniO2->devolver_x1() && estrelladelamuerte->get_y() == ovniO2->devolver_y1())
			|| (estrelladelamuerte->get_x3() == ovniO3->devolver_x1() && estrelladelamuerte->get_y() == ovniO3->devolver_y1()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=5 y=1
		if ((estrelladelamuerte->get_x4() == ovniO1->devolver_x1() && estrelladelamuerte->get_y() == ovniO1->devolver_y1())
			|| (estrelladelamuerte->get_x4() == ovniO2->devolver_x1() && estrelladelamuerte->get_y() == ovniO2->devolver_y1())
			|| (estrelladelamuerte->get_x4() == ovniO3->devolver_x1() && estrelladelamuerte->get_y() == ovniO3->devolver_y1()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=6 y=1
		if ((estrelladelamuerte->get_x5() == ovniO1->devolver_x1() && estrelladelamuerte->get_y() == ovniO1->devolver_y1())
			|| (estrelladelamuerte->get_x5() == ovniO2->devolver_x1() && estrelladelamuerte->get_y() == ovniO2->devolver_y1())
			|| (estrelladelamuerte->get_x5() == ovniO3->devolver_x1() && estrelladelamuerte->get_y() == ovniO3->devolver_y1()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=7  y=1
		if ((estrelladelamuerte->get_x6() == ovniO1->devolver_x1() && estrelladelamuerte->get_y() == ovniO1->devolver_y1())
			|| (estrelladelamuerte->get_x6() == ovniO2->devolver_x1() && estrelladelamuerte->get_y() == ovniO2->devolver_y1())
			|| (estrelladelamuerte->get_x6() == ovniO3->devolver_x1() && estrelladelamuerte->get_y() == ovniO3->devolver_y1()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=8 y=1
		if ((estrelladelamuerte->get_x7() == ovniO1->devolver_x1() && estrelladelamuerte->get_y() == ovniO1->devolver_y1())
			|| (estrelladelamuerte->get_x7() == ovniO2->devolver_x1() && estrelladelamuerte->get_y() == ovniO2->devolver_y1())
			|| (estrelladelamuerte->get_x7() == ovniO3->devolver_x1() && estrelladelamuerte->get_y() == ovniO3->devolver_y1()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=9
		if ((estrelladelamuerte->get_x8() == ovniO1->devolver_x1() && estrelladelamuerte->get_y() == ovniO1->devolver_y1())
			|| (estrelladelamuerte->get_x8() == ovniO2->devolver_x1() && estrelladelamuerte->get_y() == ovniO2->devolver_y1())
			|| (estrelladelamuerte->get_x8() == ovniO3->devolver_x1() && estrelladelamuerte->get_y() == ovniO3->devolver_y1()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		// Choque con 5 punto
			//x=1;y=1
		if ((estrelladelamuerte->get_x() == ovniO1->devolver_x() && estrelladelamuerte->get_y() == ovniO1->devolver_y2())
			|| (estrelladelamuerte->get_x() == ovniO2->devolver_x() && estrelladelamuerte->get_y() == ovniO2->devolver_y2())
			|| (estrelladelamuerte->get_x() == ovniO3->devolver_x() && estrelladelamuerte->get_y() == ovniO3->devolver_y2()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=2;y=1
		if ((estrelladelamuerte->get_x1() == ovniO1->devolver_x() && estrelladelamuerte->get_y() == ovniO1->devolver_y2())
			|| (estrelladelamuerte->get_x1() == ovniO2->devolver_x() && estrelladelamuerte->get_y() == ovniO2->devolver_y2())
			|| (estrelladelamuerte->get_x1() == ovniO3->devolver_x() && estrelladelamuerte->get_y() == ovniO3->devolver_y2()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=3 y=1
		if ((estrelladelamuerte->get_x2() == ovniO1->devolver_x() && estrelladelamuerte->get_y() == ovniO1->devolver_y2())
			|| (estrelladelamuerte->get_x2() == ovniO2->devolver_x() && estrelladelamuerte->get_y() == ovniO2->devolver_y2())
			|| (estrelladelamuerte->get_x2() == ovniO3->devolver_x() && estrelladelamuerte->get_y() == ovniO3->devolver_y2()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=4  y=1
		if ((estrelladelamuerte->get_x3() == ovniO1->devolver_x() && estrelladelamuerte->get_y() == ovniO1->devolver_y2())
			|| (estrelladelamuerte->get_x3() == ovniO2->devolver_x() && estrelladelamuerte->get_y() == ovniO2->devolver_y2())
			|| (estrelladelamuerte->get_x3() == ovniO3->devolver_x() && estrelladelamuerte->get_y() == ovniO3->devolver_y2()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=5 y=1
		if ((estrelladelamuerte->get_x4() == ovniO1->devolver_x() && estrelladelamuerte->get_y() == ovniO1->devolver_y2())
			|| (estrelladelamuerte->get_x4() == ovniO2->devolver_x() && estrelladelamuerte->get_y() == ovniO2->devolver_y2())
			|| (estrelladelamuerte->get_x4() == ovniO3->devolver_x() && estrelladelamuerte->get_y() == ovniO3->devolver_y2()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=6 y=1
		if ((estrelladelamuerte->get_x5() == ovniO1->devolver_x() && estrelladelamuerte->get_y() == ovniO1->devolver_y2())
			|| (estrelladelamuerte->get_x5() == ovniO2->devolver_x() && estrelladelamuerte->get_y() == ovniO2->devolver_y2())
			|| (estrelladelamuerte->get_x5() == ovniO3->devolver_x() && estrelladelamuerte->get_y() == ovniO3->devolver_y2()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=7  y=1
		if ((estrelladelamuerte->get_x6() == ovniO1->devolver_x() && estrelladelamuerte->get_y() == ovniO1->devolver_y2())
			|| (estrelladelamuerte->get_x6() == ovniO2->devolver_x() && estrelladelamuerte->get_y() == ovniO2->devolver_y2())
			|| (estrelladelamuerte->get_x6() == ovniO3->devolver_x() && estrelladelamuerte->get_y() == ovniO3->devolver_y2()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=8 y=1
		if ((estrelladelamuerte->get_x7() == ovniO1->devolver_x() && estrelladelamuerte->get_y() == ovniO1->devolver_y2())
			|| (estrelladelamuerte->get_x7() == ovniO2->devolver_x() && estrelladelamuerte->get_y() == ovniO2->devolver_y2())
			|| (estrelladelamuerte->get_x7() == ovniO3->devolver_x() && estrelladelamuerte->get_y() == ovniO3->devolver_y2()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=9
		if ((estrelladelamuerte->get_x8() == ovniO1->devolver_x() && estrelladelamuerte->get_y() == ovniO1->devolver_y2())
			|| (estrelladelamuerte->get_x8() == ovniO2->devolver_x() && estrelladelamuerte->get_y() == ovniO2->devolver_y2())
			|| (estrelladelamuerte->get_x8() == ovniO3->devolver_x() && estrelladelamuerte->get_y() == ovniO3->devolver_y2()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//Choque con 6 punto
		//x=1;y=1
		if ((estrelladelamuerte->get_x() == ovniO1->devolver_x1() && estrelladelamuerte->get_y() == ovniO1->devolver_y2())
			|| (estrelladelamuerte->get_x() == ovniO2->devolver_x1() && estrelladelamuerte->get_y() == ovniO2->devolver_y2())
			|| (estrelladelamuerte->get_x() == ovniO3->devolver_x1() && estrelladelamuerte->get_y() == ovniO3->devolver_y2()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=2;y=1
		if ((estrelladelamuerte->get_x1() == ovniO1->devolver_x1() && estrelladelamuerte->get_y() == ovniO1->devolver_y2())
			|| (estrelladelamuerte->get_x1() == ovniO2->devolver_x1() && estrelladelamuerte->get_y() == ovniO2->devolver_y2())
			|| (estrelladelamuerte->get_x1() == ovniO3->devolver_x1() && estrelladelamuerte->get_y() == ovniO3->devolver_y2()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=3 y=1
		if ((estrelladelamuerte->get_x2() == ovniO1->devolver_x1() && estrelladelamuerte->get_y() == ovniO1->devolver_y2())
			|| (estrelladelamuerte->get_x2() == ovniO2->devolver_x1() && estrelladelamuerte->get_y() == ovniO2->devolver_y2())
			|| (estrelladelamuerte->get_x2() == ovniO3->devolver_x1() && estrelladelamuerte->get_y() == ovniO3->devolver_y2()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=4  y=1
		if ((estrelladelamuerte->get_x3() == ovniO1->devolver_x1() && estrelladelamuerte->get_y() == ovniO1->devolver_y2())
			|| (estrelladelamuerte->get_x3() == ovniO2->devolver_x1() && estrelladelamuerte->get_y() == ovniO2->devolver_y2())
			|| (estrelladelamuerte->get_x3() == ovniO3->devolver_x1() && estrelladelamuerte->get_y() == ovniO3->devolver_y2()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=5 y=1
		if ((estrelladelamuerte->get_x4() == ovniO1->devolver_x1() && estrelladelamuerte->get_y() == ovniO1->devolver_y2())
			|| (estrelladelamuerte->get_x4() == ovniO2->devolver_x1() && estrelladelamuerte->get_y() == ovniO2->devolver_y2())
			|| (estrelladelamuerte->get_x4() == ovniO3->devolver_x1() && estrelladelamuerte->get_y() == ovniO3->devolver_y2()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=6 y=1
		if ((estrelladelamuerte->get_x5() == ovniO1->devolver_x1() && estrelladelamuerte->get_y() == ovniO1->devolver_y2())
			|| (estrelladelamuerte->get_x5() == ovniO2->devolver_x1() && estrelladelamuerte->get_y() == ovniO2->devolver_y2())
			|| (estrelladelamuerte->get_x5() == ovniO3->devolver_x1() && estrelladelamuerte->get_y() == ovniO3->devolver_y2()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=7  y=1
		if ((estrelladelamuerte->get_x6() == ovniO1->devolver_x1() && estrelladelamuerte->get_y() == ovniO1->devolver_y2())
			|| (estrelladelamuerte->get_x6() == ovniO2->devolver_x1() && estrelladelamuerte->get_y() == ovniO2->devolver_y2())
			|| (estrelladelamuerte->get_x6() == ovniO3->devolver_x1() && estrelladelamuerte->get_y() == ovniO3->devolver_y2()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=8 y=1
		if ((estrelladelamuerte->get_x7() == ovniO1->devolver_x1() && estrelladelamuerte->get_y() == ovniO1->devolver_y2())
			|| (estrelladelamuerte->get_x7() == ovniO2->devolver_x1() && estrelladelamuerte->get_y() == ovniO2->devolver_y2())
			|| (estrelladelamuerte->get_x7() == ovniO3->devolver_x1() && estrelladelamuerte->get_y() == ovniO3->devolver_y2()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}
		//x=9
		if ((estrelladelamuerte->get_x8() == ovniO1->devolver_x1() && estrelladelamuerte->get_y() == ovniO1->devolver_y2())
			|| (estrelladelamuerte->get_x8() == ovniO2->devolver_x1() && estrelladelamuerte->get_y() == ovniO2->devolver_y2())
			|| (estrelladelamuerte->get_x8() == ovniO3->devolver_x1() && estrelladelamuerte->get_y() == ovniO3->devolver_y2()))
		{
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->EliminarVida();
			Console::SetCursorPosition(22, 30); cout << "          ";
		}

		return estrelladelamuerte->get_vidas() > 0;
	}
	void Recolectar_oro() {
		if (cont == 5) {
			estrelladelamuerte->Borrar();
			estrelladelamuerte->pos_inicial();
			estrelladelamuerte->Mostrar();
		}

	}
	int get_contador() {
		return cont;
	}
	void Aparece_Carro() {
		if (cont == 5) {

			Mccuinkuchau->Borrar();
			Mccuinkuchau->Mover();
			Mccuinkuchau->Imprimir();
			if (Mccuinkuchau->get_y() == 0) {
				Mccuinkuchau->Borrar();

			}
		}
	}


};
