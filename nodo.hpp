class Nodo
{
private:
    int valor;
    Nodo *siguiente = nullptr;
    Nodo *anterior = nullptr;

public:
    Nodo(int);

    ~Nodo();

    int getValor();

    void setValor(int);

    Nodo *getAnterior();

    void setAnterior(Nodo *);

    Nodo *getSiguiente();

    void setSiguiente(Nodo *);

    void imprimir();
};
