class Nodo
{
private:
    int valor;
    Nodo *siguiente = nullptr;

public:
    Nodo(int);
    ~Nodo();
    int getvalor();
    void *setSiguiente(int);
    Nodo *getSiguiente();
    void getSiguiente(Nodo *);
};
