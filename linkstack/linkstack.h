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
};


#endif // LINKSTACK_H_