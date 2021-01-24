#include <stdio.h>
#include "linkqueue.h"

int main(int argc, char const *argv[])
{
    LinkQueue q;
    InitLinkQueue(&q);

    printf("EnQueue 5 item\n");
    for (int i = 0; i < 5; i++)
    {
        EnLinkQueue(&q, i);
    }
    ShowLinkQueue(q);

    printf("DeQueue 3 item\n");
    ElemType e;
    for (int i = 0; i < 3; i++)
    {
        printf("De queue index %d item ", i);
        if (OK == DeLinkQueue(&q, &e))
            printf("success: %d\n", e);
        else
            printf("fail\n");
    }
    ShowLinkQueue(q);

    printf("EnQueue 5 item\n");
    for (int i = 0; i < 5; i++)
    {
        EnLinkQueue(&q, i);
    }
    ShowLinkQueue(q);

    return 0;
}
