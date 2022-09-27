#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colecao.h"


typedef struct jogador2020{
    char nomeJog[30];
    int numGols;
    float altJog;
    int chave;
}Jogador;



void allCollec(void* all){
    Jogador* aux = (Jogador*) all;

    printf("Nome do jogador: %s\n", aux->nomeJog);
    printf("Numero de gols : %i\n", aux->numGols);
    printf("Altura do Jogador: %.1f\n", aux->altJog);
    printf("\n");
}

int cmp(void* elm, void* key){
    Jogador* pa = (Jogador*) elm;
    int *pb = ( int*) key;
    if ( pa->chave == (*pb)) {
        return 1;
    }else {
        return 0;
    }
}


int main(void) {
    Collection* jogador2020  = Create(3);

    Jogador* j10 = (Jogador*) malloc(sizeof(Jogador));
    strcpy(j10->nomeJog, "Messi");
    j10->numGols=763;
    j10->altJog = 1.70;
    j10->chave = 0;

    Jogador* j7 = (Jogador*) malloc(sizeof(Jogador));
    strcpy(j7->nomeJog, "C.Ronaldo");
    j7->numGols=758;
    j7->altJog = 1.87;
    j7->chave = 1;

    Jogador* j3 = (Jogador*) malloc(sizeof(Jogador));
    strcpy(j3->nomeJog, "RonyRustico");
    j3->numGols=100000;
    j3->altJog = 1.75;
    j3->chave = 2;

    InsertElm(jogador2020, j10);
    InsertElm(jogador2020, j7);
    InsertElm(jogador2020, j3);
    //List(jogador2020,allCollec);

    int chavenew = 1;

    RemoveElm(jogador2020, &chavenew, cmp);


    //List(jogador2020,allCollec);

    int buscar = 2;
    //o query ja esta funcionando
    //so que para visualiza o elemento e necessario pegar o retorno e printar
    //com a funcao que vcs mesmo criaram

    allCollec(QueryELm(jogador2020,&buscar,cmp));

    if (Destroy(jogador2020))
        printf("destruido\n");

    List(jogador2020,allCollec);

}
