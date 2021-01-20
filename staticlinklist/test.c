#include <stdio.h>
#include "staticlinklist.h"
#define INIT_LEN 10

int main(int argc, char const *argv[])
{

    StaticLinkList L;
    InitList(L);
    printf("List length: %d\n", ListLength(L));
    ShowList(L);
    int datas[INIT_LEN] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    printf("Head insert: \n");
    CreateListHead(L, INIT_LEN, datas);
    ShowList(L);
    ClearList(L);

    printf("Tail insert: \n");
    CreateListTail(L, INIT_LEN, datas);
    ShowList(L);

    ElemType getElem;
    for (int i = -1; i < 12; i++)
    {
        printf("Get index %d item ", i);
        if (GetElem(L, i, &getElem))
        {
            printf("success: %d\n", getElem);
        }
        else
        {
            printf("fail\n");
        }
    }

    for (int i = -1; i < 12; i++)
    {
        printf("Locate item %d: %d\n", i, LocateItem(L, i));
    }

    ElemType insertElemArr[] = {-1, 0, 12, 11, 1, 5};
    for (int i = 0; i < 6; i++)
    {
        printf("Insert index %d item %d ", insertElemArr[i], insertElemArr[i]);
        if (InsertItem(L, insertElemArr[i], insertElemArr[i]))
        {
            printf("success\n");
        }
        else
        {
            printf("fail\n");
        }
        ShowList(L);
    }

    ElemType deleteElemArr[] = {-1, 0, 14, 13, 1, 5};
    ElemType deleteElem;
    for (int i = 0; i < 6; i++)
    {
        printf("Delete index %d item ", deleteElemArr[i]);
        if (DeleteItem(L, deleteElemArr[i], &deleteElem))
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
