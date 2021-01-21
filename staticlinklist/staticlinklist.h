#ifndef STATICLINKLIST_H_
#define STATICLINKLIST_H_

#define MAX_LEN 1000
#include "../utils/utils.h"

typedef struct Node
{
    ElemType data;
    int cur;
} Node;

typedef Node StaticLinkList[MAX_LEN];

Status GetElem(StaticLinkList L, int i, ElemType *e);
int LocateItem(StaticLinkList L, ElemType e);
Status InsertItem(StaticLinkList L, int i, ElemType e);
Status DeleteItem(StaticLinkList L, int i, ElemType *e);
void InitList(StaticLinkList L);
void CreateListHead(StaticLinkList L, int n, ElemType datas[]);
void CreateListTail(StaticLinkList L, int n, ElemType datas[]);
void ClearList(StaticLinkList L);
void ShowList(StaticLinkList L);
int Malloc_sll(StaticLinkList L);
void Free_sll(StaticLinkList L, int p);
int ListLength(StaticLinkList L);

#endif
