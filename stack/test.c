#include <stdio.h>
#include "stack.h"

int main(int argc, char const *argv[])
{
    Stack S;
    InitStack(&S);
    for (int i = 0; i < 10; i++)
    {
        StackPush(&S, i * 2);
    }

    ShowStack(S);

    ElemType e;
    for (int i = 0; i < 5; i++)
    {
        StackPop(&S, &e);
        printf("Pop: %d\n", e);
        ShowStack(S);
    }

    return 0;
}
