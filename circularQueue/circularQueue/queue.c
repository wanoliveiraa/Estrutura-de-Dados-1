#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct _queue_ 
{
    int maxEl;
    int currentLen;
    int head;
    int back;
    void** items;
}Queue;

int circularIndex(int i, int maxEl)
{
    if(i >= 0)
        return i % maxEl;
    else
        return maxEl - i;
}

Queue* createQueue(int maxEl)
{
    Queue* q = (Queue*) malloc(sizeof(Queue));
    if (q == NULL)
        return NULL;

    q->maxEl = maxEl;
    q->currentLen = 0;
    q->head = 0;
    q->back = -1;

    q->items = (void**) malloc(maxEl*sizeof(void*));
    
    if(q->items == NULL){
        free(q);
        return NULL;
    }

    return q;
}

void* pop(Queue* q){
    if(q == NULL || q->currentLen <= 0)
        return NULL;

    void* aux = q->items[q->head];
    q->head = circularIndex(q->head + 1, q->maxEl);
    q->currentLen--;

    return aux;
}

int push(Queue* q, void* el){
    if(q == NULL || el == NULL)
        return 0;
    else if(q->currentLen >= q->maxEl){
        return 0;
    }

    q->back = circularIndex(q->back + 1, q->maxEl);
    q->items[q->back] = el;
    q->currentLen++;

    return 1;
}

void destructQueue(Queue* q){
    for(int i = 0; i < q->currentLen; i++){
        int index = circularIndex(q->head + i, q->maxEl);
        free(q->items[index]);
    }

    free(q);
}

void printQueue(Queue* q,void (*print)(void*)){
    for(int i = 0; i < q->currentLen; i++){
        int index = circularIndex(q->head + i, q->maxEl);
        print(q->items[index]);
    }
}
int qPromoveUltimo( Queue *q, int n){
    if(q == NULL)
        return 0;
    else if(q->currentLen <= n )
        return 0;

    void* aux = q->items[q->back];

    for(int i = 0; i < n; i++){
        int index1 = circularIndex(q->back - i, q->maxEl);
        int index2 = circularIndex(q->back - i -1, q->maxEl);
        q->items[index1] = q->items[index2];
    }

    int index3 = circularIndex(q->back - n, q->maxEl);
    q->items[index3] = aux;
    
}

int qPunePrimeiro ( Queue *q, int n){
    if(q == NULL)
        return 0;
    else if(q->currentLen <= n)
        return 0;

    void* aux = q->items[q->head];

    for(int i = 0; i < n; i++){
        int index1 = circularIndex(q->head + i, q->maxEl);
        int index2 = circularIndex(q->head + i + 1, q->maxEl);
        q->items[index1] = q->items[index2];
    }

    int index3 = circularIndex(q->head + n, q->maxEl);
    q->items[index3] = aux;
}