#include <stdio.h>
#include "stack.h"

void InitStack(Stack *S);
Status StackPush(Stack *S, ElemType e);
Status StackPop(Stack *S, ElemType *e);
int StackLength(Stack S);
void ShowStack(Stack S);

void InitStack(Stack *S)
{
    S->top = -1;
}

Status StackPush(Stack *S, ElemType e)
{
    if (S->top == STACK_MAX_LEN - 1)
        return ERROR;
    S->top++;
    S->data[S->top] = e;
    return OK;
}

Status StackPop(Stack *S, ElemType *e)
{
    if (S->top == -1)
        return ERROR;
    *e = S->data[S->top];
    S->top--;
    return OK;
}

int StackLength(Stack S)
{
    return S.top + 1;
}

void ShowStack(Stack S)
{
    printf("Stack length: %d\n", StackLength(S));
    printf("---------\n");
    printf("|idx|val|\n");
    for (int i = StackLength(S) - 1; i > -1; i--)
    {
        if (i == StackLength(S) - 1)
            printf("|%3d|%3d| <-- top\n", i, S.data[i]);
        else
            printf("|%3d|%3d|\n", i, S.data[i]);
    }
    printf("---------\n");
}
