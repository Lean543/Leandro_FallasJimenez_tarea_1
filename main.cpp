#include "lista.hpp"
#include <iostream>

int main()
{
    Lista *lista = new Lista();

    lista->insertar(1);
    lista->insertar(3);
    lista->insertar(5);
    lista->insertar(7);
    lista->insertar(9);

    lista->contar();
    lista->imprimir();
    lista->imprimir_reverso();

    lista->eliminar();

    lista->imprimir();

    Lista *listafiltrada = lista->filtrar();
    listafiltrada->imprimir(); //imprimir lista filtrada

    delete lista; //llamar destructores de cada lista
    delete listafiltrada;
}