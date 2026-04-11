#include "nodo.hpp"

class Lista
{
private:
    Nodo *inicial;

public:
    Lista();
    ~Lista();
    void insertar(int);
    void imprimir();
};