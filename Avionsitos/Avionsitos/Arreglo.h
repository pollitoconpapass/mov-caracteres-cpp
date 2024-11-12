// ARREGLO
#pragma once
#include "Avion1.h"
#include "Avion2.h"
#include "Avion3.h"
#include "Avion4.h"
#include "Avion5.h"
#include "Avion6.h"
#include "Avion7.h"
#include "Avion8.h"
#include "Avion9.h"

class ArregloEntidad {
private:
	int cant;
	Entidad** arr;

public:
	ArregloEntidad() {
		cant = 0;
	}
	~ArregloEntidad() {
		for (int i = 0; i < cant; i++) {
			delete arr[i];
		}
		delete[]arr;
	}

	void Agregar(Entidad* nuevo) {
		Entidad** aux = new Entidad * [cant + 1];
		for (int i = 0; i < cant; i++) {
			aux[i] = arr[i];
		}
		aux[cant] = nuevo;
		cant++;
		arr = aux;
	}

	void Eliminar(Entidad* eliminado) {
		Entidad** aux = new Entidad * [cant - 1];
		int i;
		for (i = 0; arr[i] != eliminado; i++) {
			aux[i] = arr[i];
		}
		for (int j = i; j < cant - 1; j++) {
			aux[j] = arr[j + 1];
		}
		delete eliminado;
		cant--;
		arr = aux;
	}

	void Eliminar(int pos) {
		if (pos < cant) {
			arr[pos]->Borrar();
			Eliminar(arr[pos]);
		}
	}

	void Borrar() {
		for (int i = 0; i < cant; i++) {
			arr[i]->Borrar();
		}
	}

	void Mover() {
		for (int i = 0; i < cant; i++) {
			arr[i]->Mover();
		}
	}

	void Mostrar() {
		for (int i = 0; i < cant; i++) {
			arr[i]->Mostrar();
		}
	}
};
