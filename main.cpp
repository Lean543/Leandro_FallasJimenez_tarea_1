#include "lista.hpp"
#include <iostream>

//Leandro Fallas Jiménez, C12774

int main()
{
    Lista *lista = new Lista();

    lista->insertar(1);
    lista->insertar(3);
    lista->insertar(4);
    lista->insertar(8);
    lista->insertar(9);
    lista->insertar(11);
    lista->insertar(15);

    lista->contar();
    lista->imprimir();
    lista->imprimir_reverso();

    lista->eliminar();

    lista->imprimir_reverso();

    Lista *listafiltrada = lista->filtrar();
    listafiltrada->contar();
    listafiltrada->imprimir(); //imprimir lista filtrada
    listafiltrada->imprimir_reverso();

    delete lista; //llamar destructores de cada lista
    delete listafiltrada;
}