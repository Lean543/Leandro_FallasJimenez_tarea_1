#include "lista.hpp"
#include <iostream>

Lista::Lista() : inicial{nullptr} {};

Lista::~Lista()
{
    if (this->inicial != nullptr)
    {
        delete inicial;
    }
}

void Lista::insertar(int valor)
{
    Nodo *nuevo = new Nodo(valor);

    Nodo *actual = this->inicial;
    if (actual == nullptr)
    {
        this->inicial = nuevo;
    }
    else
    {
        while (actual->getSiguiente() != nullptr)
        {
            actual = actual->getSiguiente();
        }
        actual->setSiguiente(nuevo);
    }
}

void Lista::imprimir()
{
    std::cout << "Lista: {" << std::endl;
    Nodo *actual = this->inicial;
    while (actual != nullptr)
    {
        actual->imprimir();
        actual = actual->getSiguiente();
    }
    std::cout << "}" << std::endl;
}