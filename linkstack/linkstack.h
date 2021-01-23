#ifndef LINKSTACK_H_
#define LINKSTACK_H_

#include "../utils/utils.h"

typedef struct StackNode
{
  ElemType data;
  struct StackNode *next;
} StackNode, *LinkStackPtr;

typedef struct LinkStack
{
  LinkStackPtr top;
  int count;
} LinkStack;

void InitLinkStack(LinkStack *S);
void ShowLinkStack(LinkStack S);
int LinkStackLength(LinkStack S);
Status LinkStackPush(LinkStack *S, ElemType e);
Status LinkStackPop(LinkStack *S, ElemType *e);


#endif // LINKSTACK_H_