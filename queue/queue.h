#if !defined(QUEUE_H_)
#define QUEUE_H_

#include "../utils/utils.h"
#define MAX_QUEUE_LEN 10
typedef struct Queue
{
    ElemType data[MAX_QUEUE_LEN];
    int front, rear;
} Queue;

void InitQueue(Queue *q);
void ShowQueue(Queue q);
int QueueLength(Queue q);
Status EnQueue(Queue *q, ElemType e);
Status DeQueue(Queue *q, ElemType *e);


#endif // QUEUE_H_
