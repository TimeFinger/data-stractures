#include <stdio.h>
#include <stdlib.h>

typedef char DataType;
typedef struct dlnode {
    DataType data;
    struct dlnode *prior, *next;
} DLinkNode;
typedef DLinkNode *DLinkList;

// 创建链表
DLinkList CreateDLinkList()
{
    DLinkList head = (DLinkNode *)malloc(sizeof(DLinkNode));
    DLinkNode *p = head;
    DataType data;
    DLinkNode *np;
    while ((data = getchar()) != '\n') {
        np = (DLinkNode *)malloc(sizeof(DLinkNode));
        np->data = data;
        np->prior = p;
        p->next = np;
        p = np;
    }
    return head;
}

// 在已知节点前插入节点
void InsertDLinkList(DLinkNode *p, DataType data)
{
    DLinkNode *np = (DLinkNode *)malloc(sizeof(DLinkNode));
    np->data = data;
    np->prior = p->prior;
    np->next = p;
    p->prior->next = np;
    p->prior = np;

}

// 删除一个指定结点 如果删除第n个结点, 是不是逻辑和单链表一样了？ 
DataType DeleteDLinkList(DLinkNode *p)
{
    p->prior->next = p->next;
    p->next->prior = p->prior;
    DataType data = p->data;
    free(p);
    return data;
}

// 打印链表, 先正向再逆向
void PrintDLinkList(DLinkList head)
{
    DLinkNode *p = head;
    if (!p->data) {
        p = p->next;
    }
    while (p != NULL) {
        printf("%c,", p->data);
        if (!p->next) {
            break;
        }
        p = p->next;
    }
    printf("\n");
    while (p != head) {
        printf("%c,", p->data);
        p = p->prior;
    }
    printf("\n");
}

int main()
{
    DLinkList head = CreateDLinkList();
    PrintDLinkList(head);
    InsertDLinkList(head->next->next, '9');
    PrintDLinkList(head);
    DeleteDLinkList(head->next->next);
    PrintDLinkList(head);
    return 0;
}