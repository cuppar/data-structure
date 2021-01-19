#include "list.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
  List l;
  InitList(&l);
  ShowList(l);
  for (int i = 0; i < 161; i++)
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

  return 0;
}
