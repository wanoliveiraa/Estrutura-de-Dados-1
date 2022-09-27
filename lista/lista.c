#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

typedef struct _no_{
    void *item;
    struct _no_ *proximo;
}SLLNo;

typedef struct _lista_{
    SLLNo *first;
    SLLNo *current;
}lista;

lista *addCreat(){
    lista *l = (lista*)malloc(sizeof(lista));
    if(l!=NULL){
        l->first = NULL;
        return l;
    }
    return NULL;
}

int inserir(lista *l,void *item){
    SLLNo *novoNo;
    if(l!=NULL){
        novoNo = (SLLNo*)malloc(sizeof(SLLNo));
        if(novoNo!=NULL){
            novoNo->item = item;
            novoNo->proximo = l->first;
            l->first = novoNo;
            return 1;
        }
    }
    return 0;
}
void* removeElm(lista* l, void* key, int(*cmp)(void*,void*)){
  if(l == NULL){
    return NULL;
  }
  SLLNo* aux = l->first;
  SLLNo* prev = NULL;
  while(aux != NULL){
    if(cmp(aux->item,key)){
      if(prev == NULL){
        l->first = aux->proximo;
      }else{
        prev->proximo = aux->proximo;
      }
      free(aux);
      return aux;
    }
    prev = aux;
    aux = aux->proximo;
  }
    return NULL;
}

void* igetFirst(lista*l){
    if(l!=NULL){
        if(l->first!=NULL){
            l->current = l->first;
            return l->current->item;
        }
    }
return NULL;
}

void* igetNext(lista*l){
    if(l!=NULL){
        if(l->first!=NULL){
           if(l->current->proximo!=NULL){
            l->current = l->first;
            return l->current->item;
           }
        }
    }
return NULL;
}
int *destroy(lista *l){
    if(l!=NULL){
        if(l->first==NULL){
            free(l);
            return 1;
        }
    }
    return 0;
}

void* QueryELm(lista *l, void* key,int (*cmp)(void*, void*)){

    if(l != NULL){
        if(l->first!=NULL){
          SLLNo *aux = l->first;

          while(aux->proximo!=NULL && cmp(aux->item,key) != 1){
            aux = aux->proximo;
          }
          if(cmp(aux->item,key) == 1){
            return aux->item;
          }
        }
    }
    return NULL;
}

void imprimir(lista* l, void (*allLista)(void*)){

    if(l == NULL){
        return NULL ;
    }

    SLLNo *aux = l->first;
    while(aux!=NULL){
        allLista(aux->item);
        aux = aux->proximo;
    }
    return NULL;
}



