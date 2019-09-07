#include <stdio.h>
#include <stdlib.h>

typedef char DataType;
typedef struct node
{
    DataType data;
    struct node *next;
} LinkNode;
typedef LinkNode *LinkList;

// 创建链表, 新结点插入头部
LinkList CreateListF()
{
    LinkList head = NULL;
    LinkNode *p;
    DataType data;
    while ((data = getchar()) != '\n') {
        p = (LinkNode *)malloc(sizeof(LinkNode));
        p->data = data;
        p->next = head;
        head = p;
    }
    return head;
}

// 创建链表, 新结点从尾部插入
LinkList CreateListR()
{
    LinkList head = (LinkNode *)malloc(sizeof(LinkNode));
    LinkNode *rear = head;
    LinkNode *p;
    DataType data;
    while ((data = getchar()) != '\n') {
        p = (LinkNode *)malloc(sizeof(LinkNode));
        p->data = data;
        rear->next = p;
        rear = p;
    }
    rear->next = NULL;
    return head;
}

// 通过索引查找结点
LinkNode *GetNodeByIndex(LinkList head, int i)
{
    if (i < 0) {
        printf("index error\n");
        exit(0);
    }
    LinkNode *p = head;
    if (!p->data) {
        p = p->next;
    }
    int n = 0;
    while (i > n && p->next != NULL) {
        p = p->next;
        n++;
    }
    if (i == n) {
        return p;
    }
    printf("index error2\n");
    exit(0);
}

// 通过值查找结点
LinkNode *LocateNodeByValue(LinkList head, DataType v)
{
    LinkNode *p = head;
    if (!p->data) {
        p = p->next;
    }
    while (p && p->data != v) {
        p = p->next;
    }
    return p;
}

// 插入结点
void InsertList(LinkList head, int i, DataType data)
{
    LinkNode *p = head;
    int n = 0;
    while (n++ < i) {
        p = p->next;
    }
    if (!p) {
        printf("参数i太大\n");
        exit(0);
    }
    LinkNode *np = (LinkNode *)malloc(sizeof(LinkNode));
    np->data = data;
    np->next = p->next;
    p->next = np;
}

DataType DeleteList(LinkList head, int i)
{
    LinkNode *p = head;
    int n = 0;
    while (n++ < i && p->next) {
        p = p->next;
    }
    if (!p->next) {
        printf("参数i太大\n");
        exit(0);
    }
    LinkNode *dp = p->next;
    p->next = p->next->next;
    DataType data = dp->data;
    free(dp);
    return data;
}

// 打印链表
void PrintList(LinkList head)
{
    LinkNode *p = head;
    if (!p->data) {     // 兼容heada结点不是开始结点的情况(哨兵模式))
        p = p->next;
    }
    while (p != NULL) {
        printf("%c, ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    LinkList head;
    LinkNode *p;

    // printf("CreateListF...\n");
    // head = CreateListF();
    // PrintList(head);

    printf("CreateListR...\n");
    head = CreateListR();
    PrintList(head);

    // printf("GetNodeByIndex...\n");
    // int i;
    // scanf("%d", &i);
    // p = GetNodeByIndex(head, i);
    // printf("%c\n", p->data);

    // printf("LocateNodeByValue...\n");
    // char c;
    // scanf("%c", &c);
    // p = LocateNodeByValue(head, c);
    // if (p == NULL) {
    //     printf("未找值为%c的结点\n", c);
    // } else {
    //     printf("已找值为%c的结点\n", c);
    // }

    // printf("InsertList...\n");
    // int i;
    // DataType data;
    // scanf("%d,%c", &i, &data);
    // InsertList(head, i, data);
    // PrintList(head);

    printf("DeleteList...\n");
    int i;
    scanf("%d", &i);
    DataType data = DeleteList(head, i);
    printf("%c\n", data);
    PrintList(head);
    return 0;
}
