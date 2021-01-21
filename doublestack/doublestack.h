#if !defined(DOUBLE_STACK_H_)
#define DOUBLE_STACK_H_

#define DOUBLE_STACK_MAX_LEN 100
#include "../utils/utils.h"


typedef struct DoubleStack
{
    ElemType data[DOUBLE_STACK_MAX_LEN];
    int top1;
    int top2;
} DoubleStack;

void InitDoubleStack(DoubleStack *S);
Status DoubleStackPush(DoubleStack *S, ElemType e, int stackNumber);
Status DoubleStackPop(DoubleStack *S, ElemType *e, int stackNumber);
int DoubleStackLength(DoubleStack S, int stackNumber);
void ShowDoubleStack(DoubleStack S);

#endif // DOUBLE_STACK_H_
