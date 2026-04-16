#include "lista.hpp"
#include <iostream>

Lista::Lista() : inicial{nullptr} {}; //crear un nodo inicial al hacer un objeto tipo lista y asignarle al atributo valor de este un puntero null

Lista::~Lista() //destructor de los objetos tipo Lista
{   
    std::cout << "Destruyendo nodos de la lista: {" << std::endl;
    if (this->inicial != nullptr)
    {
        delete inicial;
    }
    std::cout << "}" << std::endl;
}

void Lista::insertar(int valor)
{
    Nodo *nuevo = new Nodo(valor); //estos objetos tipo nodo se pierden luego de terminar la función porque no se retornan entonces todo bien

    Nodo *actual = this->inicial; //asignele a un objeto tipo nodo temporal llamado actual el nodo inicial de la lista

    if (actual == nullptr) //si el puntero del nodo no apunta a nada, osea: si la lista está vacia, haga lo siguiente:
    {
        this->inicial = nuevo; //signe como nodo inicial el nuevo nodo recien creado y por tanto el nuevo nodo también pasaría a ser el actual
    }
    else
    {
        while (actual->getSiguiente() != nullptr) //el ultimo nodo tiene como siguiente a un nodo vacío
        {
            actual = actual->getSiguiente(); //avanzar el nodo actual hasta el último de la lista
        }
        nuevo->setAnterior(actual); //*asignarle al nodo nuevo como nodo anterior al nodo actual
        actual->setSiguiente(nuevo); //asignarle al nodo actual como nodo siguiente al nodo nuevo
    }
}

void Lista::contar()
{
    int counter = 0;
    Nodo *actual = this->inicial;
    while (actual != nullptr)
    {
        actual = actual->getSiguiente();
        counter += 1;
    }

    std::cout << "El número de elementos de la lista es: " << counter << std::endl;
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

void Lista::imprimir_reverso()
{   
    Nodo *actual = this->inicial; //creacion de un objeto nodo temporal llamado actual para usarlo como
    //puntero de la lista al asignarlo como nodo incial de esta
    while (actual->getSiguiente() != nullptr)
    {
        actual = actual->getSiguiente(); //*avanzar el nodo actual hasta el último nodo de la lista
    }
    std::cout << "Lista: {" << std::endl;
    while (actual != nullptr) //*el primer nodo tiene como anterior a un nodo vacío entonces en ese
    //momento ya no entra al while y no lo imprime
    {
        actual->imprimir();
        actual = actual->getAnterior(); //*retroceder el nodo actual (nodo puntero) hasta el primero de la lista
    }
    std::cout << "}" << std::endl;
}

void Lista::eliminar()
{
    int referencia;
    std::cout << "Ingrese el valor del nodo a aliminar: ";
    std::cin >> referencia;
    std::cout << "Ingresaste: " << referencia << std::endl;
    Nodo *actual = this->inicial;

    while (actual != nullptr)
    {
        if (actual->getValor() == referencia) //*si se encuentra un nodo con ese numero hagale lo siguiente:
        {
            Nodo *anterior = actual->getAnterior(); //*asignar a un objeto puntero tipo nodo temporal llamado anterior
            // al puntero del nodo anterior al actual en el recorrido
            Nodo *siguiente = actual->getSiguiente(); //*asignar a un objeto puntero tipo nodo temporal llamado siguiente
            // al puntero del nodo siguiente al actual en el recorrido 

            if (anterior != nullptr) //*if para que si se va a eliminar el nodo inicial de la lista no acceda a una parte
            //de la memoria vacia al acceder al nodo anterior al primero
            {
                anterior->setSiguiente(siguiente); //*asigne al nodo anterior como nodo siguiente al
                //nodo siguiente al actual 
            }
            else
                this->inicial = siguiente; //*asigne el nodo siguiente al inicial como nuevo inicial

            if (siguiente != nullptr) //*if para que si se va a eliminar el nodo final de la lista no acceda a una parte
            //de la memoria vacia al acceder al nodo siguiente al ultimo
            {
                siguiente->setAnterior(anterior);//*asigne al nodo siguiente como nodo siguiente al
                //nodo anterior al actual 
            }           
            actual->setSiguiente(nullptr); //*evita que el destructor borre los nodos siguientes al actual
            delete actual;
            return; //*si ya borró el nodo salga de la función y no siga :)
        }
        else //*si el nodo no tiene ese número:
        {
            actual = actual->getSiguiente(); //*avance en la lista
        }
    }

    std::cout << "No se encontró el nodo a eliminar" << std::endl; //*si no se encuentra el
    //nodo en la lista, devolver un mensaje
}

Lista* Lista::filtrar()
{
    int referencia;
    std::cout << "Ingrese el valor mínimo del nodo desde el que se debe copiar: ";
    std::cin >> referencia;
    std::cout << "Ingresaste: " << referencia << std::endl;
    Nodo *actual = this->inicial;
    Lista *lista2 = new Lista(); //*creación de nuevo objeto puntero lista (puntero a nueva lista filtrada)

    while (actual != nullptr)
    {
        if (actual->getValor() > referencia) //*si se encuentra un nodo con valor mayor a es numero haga lo siguiente:
        {
            lista2->insertar(actual->getValor()); //*inserte un nodo con ese valor a la nueva lista
        }
        actual = actual->getSiguiente(); //*avance en la lista normal
    }

    if(lista2->inicial == nullptr)
    {
        std::cout << "No se encontró un numero mayor en la lista, se devuelve una lista vacía" << std::endl; //*si no 
        //se encuentra un nodo mayor en la lista, devolver un mensaje
    }

    return lista2; //devolver la nueva lista filtrada
}

