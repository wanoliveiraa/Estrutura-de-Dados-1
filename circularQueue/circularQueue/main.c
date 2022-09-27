#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "queue.h"

typedef struct _carro_ {
    int placa;
    char cor[20];
}Carro;

void printCar(void* car){
    Carro* aux = (Carro*) car;

    printf("Placa: %d\n", aux->placa);
    printf("Cor: %s\n", aux->cor);
}

int main (){
    Queue* fila = createQueue(4);

    Carro* c1 = (Carro*) malloc(sizeof(Carro));
    c1->placa = 111111;
    strcpy(c1->cor, "red");

    Carro* c2 = (Carro*) malloc(sizeof(Carro));
    c2->placa = 222222;
    strcpy(c2->cor, "blue");

    Carro* c3 = (Carro*) malloc(sizeof(Carro));
    c3->placa = 333333;
    strcpy(c3->cor, "orange");

    Carro* c4 = (Carro*) malloc(sizeof(Carro));
    c4->placa = 444444;
    strcpy(c4->cor, "purple");

    push(fila, c1);
    push(fila, c2);
    push(fila, c3);
    push(fila, c4);
    
    //qPromoveUltimo(fila, 1);
    qPunePrimeiro(fila, 2);
    
    printQueue(fila,printCar);

    destructQueue(fila);
   
    return 0;
}