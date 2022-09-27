
#ifndef COLECAO_H_INCLUDED
#define COLECAO_H_INCLUDED

typedef struct _colecao_ Collection;

    Collection *Create(int maxElm);
    int InsertElm(Collection *collec,void *item);
    int RemoveElm(Collection *collec, void* key,int (*cmp)(void*, void*));
    void* QueryELm(Collection *collec, void* key,int (*cmp)(void*, void*));
    void List(Collection* collec, void (*allCollec)(void*));
    int Destroy(Collection* collec);

#endif
