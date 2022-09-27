
#include <stdio.h>
#include <stdlib.h>

#include "colecao.h"

typedef struct _colecao_{
    int numElm;
    int maxElm;
    void **elm;
}Collection;


Collection *Create(int maxElm){

    Collection *collec;

    if(maxElm>0){
        collec=(Collection*)malloc(sizeof(Collection));
    if (collec!=NULL){
        collec->elm=(void**)malloc(maxElm*sizeof(void*));
        if(collec->elm!=NULL){
            collec->maxElm=maxElm;
            collec->numElm=0;
            }
        }
    }
    return collec;
}

 int InsertElm(Collection *collec,void *item){
    if(collec == NULL || item == NULL){
        return 0;
    }
    if(collec->numElm >= collec->maxElm){
        return 0;
    }

    (collec->elm)[collec->numElm] = item;
    collec->numElm++;

    return 1;

}

int RemoveElm(Collection *collec, void* key,int (*cmp)(void*, void*)){
    if(collec == NULL)
        return 0;


    for(int i = 0; i < collec->numElm; i++)
    {
        if (cmp(collec->elm[i], key))
        {
            free(collec->elm[i]);

            for(int j = i; j < collec->numElm - 1; j++)
            {
                collec->elm[j] = collec->elm[j+1];
            }

            collec->numElm--;

            return 1;
        }
    }

    return 0;
}
void* QueryELm(Collection *collec, void* key,int (*cmp)(void*, void*)){
    if(collec == NULL){
        return NULL;
    }

    for(int i = 0; i < collec->numElm; i++){
        if (cmp(collec->elm[i],key)){
            return collec->elm[i];
        }   
    }
    return NULL;
}
void List(Collection* collec, void (*allCollec)(void*)){
    if(collec == NULL)
        return;

    for(int i = 0; i < collec->numElm; i++)
    {
        allCollec(collec->elm[i]);
    }
}

int Destroy(Collection* collec){
    if(collec!=NULL){
        if(collec->elm!=NULL){
            //aqui q ta o erro essa comparacao precisa ser != e nao ==

            // if(collec->numElm != 0){
            //     free(collec->elm);
            //     free(collec);
            //     return 1;

            // }

            for(int i = 0; i < collec->numElm; i++){
                free(collec->elm[i]);
            }

            free(collec->elm);
            free(collec);
            return 1;
        }
    }
    return 0;
}

