#include <stdio.h>
#include "queue.h"

void InitQueue(Queue *q);
void ShowQueue(Queue q);
int QueueLength(Queue q);
Status EnQueue(Queue *q, ElemType e);
Status DeQueue(Queue *q, ElemType *e);

void InitQueue(Queue *q)
{
    q->front = q->rear = 0;
}

void ShowQueue(Queue q)
{
    printf("Queue length: %d\n", QueueLength(q));
    printf("Queue: ");
    int j = q.front;
    for (int i = 0; i < QueueLength(q); i++)
    {
        printf("%d ", q.data[j]);
        j = (j + 1) % MAX_QUEUE_LEN;
    }
    printf("\n");
    printf("---------\n");
    printf("|idx|val|\n");
    for (int i = 0; i < MAX_QUEUE_LEN; i++)
    {
        if (i == q.front && i == q.rear)
            printf("|%3d|%3d| <== front, rear\n", i, q.data[i]);
        else if (i == q.front)
            printf("|%3d|%3d| <== front\n", i, q.data[i]);
        else if (i == q.rear)
            printf("|%3d|%3d| <== rear\n", i, q.data[i]);
        else
            printf("|%3d|%3d|\n", i, q.data[i]);
    }
    printf("---------\n");
}

int QueueLength(Queue q)
{
    return (q.rear - q.front + MAX_QUEUE_LEN) % MAX_QUEUE_LEN;
}

Status EnQueue(Queue *q, ElemType e)
{
    // Queue is fill or not
    if ((q->rear + 1) % MAX_QUEUE_LEN == q->front)
        return ERROR;
    q->data[q->rear] = e;
    q->rear = (q->rear + 1) % MAX_QUEUE_LEN;
    return OK;
}

Status DeQueue(Queue *q, ElemType *e)
{
    // queue is empty or not
    if (q->front == q->rear)
        return ERROR;
    *e = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_LEN;
    return OK;
}
