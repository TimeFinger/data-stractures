#include <stdio.h>
#include <stdlib.h>

typedef char DataType;              
typedef struct node {
    DataType data;
    struct node *lchild, *rchild;
} BinTNode;
typedef BinTNode *BinTree;

BinTree CreateBinTree(BinTree bt)
{
    // 不用数组存, 直接用指针指行不行？ 
    // 不行, 因为下面新增加节点时需要知道其双亲结点, 如果不把所有结点按顺序放入一个数组(或队列)中, 无法得知新加结点的双亲结点是哪个结点
    // 数组是为了模拟队列, 不用队列是因为方便查看减少依赖
    BinTNode *Q[100];
    BinTNode *p;
    int front = 1;      // 从1开始计数, 永远指向双亲结点
    int rear = 0;       //  永远指向Q中的最新结点
    DataType ch = getchar();
    while (ch != '#') {     // #代码结束
        p = NULL;
        if (ch != '@') {    // @代表空
            p = (BinTNode *)malloc(sizeof(BinTNode));
            p->data = ch;
            p->lchild = NULL;
            p->rchild = NULL;
        }
        Q[++rear] = p;
        if (rear == 1) {
            bt = p;
        } else if (rear > 1) {
            if (Q[front] != NULL && p != NULL) {
                if (rear % 2 == 0) {        // 为偶数说明为左结点
                    Q[front]->lchild = p;
                } else if (rear % 2 == 1) { // 为奇数说明为右结点
                    Q[front]->rchild = p;
                }
            }
            if (rear % 2 == 1) {        // 如果为奇数, 将front指向下一个双亲结点
                front++;
            }
        }
        ch = getchar();
    }
    return bt;
}

void Preorder(BinTree bt)
{
    if (bt != NULL) {
        printf("addr:%p, data:%c, lchild:%p, rchild:%p\n", bt, bt->data, bt->lchild, bt->rchild);
        Preorder(bt->lchild);
        Preorder(bt->rchild);
    }
}

void Inorder(BinTree bt)
{
    BinTNode *st[100];
    int top = 0;
    st[top] = bt;
    while (top > -1)
    {
        while (st[top] != NULL) {
            top++;
            st[top] = st[top-1]->lchild;
        }
        top--;      // 上面的循环结束后, top指向的必定为空, 所以减1
        if (top >= 0) {
            printf("%c, ", st[top]->data);
            st[top] = st[top]->rchild;      // top所指定的肯定无左结点了, 打印后直接將下级右结点赋值给top的指向, 相当于出栈又进栈
        }
    }
}

int main()
{
    BinTree bt;
    bt = CreateBinTree(bt);
    Preorder(bt);
    Inorder(bt);
    return 0;
}