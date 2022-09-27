#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
typedef struct _stack_ Stack;
Stack *stkCreat(int max);
int stkPush(Stack *s, void* elm);
void *stkPop(Stack *s);
void *stkTop(Stack *s);
int *stkIsEmpyt(Stack *s);
int *stkDestroy(Stack *s);
#endif // STACK_H_INCLUDED
