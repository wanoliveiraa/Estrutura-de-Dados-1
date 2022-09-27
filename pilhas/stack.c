#include"stack.h";
typedef struct _stack_{
    int maxElms;
    int top;
    void **elm;
}Stack;
//Criar Pilha-----------------------------------------
Stack *stkCreat(int max){

    Stack *s;

    if(max>0){

        s = (Stack*)malloc(sizeof(Stack));

        if(s!=NULL){

            s->elm = (void**)malloc(sizeof(void*)*max);

            if(s->elm!=NULL){

                s->maxElms = max;
                s->top = -1;
                return s;
            }
        free(s);
        }
    }
    return NULL;
}
//Destruir Pilha-------------------------------------------
int *stkDestroy(void){
    if(s!=NULL){
        if(s->top<0){
            free(s->elm);
            free(s);
            return 1;
        }
    }
    return 0;
}
//Colocar elemento na Pilha-------------------------
Stack *stkPush(Stack *s, void *elm){
    if(s!=NULL){
        if(s->top < s->maxElms){
            elm++;
            s->elm[s->top] = elm;
            return 1;
        }
    }
    return 0;
}
//Retirar elemento da pilha -------------------------
Stack *stkPop(Stack *s, void *elm){
    void *aux;
    if(s!=NULL){
        if(s->top>=0){
            aux = s->elm[s->top];
            s->top--;
            return aux;
        }
    }
    return  NULL;
}
//Verifica o elemento que está no Topo sem remover;
void stkTop(Stack *s){

    void *aux;
    if(s!=NULL){
        if(s->top>=0){
            aux = s->elm[s->top];
            return aux;
        }
    }
    return  NULL;
}
//Verifica se a pilha está vazia
int *stkIsEmpyt(Stack *s){
    if(s!=NULL){
        if(s->top>=0){
            return 1;
        }
        return 0;
    }
}
