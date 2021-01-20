#include "staticlinklist.h"
#include <stdlib.h>
#include <stdio.h>

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

Status GetElem(StaticLinkList L, int i, ElemType *e)
{
    if (i < 1 || i > ListLength(L))
        return ERROR;
    int j = 1;
    int p = L[MAX_LEN - 1].cur;
    while (p && j < i)
    {
        p = L[p].cur;
        j++;
    }

    if (!p || j > i)
        return ERROR;
    *e = L[p].data;
    return OK;
}

int LocateItem(StaticLinkList L, ElemType e)
{
    int p = L[MAX_LEN - 1].cur;
    int pos = 0;
    while (p)
    {
        pos++;
        if (L[p].data == e)
        {
            break;
        }
        p = L[p].cur;
    }
    if (!p || pos == 0)
        return -1;
    return pos;
}

Status InsertItem(StaticLinkList L, int i, ElemType e)
{
    int p = MAX_LEN - 1;
    int j = 1;
    while (p && j < i)
    {
        p = L[p].cur;
        j++;
    }
    if (!p || j > i)
        return ERROR;
    int q = Malloc_sll(L);
    if (q)
    {

        L[q].data = e;
        L[q].cur = L[p].cur;
        L[p].cur = q;
        return OK;
    }
    return ERROR;
}

Status DeleteItem(StaticLinkList L, int i, ElemType *e)
{
    int p = MAX_LEN - 1;
    int j = 1;
    while (L[p].cur && j < i)
    {
        p = L[p].cur;
        j++;
    }
    if (!L[p].cur || j > i)
        return ERROR;
    int q = L[p].cur;
    *e = L[q].data;
    L[p].cur = L[q].cur;
    Free_sll(L, q);
    return OK;
}

void InitList(StaticLinkList L)
{
    for (int i = 0; i < MAX_LEN; i++)
    {
        L[i].cur = i + 1;
    }
    L[MAX_LEN - 1].cur = 0;
}

void CreateListHead(StaticLinkList L, int n, ElemType datas[])
{
    int head = MAX_LEN - 1;
    for (int i = 0; i < n; i++)
    {
        int p = Malloc_sll(L);
        L[p].data = datas[i];
        L[p].cur = L[head].cur;
        L[head].cur = p;
    }
}

void CreateListTail(StaticLinkList L, int n, ElemType datas[])
{
    int r = MAX_LEN - 1;
    for (int i = 0; i < n; i++)
    {
        int p = Malloc_sll(L);
        L[p].data = datas[i];
        L[r].cur = p;
        r = p;
    }
    L[r].cur = 0;
}

void ClearList(StaticLinkList L)
{
    int p = L[MAX_LEN - 1].cur;
    int q;
    while (p)
    {
        q = L[p].cur;
        Free_sll(L, p);
        p = q;
    }
}

void ShowList(StaticLinkList L)
{
    printf("List length: %d\n", ListLength(L));
    if (ListLength(L) > 0)
        printf("index | data | self cursor\n");
    int p = L[MAX_LEN - 1].cur;
    int i = 1;
    while (p)
    {
        printf("%5d | %4d | %11d\n", i, L[p].data, p);
        p = L[p].cur;
        i++;
    }
}

int Malloc_sll(StaticLinkList L)
{
    int p = L[0].cur;
    L[0].cur = L[p].cur;
    return p;
}

void Free_sll(StaticLinkList L, int p)
{
    L[p].cur = L[0].cur;
    L[0].cur = p;
}

int ListLength(StaticLinkList L)
{
    int i = L[MAX_LEN - 1].cur;
    int count = 0;
    while (i)
    {
        i = L[i].cur;
        count++;
    }
    return count;
}
