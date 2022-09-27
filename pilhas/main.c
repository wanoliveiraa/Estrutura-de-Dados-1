#include <stdio.h>
#include <stdlib.h>
#include"stack.h"



int main(){

    int opc,valor;
        printf("Tamanho da Pilha: \n");
        scanf("%i",&valor);
        getchar();
        Stack* teste  = stkCreat(valor);

        if(teste){
            printf("Criou");
        }
}
