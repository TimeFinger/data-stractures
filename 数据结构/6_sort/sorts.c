#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 20

typedef int ValType;
typedef struct {
    ValType val;
} RecType;
typedef RecType SeqList[MAXSIZE + 1];

void InsertSort(SeqList L, int n)
{
    int i, j;
    for (i = 2; i <= n; i++) {
        if (L[i].val < L[i - 1].val) {
            L[0] = L[i];
            // for (j = i - 1; j > 0; j--) {
            //     if (L[j].val > L[0].val) {
            //         L[j + 1] = L[j];
            //         L[j] = L[0];
            //     } else {
            //         L[j + 1] = L[0];
            //         break;
            //     }
            // }
            for (j = i - 1; L[0].val < L[j].val; j--) {
                L[j + 1] = L[j];
            }
            L[j + 1] = L[0];
        }
    }
}

void BubbleSort(SeqList L, int n)
{
    int i, j;
    short is_exchanged;
    for (i = 1; i < n; i++) {
        is_exchanged = 0;
        for (j = i + 1; j <= n; j++) {
            if (L[i].val > L[j].val) {
                L[0] = L[j];
                L[j] = L[i];
                L[i] = L[0];
                is_exchanged = 1;
            }
        }
        if (!is_exchanged) return;
    }
}

void SelectSort(SeqList L, int n)
{
    int i, j, min;
    for (i = 1; i < n; i++) {
        min = i;
        for (j = i + 1; j <= n; j++) {
            if (L[j].val < L[min].val) {
                min = j;
            }
        }
        if (min != i) {
            L[0] = L[min];
            L[min] = L[i];
            L[i] = L[0];
        }
    }
}

void GenRandSeqList(SeqList L, int n)
{
    srand((unsigned int)time(NULL));
    for (int i = 0; i < n; i++) {
        L[i+1].val = rand() % 100;
    }
}

void ShowSeqList(SeqList L, int n)
{
    for (int i = 1; i <=n; i++) {
        printf("%d, ", L[i].val);
    }
    printf("\n");
}

int main()
{
    int n = 10;
    SeqList L;
    GenRandSeqList(L, n);
    ShowSeqList(L, n);
    // InsertSort(L, n);
    // BubbleSort(L, n);
    SelectSort(L, n);
    ShowSeqList(L, n);
    return 0;
}