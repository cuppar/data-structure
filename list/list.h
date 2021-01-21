#ifndef LIST_H_
#define LIST_H_

#define LIST_LEN 2

#include <stdbool.h>
#include "../utils/utils.h"

typedef struct
{
  ElemType *items;
  int length;
  int max_len;
} List;

// init the List with length 0 and void* head pointer
void InitList(List *l);
// print the List to STDOUT
void ShowList(List l);

int ListEmpty(List l);
void ClearList(List *l);
void DestoryList(List *l);
bool InsertItem(List *l, int index, ElemType e);
bool DeleteItem(List *l, int index, ElemType *e);
bool GetItem(List l, int index, ElemType *e);
int LocateItem(List l, ElemType e);
void UnionList(List *la, List lb);

#endif
