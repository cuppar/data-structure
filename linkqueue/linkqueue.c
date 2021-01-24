#include <stdio.h>
#include <stdlib.h>
#include "linkqueue.h"

void InitLinkQueue(LinkQueue *q);
void ShowLinkQueue(LinkQueue q);
Status EnLinkQueue(LinkQueue *q, ElemType e);
Status DeLinkQueue(LinkQueue *q, ElemType *e);
int LinkQueueLength(LinkQueue q);

void InitLinkQueue(LinkQueue *q)
{
    QNode *n = (QNode *)malloc(sizeof(QNode));
    n->next = NULL;
    q->front = q->rear = n;
}

void ShowLinkQueue(LinkQueue q)
{
    printf("Link queue length: %d\n", LinkQueueLength(q));
    printf("queue: ");
    QNode *p = q.front->next;

    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

Status EnLinkQueue(LinkQueue *q, ElemType e)
{
    QNode *s = (QNode *)malloc(sizeof(QNode));
    if (!s)
        return ERROR;
    s->data = e;
    s->next = NULL;
    q->rear->next = s;
    q->rear = s;
    return OK;
}

Status DeLinkQueue(LinkQueue *q, ElemType *e)
{
    if (q->front == q->rear)
        return ERROR;
    QNode *p = q->front->next;
    *e = p->data;
    q->front->next = p->next;
    free(p);
    if (p == q->rear)
        q->rear = q->front;
    return OK;
}

int LinkQueueLength(LinkQueue q)
{
    int count = 0;
    QNode *p = q.front->next;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}
