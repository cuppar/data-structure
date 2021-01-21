#if !defined(STACK_H_)
#define STACK_H_

#define STACK_MAX_LEN 100
#include "../utils/utils.h"


typedef struct Stack
{
    ElemType data[STACK_MAX_LEN];
    int top;
} Stack;

void InitStack(Stack *S);
Status StackPush(Stack *S, ElemType e);
Status StackPop(Stack *S, ElemType *e);
int StackLength(Stack S);
void ShowStack(Stack S);

#endif // STACK_H_
