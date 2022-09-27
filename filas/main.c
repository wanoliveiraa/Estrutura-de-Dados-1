#include <stdio.h>
#include <stdlib.h>

typedef struct _queue{
    int front;
    int rear;
    int nelms;
    int max_itens;
    void **qArray;
}Queue;

Queue * creat(int max){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    if(q==NULL){
        return NULL;
    }
    q->qArray = (void**)malloc(max*sizeof(void*));
    if(q->qArray ==NULL){
        return NULL;
    }
    q->front = 0;
    q->rear = 0;
    q->max_itens = max;
}
int qIncreCirc(int i, int max){
    if(i==max){
        return 0;
    }else{
        i++;
        return i;
    }

}

int qEnqueue(Queue *q,void* elm){
    if(q!=NULL){
        if(q->nelms < q->max_itens){
           q->rear = qIncreCirc(q->rear,q->max_itens);
            q->qArray[q->rear] = elm;
            return 1;
        }
    }
    return 0;
}

void *dQueue(Queue *q){
    void *aux
    if(q==NULL){
        return NULL;
    }
    if(q->nelms < q->max_itens){
        aux = q->qArray[q->front];
        q->front++;
        return aux;
    }
    return NULL
}


int main()
{
    printf("Hello world!\n");
    return 0;
}
