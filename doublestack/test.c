#include <stdio.h>
#include "doublestack.h"

int main(int argc, char const *argv[])
{
    DoubleStack S;
    InitDoubleStack(&S);
    for (int i = 0; i < 10; i++)
    {
        DoubleStackPush(&S, i * 2, 1);
    }

    for (int i = 0; i < 10; i++)
    {
        DoubleStackPush(&S, i * 3, 2);
    }

    ShowDoubleStack(S);

    ElemType e = 0;
    for (int i = 0; i < 5; i++)
    {
        DoubleStackPop(&S, &e, 1);
        printf("Stack 1 pop: %d\n", e);
        ShowDoubleStack(S);
    }
    for (int i = 0; i < 5; i++)
    {
        DoubleStackPop(&S, &e, 2);
        printf("Stack 2 pop: %d\n", e);
        ShowDoubleStack(S);
    }

    return 0;
}
