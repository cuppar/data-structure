#if !defined(LINKQUEUE_H_)
#define LINKQUEUE_H_

#include "../utils/utils.h"

typedef struct QNode
{
    ElemType data;
    struct QNode *next;
} QNode, *QNodePtr;

typedef struct LinkQueue
{
    QNodePtr front, rear;
} LinkQueue;

void InitLinkQueue(LinkQueue *q);
void ShowLinkQueue(LinkQueue q);
Status EnLinkQueue(LinkQueue *q, ElemType e);
Status DeLinkQueue(LinkQueue *q, ElemType *e);
int LinkQueueLength(LinkQueue q);


#endif // LINKQUEUE_H_
