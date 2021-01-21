#include <stdio.h>
#include "list.h"
#include <stdlib.h>

void InitList(List *l);
void ShowList(List l);
int ListEmpty(List l);
void ClearList(List *l);
bool InsertItem(List *l, int index, ElemType e);
bool DeleteItem(List *l, int index, ElemType *e);
bool GetItem(List l, int index, ElemType *e);
int LocateItem(List l, ElemType e);
void UnionList(List *la, List lb);
void DestoryList(List *l);

// init the List with length 0 and void* head pointer
void InitList(List *l)
{
  l->items = malloc(LIST_LEN * sizeof(ElemType));
  l->length = 0;
  l->max_len = LIST_LEN;
}

// print the List to STDOUT
void ShowList(List l)
{
  if (ListEmpty(l))
  {
    printf("Empty List\n");
    return;
  }

  printf("List length: %d\n", l.length);
  printf("Index | Value | Location\n");

  for (int i = 0; i < l.length; i++)
  {
    printf("  %3d |   %3d | %p\n", i, l.items[i], &l.items[i]);
  }
}

int ListEmpty(List l)
{
  return !(l.length > 0);
}

void ClearList(List *l)
{
  l->length = 0;
}

void DestoryList(List *l)
{
  ClearList(l);
  free(l->items);
  l->items = NULL;
}

bool InsertItem(List *l, int index, ElemType e)
{
  if (l->length >= l->max_len)
  {
    int new_max_len = l->max_len * 2;
    auto List new_l;
    new_l.length = l->length;
    new_l.max_len = new_max_len;
    new_l.items = (ElemType *)malloc(new_max_len * sizeof(ElemType));
    if (new_l.items == NULL)
    {
      printf("Alloc memory fail!");
      return false;
    }
    for (int i = 0; i < l->length; i++)
    {
      new_l.items[i] = l->items[i];
    }
    DestoryList(l);
    *l = new_l;
    printf("Dynamic grown List to max length %d\n", l->max_len);
  }

  if (index > l->length || index < 0)
    return false;
  for (int i = l->length - 1; i >= index; i--)
  {
    l->items[i + 1] = l->items[i];
  }
  l->items[index] = e;
  l->length++;
  return true;
}

bool DeleteItem(List *l, int index, ElemType *e)
{
  bool success = false;
  if (index < 0 || index >= l->length)
  {
    return success;
  }

  *e = l->items[index];
  for (int i = index; i < l->length - 1; i++)
  {
    l->items[i] = l->items[i + 1];
  }
  l->length--;
  success = true;
  return success;
}

bool GetItem(List l, int index, ElemType *e)
{
  if (index < 0 || index >= l.length)
    return false;
  *e = l.items[index];
  return true;
}

int LocateItem(List l, ElemType e)
{
  int pos = -1;
  for (int i = 0; i < l.length; i++)
  {
    if (l.items[i] == e)
    {
      pos = i;
      break;
    }
  }
  return pos;
}

void UnionList(List *la, List lb)
{
  for (int i = 0; i < lb.length; i++)
  {
    if (LocateItem(*la, lb.items[i]) < 0)
    {
      InsertItem(la, la->length, lb.items[i]);
    }
  }
}
