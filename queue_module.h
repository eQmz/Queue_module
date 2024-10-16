#ifndef QUEUE_MODULE_H
#define QUEUE_MODULE_H

/**
 * @file queue_module.h
 * @author E_MtSnZ 
 * @brief This library contains a basic queque structure which has its own methods and constructor
 * @version 1.0
 * @date 2024-10-15
 * @code
    #include "queue_module.h"

    int main(int argc, char const *argv[])
    {
        Cola_t cola;
        create_queue(&cola);

        for(int i = 1; i < 7; i++)
            cola.put(&cola, 10*i);
        
        printf("Queuqe peek: %d\n", cola.peek(&cola));

        for(int i = 0; i < MAX; i++)
            printf("Dequeue: %d\n", cola.pop(&cola));

        printf("Queue peek: %d\n", cola.peek(&cola));
        return 0;
    }
    
    Output
    Inserted: 10
    Inserted: 20
    Inserted: 30
    Inserted: 40
    Inserted: 50
    The queue is full
    Queue peek: 10
    Dequeue: 10
    Dequeue: 20
    Dequeue: 30
    Dequeue: 40
    Dequeue: 50
    The queue is empty
    Queue peek: -1
 * @endcode
 * @copyright Copyright (c) 2024
 * 
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdint.h"

/**
 * @brief This MACRO is the max number of elements in the queue
 * 
 */
#define MAX_ELEM_QUEUE 5 // Tamaño máximo de la cola

/**
 * @brief This is the queue typedef
 * 
 */
typedef struct Cola Cola_t;

/**
 * @brief This is the definition for a function pointer with Cola_t parameter and return of void type
 * 
 */
typedef void(* tf0_t)(Cola_t *cola);

/**
 * @brief This is the definition for a function pointer with Cola_t parameter and return of int type
 * 
 */
typedef int(* tf1_t)(Cola_t *cola);

/**
 * @brief This is the definition for a function pointer with Cola_t and int parameters and return of int type
 * 
 */
typedef int(* tf2_t)(Cola_t *cola, int valor);

/**
 * @brief This is the queue structure definition
 * 
 */
struct Cola {

    /**
     * @brief elements array of the queue
     * 
     */
    int elem[MAX_ELEM_QUEUE];

    /**
     * @brief front of the queue
     * 
     */
    int8_t front;

    /**
     * @brief rear or end of the queue
     * 
     */
    int8_t rear;

    /**
     * @brief Initializes the attributes of the queue instance
     * 
     * @param cola This is the queue instance
    */
    tf0_t init_queue; 

    /**
     * @brief Checks if the queue is empty
     * 
     * @param cola The queue instance
     * @return int if the queue is empty returns 1 otherwise returns 0
     */
    tf1_t is_empty;

    /**
     * @brief Checks if the queue is full
     * 
     * @param cola The queue instance
     * @return int if the queue is full returns 1 otherwise returns 0
     */
    tf1_t is_full;

    /**
     * @brief Puts a new item or element in the queue
     * 
     * @param cola queue instance
     * @param valor item value
     * @return int if the queue is full returns 1 otherwise returns 0
     */
    tf2_t put;

    /**
     * @brief pulls an item from the queue
     * 
     * @param cola queue instance
     * @return int if the queue is empty returns -1 otherwise returns the item value
     */
    tf1_t pop;
    
    /**
     * @brief Shows the last item of the queue and it does not pull the last item from the queue
     * 
     * @param cola queue instance
     * @return int if the queue is empty returns -1 otherwise returns the item value
     */
    tf1_t peek;
};

/**
 * @brief Initializes the attributes of the queue instance
 * 
 * @param cola This is the queue instance
 */
static void inicializarCola(Cola_t *cola);

/**
 * @brief Checks if the queue is empty
 * 
 * @param cola The queue instance
 * @return int if the queue is empty returns 1 otherwise returns 0
 */
static int estaVacia(Cola_t *cola);

/**
 * @brief Checks if the queue is full
 * 
 * @param cola The queue instance
 * @return int if the queue is full returns 1 otherwise returns 0
 */
static int estaLlena(Cola_t *cola);

/**
 * @brief Puts a new item or element in the queue
 * 
 * @param cola queue instance
 * @param valor item value
 * @return int if the queue is full returns 1 otherwise returns 0
 */
static int enqueue(Cola_t *cola, int valor);

/**
 * @brief pulls an item from the queue
 * 
 * @param cola queue instance
 * @return int if the queue is empty returns -1 otherwise returns the item value
 */
static int dequeue(Cola_t *cola);

/**
 * @brief Shows the last item of the queue and it does not pull the last item from the queue
 * 
 * @param cola queue instance
 * @return int if the queue is empty returns -1 otherwise returns the item value
 */
static int frente(Cola_t *cola);

/**
 * @brief This is the constructor that initializes the methods pointers and the queue attributes
 * 
 * @param cola queue instance
 */
void create_queue(Cola_t *cola);

#endif // QUEUE_MODULE_H