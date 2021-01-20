#include <stdio.h>
#include "linklist.h"
#define INIT_LEN 10

int main(int argc, char const *argv[])
{
    LinkList L;
    ElemType datas[INIT_LEN] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("Head insert:\n");
    CreateListHead(&L, INIT_LEN, datas);
    ShowList(L);
    printf("Clear list:\n");
    ClearList(&L);
    ShowList(L);

    printf("Tail insert:\n");
    CreateListTail(&L, INIT_LEN, datas);
    ShowList(L);

    ElemType e;

    for (int i = -2; i < 12; i++)
    {
        printf("Get index %d item ", i);
        if (OK == GetElem(L, i, &e))
        {
            printf("success: %d\n", e);
        }
        else
        {
            printf("fail\n");
        }
    }

    for (int i = -2; i < 12; i++)
    {
        printf("Locate item %d: %d\n", i, LocateItem(L, i));
    }

    int insertData[] = {-1, 0, 12, 11, 1, 3, 7};
    for (int i = 0; i < 7; i++)
    {

        printf("Insert index %d item %d ", insertData[i], insertData[i]);
        if (OK == InsertItem(&L, insertData[i], insertData[i]))
        {
            printf("success\n");
        }
        else
        {
            printf("fail\n");
        }
        ShowList(L);
    }

    int deleteData[] = {-1, 0, 16, 15, 14, 3, 7};
    ElemType deleteElem;
    for (int i = 0; i < 7; i++)
    {

        printf("Delete index %d item ", deleteData[i]);
        if (OK == DeleteItem(&L, deleteData[i], &deleteElem))
        {
            printf("success: %d\n", deleteElem);
        }
        else
        {
            printf("fail\n");
        }
        ShowList(L);
    }

    return 0;
}
