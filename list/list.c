#include <stdio.h>
#include "list.h"
#include <stdlib.h>

void InitList(List *l);
void ShowList(List l);
int ListEmpty(List l);
void ClearList(List *l);
bool InsertItem(List *l, int index, DataType e);
bool GetItem(List l, int index, DataType *e);
int LocateItem(List l, DataType e);
void UnionList(List *la, List lb);

// init the List with length 0 and void* head pointer
void InitList(List *l)
{
  l->items = malloc(LIST_LEN * sizeof(DataType));
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

// void ClearList(List *l);

bool InsertItem(List *l, int index, DataType e)
{
  if (l->length >= l->max_len)
  {
    int new_max_len = l->max_len * 2;
    List new_l;
    new_l.length = l->length;
    new_l.max_len = new_max_len;
    new_l.items = malloc(new_max_len * sizeof(DataType));
    for (int i = 0; i < l->length; i++)
    {
      new_l.items[i] = l->items[i];
    }
    free(l->items);
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
// bool GetItem(List l, int index, DataType *e);
// int LocateItem(List l, DataType e);
// void UnionList(List *la, List lb);
