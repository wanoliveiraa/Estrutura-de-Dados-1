#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include<locale.h>
//Trabalho de Implementação do TAD
//Dupla: Luís Felipe Rocha Pereira e Walderney Oliveira Azevedo.

typedef struct jogador2020{
    char nomeJog[100];
    int numGols;
    double altJog;
    int chave;
}Jogador;

void allLista(void* all){// all será passado na funcão List recebendo collec->elm[i]
    Jogador* aux = (Jogador*) all;// aux vai receber all que se passa pela colecao Jogador
    printf("----------------------------------\n");//acessando os atributos da struct Jogador collec->elm[i]
    printf("Nome do jogador: %s\n", aux->nomeJog);
    printf("Numero de gols : %i\n", aux->numGols);
    printf("Altura do Jogador: %.2lf cm \n", aux->altJog);
    printf("Camisa :%d\n", aux->chave);
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
    setlocale(LC_ALL,"Portuguese");
    int remover;//chave
    int buscar;//chave
    int opcao;
    int valor = 0;//Quantidade de elementos
    int auxVal;

    lista *jogadores;
    jogadores = NULL;
    jogadores = addCreat();

    do{
        printf(" 1-Inserir elemento na Lista \n 2-Printar Elementos \n");
        printf(" 3-Buscar Elemento\n 4-Remover um Elemento da Lista\n 5-Destruir\n 0-Sair\n");
        scanf("%i",&opcao);
        getchar();

        switch (opcao){
            case 1:

                printf("Informe quantos elementos voce quer por na Lista:\n");
                scanf("%d",&auxVal);
                getchar();

                for(int i = 0;i<auxVal;i++){

                    Jogador* ji = (Jogador*) malloc(sizeof(Jogador));

                    printf("Nome do Jogador :\n");
                    scanf("%99[^\n]",ji->nomeJog);
                    getchar();

                    printf("Quantidade de gols:\n");
                    scanf("%i",&ji->numGols);
                    getchar();

                    printf("Altura do Jogador:\n");
                    scanf("%lf",&ji->altJog);
                    getchar();

                    printf("Camisa do Jogador:\n");
                    scanf("%i",&ji->chave);
                    getchar();

                    inserir(jogadores,ji);

                }
            break;
            case 2:
                imprimir(jogadores,allLista);
            break;

            case 3:
                printf("Informe a camisa do Jogador:\n");
                scanf("%i",&buscar);
                getchar();
                allLista(QueryELm(jogadores,&buscar,cmp));
            break;

            case 4:
                printf("Informe a camisa do Jogador:\n");
                scanf("%i",&remover);
                getchar();
                removeElm(jogadores,&remover,cmp);
                printf("\n Removido");
            break;
            case 5:
                destroy(jogadores);
                printf("Destruido\n");
            break;
            case 0:
            break;

            default:
                printf("Opção Inválida!\n");
        }


    }while(opcao!=0);
}
