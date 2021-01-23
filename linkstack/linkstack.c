#include "linkstack.h"
#include <stdio.h>
#include <stdlib.h>

void InitLinkStack(LinkStack *S);
void ShowLinkStack(LinkStack S);
int LinkStackLength(LinkStack S);
Status LinkStackPush(LinkStack *S, ElemType e);
Status LinkStackPop(LinkStack *S, ElemType *e);

void InitLinkStack(LinkStack *S)
{
    S->top = NULL;
    S->count = 0;
}

void ShowLinkStack(LinkStack S)
{
    printf("Stack length: %d\n", LinkStackLength(S));
    printf("---------\n");
    printf("|idx|val|\n");
    StackNode *p = S.top;
    int count = LinkStackLength(S) - 1;
    while (p)
    {
        if (count == LinkStackLength(S) - 1)
        {
            printf("|%3d|%3d| <-- top\n", count, p->data);
        }
        else
        {
            printf("|%3d|%3d|\n", count, p->data);
        }
        p = p->next;
        count--;
    }
    printf("---------\n");
}

int LinkStackLength(LinkStack S)
{
    return S.count;
}

Status LinkStackPush(LinkStack *S, ElemType e)
{
    StackNode *p = (StackNode *)malloc(sizeof(StackNode));
    if (!p)
        return ERROR;
    p->data = e;
    p->next = S->top;
    S->top = p;
    S->count++;
    return OK;
}

Status LinkStackPop(LinkStack *S, ElemType *e)
{
    if (!S->top)
        return ERROR;
    StackNode *p = S->top;
    *e = p->data;
    S->top = p->next;
    S->count--;
    free(p);
    return OK;
}
