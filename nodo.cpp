#include "nodo.hpp"
#include <iostream>

Nodo::Nodo(int _valor) : valor{_valor} {}; //asignarle algo al atributo valor de los objetos tipo nodo que se creen

Nodo::~Nodo()
{
    std::cout << "Llamando destructor en nodo " << this->valor << std::endl;
    if (this->siguiente != nullptr)
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

void Nodo::setAnterior(Nodo *ant) //*asigna al nodo anterior del actual el nodo que se la pasa
{
    this->anterior = ant;
}

Nodo *Nodo::getAnterior() //*busca cual es el nodo anterior del actual y lo devuelve
{
    return this->anterior;
}

void Nodo::setSiguiente(Nodo *sig)
{
    this->siguiente = sig;
}

Nodo *Nodo::getSiguiente()
{
    return this->siguiente;
}

void Nodo::imprimir()
{
    std::cout << "Nodo [" << this->getValor() << "]" << std::endl;
}