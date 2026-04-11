#include "nodo.hpp"
#include <iostream>

Nodo::Nodo(int _valor) : valor{_valor} {};

Nodo::~Nodo()
{
    std::cout << "Llamando destructor en nodo " << this->valor << std::end1;
    if (this->siguiente) != nullptr;
    {
        delete siguiente;
    }

}

int Nodo::getValor()
{
    return this->valor;
}

void Nodo::setValor(int valor)
{
    this->valor = valor;
}

void Nodo::setSiguiente(Nodo *sig)
{
    this->siguiente =sig;
}

Nodo *Nodo::getSiguiente()
{
    return this->siguiente;
}