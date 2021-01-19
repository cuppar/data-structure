#ifndef LIST_H_
#define LIST_H_

#define LIST_LEN 2

#include <stdbool.h>
typedef int DataType;

typedef struct
{
  DataType *items;
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
bool InsertItem(List *l, int index, DataType e);
bool DeleteItem(List *l, int index, DataType *e);
bool GetItem(List l, int index, DataType *e);
int LocateItem(List l, DataType e);
void UnionList(List *la, List lb);

#endif
