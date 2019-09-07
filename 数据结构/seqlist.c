#include <stdio.h>
#include <stdlib.h>

#define ListSize 100

typedef int DataType;
typedef struct {
    DataType data[ListSize];
    int length;
} SeqList;

void InitList(SeqList *L)
{
    L->length = 0;
}

void InsertList(SeqList *L, int i, DataType x)
{
    if (i > L->length || i < 0 || i > ListSize) {
        printf("overflow");
        return;
    }
    if (L->length == 0 && i == 0) {
        L->data[i] = x;
        L->length++;
    } else if (L->length > 0) {
        for (int j = L->length; j > i; j--) {
            L->data[j] = L->data[j-1];
        }
        L->data[i] = x;
        L->length++;
    }
}

DataType DeleteList(SeqList *L, int i)
{
    if (i >= L->length || i < 0 || i > ListSize || L->length <= 0) {
        printf("overflow");
        exit(0);
    }
    DataType x = L->data[i];
    for (int j = i; j < L->length; j++) {
        L->data[j] = L->data[j+1];
    }
    L->length--;
    return x;
}

SeqList Converts(SeqList L)
{
    if (L.length <= 0) {
        printf("overflow\n");
        exit(0);
    }
    if (L.length == 1) {
        return L;
    }
    int mid = L.length / 2;
    for (int i = 0; i < mid; i++) {
        L.data[i] = L.data[i] + L.data[L.length - 1 - i];
        L.data[L.length - 1 - i] = L.data[i] - L.data[L.length - 1 - i];
        L.data[i] = L.data[i] - L.data[L.length - 1 - i];
    }
    return L;
}

void MaxMin(SeqList L, DataType *max, DataType *min, int *i, int *j)
{
    *max = *min = L.data[0];
    *i = *j = 0;
    for (int n = 1; n < L.length; n++) {
        if (L.data[n] > *max) {
            *max = L.data[n];
            *i = n;
        } else if (L.data[n] < *min) {
            *min = L.data[n];
            *j = n;
        }
    }
}

void ShowList(SeqList L)
{
    for (int i = 0; i < L.length; i++) {
        printf("%d, ", L.data[i]);
    }
    printf("\n");
}

int main()
{
    SeqList L;
    InitList(&L);
    for (int i = 0; i < 10; i++) {
        InsertList(&L, L.length, i);
    }
    ShowList(L);
    DeleteList(&L, 4);
    ShowList(L);
    DeleteList(&L, 7);
    ShowList(L);
    SeqList newL = Converts(L);
    ShowList(newL);
    InsertList(&L, 3, 100);
    InsertList(&L, 6, -100);
    ShowList(L);
    
    int max, min, i, j;
    MaxMin(L, &max, &min, &i, &j);
    printf("Max:%d, Min:%d, i:%d, j:%d\n", max, min, i, j);
    return 0;
}