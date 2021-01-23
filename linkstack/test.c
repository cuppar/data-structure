#include <stdio.h>
#include "linkstack.h"

int main(int argc, char const *argv[])
{
    LinkStack S;
    InitLinkStack(&S);
    ShowLinkStack(S);

    printf("Push 10 items:\n");
    for (int i = 0; i < 10; i++)
    {
        LinkStackPush(&S, i);
    }
    ShowLinkStack(S);

    printf("Pop 5 items:\n");
    ElemType e;
    for (int i = 0; i < 5; i++)
    {
        printf("Pop index %d item ", LinkStackLength(S) - 1);
        if (OK == LinkStackPop(&S, &e))
        {
            printf("success: %d\n", e);
        }
        else
        {
            printf("fail\n");
        }
        ShowLinkStack(S);
    }

    return 0;
}
