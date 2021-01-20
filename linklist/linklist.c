#include "linklist.h"
#include <stdlib.h>
#include <stdio.h>

Status GetElem(LinkList L, int i, ElemType *e);
int LocateItem(LinkList L, ElemType e);
Status InsertItem(LinkList *L, int i, ElemType e);
Status DeleteItem(LinkList *L, int i, ElemType *e);
void CreateListHead(LinkList *L, int n, ElemType datas[]);
void CreateListTail(LinkList *L, int n, ElemType datas[]);
void ClearList(LinkList *L);
void ShowList(LinkList L);

Status GetElem(LinkList L, int i, ElemType *e)
{
    Node *p = L->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return ERROR;
    *e = p->data;
    return OK;
}

int LocateItem(LinkList L, ElemType e)
{
    int pos = 0;
    Node *p = L->next;
    while (p)
    {
        pos++;
        if (p->data == e)
            break;
        p = p->next;
    }
    if (pos <= 0 || !p)
        return -1;
    else
        return pos;
}

Status InsertItem(LinkList *L, int i, ElemType e)
{
    Node *p = *L;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return ERROR;
    Node *q = (Node *)malloc(sizeof(Node));
    q->data = e;
    q->next = p->next;
    p->next = q;
    return OK;
}

Status DeleteItem(LinkList *L, int i, ElemType *e)
{
    int j = 1;
    Node *p = *L;
    while (p->next && j < i)
    {
        j++;
        p = p->next;
    }
    if (j > i || !(p->next))
        return ERROR;
    Node *q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}

void CreateListHead(LinkList *L, int n, ElemType datas[])
{
    *L = (Node *)malloc(sizeof(Node));
    (*L)->next = NULL;
    Node *head = *L;
    Node *p;
    for (int i = 0; i < n; i++)
    {
        p = (Node *)malloc(sizeof(Node));
        p->data = datas[i];
        p->next = head->next;
        head->next = p;
    }
}

void CreateListTail(LinkList *L, int n, ElemType datas[])
{
    *L = (Node *)malloc(sizeof(Node));
    (*L)->next = NULL;
    Node *r = *L;
    Node *p;
    for (int i = 0; i < n; i++)
    {
        p = (Node *)malloc(sizeof(Node));
        p->data = datas[i];
        r->next = p;
        r = p;
    }
    r->next = NULL;
}

void ClearList(LinkList *L)
{
    Node *p, *q;
    p = (*L)->next;
    while (p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
}

void ShowList(LinkList L)
{
    Node *p = L->next;
    int count = 0;
    while (p)
    {
        if (count == 0)
            printf("index | value | address\n");
        count++;
        printf("%5d | %5d | %p\n", count, p->data, p);

        p = p->next;
    }
    printf("List length: %d\n", count);
}
