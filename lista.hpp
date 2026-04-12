#include "nodo.hpp"

class Lista
{
private:
    Nodo *inicial;

public:
    Lista();
    ~Lista();
    void insertar(int);
    void contar();
    void imprimir();
    void imprimir_reverso();
    void eliminar();
    Lista *filtrar();
};