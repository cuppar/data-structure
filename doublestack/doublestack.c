#include <stdio.h>
#include "doublestack.h"

void InitDoubleStack(DoubleStack *S);
Status DoubleStackPush(DoubleStack *S, ElemType e, int stackNumber);
Status DoubleStackPop(DoubleStack *S, ElemType *e, int stackNumber);
int DoubleStackLength(DoubleStack S, int stackNumber);
void ShowDoubleStack(DoubleStack S);

void InitDoubleStack(DoubleStack *S)
{
    S->top1 = -1;
    S->top2 = DOUBLE_STACK_MAX_LEN;
}

Status DoubleStackPush(DoubleStack *S, ElemType e, int stackNumber)
{
    if (S->top1 + 1 == S->top2)
        return ERROR;
    if (stackNumber == 1)
    {
        S->top1++;
        S->data[S->top1] = e;
    }
    else if (stackNumber == 2)
    {
        S->top2--;
        S->data[S->top2] = e;
    }
    return OK;
}

Status DoubleStackPop(DoubleStack *S, ElemType *e, int stackNumber)
{
    if (stackNumber == 1)
    {
        if (S->top1 == -1)
            return ERROR;
        *e = S->data[S->top1];
        S->top1--;
    }
    else if (stackNumber == 2)
    {
        if (S->top2 == DOUBLE_STACK_MAX_LEN)
            return ERROR;
        *e = S->data[S->top2];
        S->top2++;
    }
    return OK;
}

int DoubleStackLength(DoubleStack S, int stackNumber)
{
    if (stackNumber == 1)
    {
        return S.top1 + 1;
    }
    else if (stackNumber == 2)
    {
        return DOUBLE_STACK_MAX_LEN - S.top2;
    }
}

void ShowDoubleStack(DoubleStack S)
{
    printf("Stack 1 length: %d\n", DoubleStackLength(S, 1));
    printf("Stack 2 length: %d\n", DoubleStackLength(S, 2));

    printf("---------\n");
    printf("|idx|val|\n");
    for (int i = DOUBLE_STACK_MAX_LEN - 1; i >= S.top2; i--)
    {
        if (i == S.top2)
            printf("|%3d|%3d| <== top2\n", i, S.data[i]);
        else
            printf("|%3d|%3d|\n", i, S.data[i]);
    }
    for (int i = S.top1; i > -1; i--)
    {
        if (i == S.top1)
            printf("|%3d|%3d| <== top1\n", i, S.data[i]);
        else
            printf("|%3d|%3d|\n", i, S.data[i]);
    }
    printf("---------\n");
}
