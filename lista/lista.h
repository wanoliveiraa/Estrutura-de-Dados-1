#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct _lista_ lista;
lista *addCreat();
int inserir(lista *l,void *item);
void* removeElm(lista* l, void* key, int(*cmp)(void*,void*));
void* igetFirst(lista*l);
void* igetNext(lista*l);
int *destroy(lista *l);
void* QueryELm(lista *l, void* key,int (*cmp)(void*, void*));
void imprimir(lista* l, void (*allLista)(void*));

#endif // LISTA_H_INCLUDED
