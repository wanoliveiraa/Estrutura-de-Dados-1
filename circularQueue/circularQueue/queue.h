#ifndef QUEUE_H
#define QUEUE_H

typedef struct _queue_ Queue;

Queue* createQueue(int maxEl);
int circularIndex(int i, int maxEl);
void* pop(Queue* q);
int push(Queue* q, void* el);
void destructQueue(Queue* q);
int qPromoveUltimo( Queue *q, int n);
int qPunePrimeiro ( Queue *q, int n);
void printQueue(Queue* q,void (*print)(void*));

#endif