#ifndef LINKLIST_H_
#define LINKLIST_H_

#include "../utils/utils.h"

typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;

typedef Node *LinkList;

Status GetElem(LinkList L, int i, ElemType *e);
int LocateItem(LinkList L, ElemType e);
Status InsertItem(LinkList *L, int i, ElemType e);
Status DeleteItem(LinkList *L, int i, ElemType *e);
void CreateListHead(LinkList *L, int n, ElemType datas[]);
void CreateListTail(LinkList *L, int n, ElemType datas[]);
void ClearList(LinkList *L);
void ShowList(LinkList L);

#endif
