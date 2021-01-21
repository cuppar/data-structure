#include "list.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
  List l;
  InitList(&l);
  ShowList(l);
  for (int i = 0; i < 20; i++)
  {
    if (InsertItem(&l, i, i))
    {
      printf("Insert %d success\n", i);
    }
    else
    {
      printf("Insert %d fail\n", i);
    }
    ShowList(l);
  }
  ElemType e;
  if (GetItem(l, 5, &e))
  {
    printf("Get 5 item: %d\n", e);
  }
  else
  {
    printf("Get 5 item fail\n");
  }
  printf("Location of data 14: %d\n", LocateItem(l, 14));
  printf("Location of data 24: %d\n", LocateItem(l, 24));

  List l2;
  InitList(&l2);
  InsertItem(&l2, 0, 999);
  InsertItem(&l2, 1, 99);
  InsertItem(&l2, 1, 9);
  InsertItem(&l2, 1, 4);
  InsertItem(&l2, 1, 774);
  printf("L1:\n");
  ShowList(l);
  printf("L2:\n");
  ShowList(l2);
  printf("Union L2 to L1:\n");
  UnionList(&l, l2);
  printf("after union:L1:\n");
  ShowList(l);
  printf("after union:L2:\n");
  ShowList(l2);

  ElemType delItem1, delItem2;
  printf("Delete last item ");
  if (DeleteItem(&l, l.length - 1, &delItem1))
  {
    printf("success: %d\n", delItem1);
  }
  else
  {
    printf("fail\n");
  }
  ShowList(l);

  printf("Delete 7 item ");
  if (DeleteItem(&l, 7, &delItem2))
  {
    printf("success: %d\n", delItem2);
  }
  else
  {
    printf("fail\n");
  }
  ShowList(l);
  

  ClearList(&l);
  printf("Clear List\n");
  ShowList(l);
  printf("Insert List ");
  int status = InsertItem(&l, 0, 5);
  printf("%s\n", status ? "success" : "fail");
  ShowList(l);
  printf("Destory List\n");
  DestoryList(&l);
  printf("sizeof(List): %zu\n", sizeof(List));

  return 0;
}
