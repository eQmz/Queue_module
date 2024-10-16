#include "queue_module.h"

void create_queue(Cola_t *cola)
{
    cola->init_queue = inicializarCola; 
    cola->is_empty = estaVacia;
    cola->is_full = estaLlena;
    cola->put = enqueue;
    cola->pop = dequeue;
    cola->peek = frente;

    cola->init_queue(cola);
}

static void inicializarCola(Cola_t *cola)
{
    cola->front = cola->rear = -1;
    for(int i = 0; i < MAX_ELEM_QUEUE; cola->elem[i++] = 0);   
}

static int estaVacia(Cola_t *cola)
{
    return (cola->front == -1) ? 1 : 0;
}

static int estaLlena(Cola_t *cola)
{
    return (cola->front == ((cola->rear + 1) % MAX_ELEM_QUEUE)) ? 1 : 0;
}

static int enqueue(Cola_t *cola, int valor)
{
    if(cola->is_full(cola))
    {
        printf("The queue is full\n");
        return -1;
    }

    if(cola->is_empty(cola))
         cola->front = 0;
    
    cola->rear = (cola->rear + 1) % MAX_ELEM_QUEUE;

    cola->elem[cola->rear] = valor;

    printf("Insertado: %d\n", valor);
    return 0;
}

static int dequeue(Cola_t *cola)
{
    if(estaVacia(cola))
    {
        printf("The queue is empty\n");
        return -1;
    }

    int aux = cola->elem[cola->front];
    
    if(cola->front == cola->rear)
        cola->init_queue(cola);

    else
        cola->front = (cola->front + 1) % MAX_ELEM_QUEUE;

    return aux;
}

static int frente(Cola_t *cola)
{
    if(cola->is_empty(cola))
    {
        printf("The queue is empty\n");
        return -1;
    }

    return cola->elem[cola->front];
}

