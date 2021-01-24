#include <stdio.h>
#include "queue.h"

int main(int argc, char const *argv[])
{
    Queue q;
    InitQueue(&q);

    printf("EnQueue 5 int\n");
    for (int i = 0; i < 5; i++)
    {
        EnQueue(&q, i);
    }
    ShowQueue(q);

    printf("DeQueue 3 int\n");
    ElemType e;
    for (int i = 0; i < 3; i++)
    {
        printf("DeQueue index %d item ", i);
        if (OK == DeQueue(&q, &e))
            printf("success: %d\n", e);
        else
            printf("fail\n");
    }
    ShowQueue(q);

    printf("EnQueue 5 int\n");
    for (int i = 0; i < 5; i++)
    {
        EnQueue(&q, i);
    }
    ShowQueue(q);

    return 0;
}
