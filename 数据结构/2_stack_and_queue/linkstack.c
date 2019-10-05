#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct stacknode {
    DataType data;
    struct stacknode * next;
} StackNode;
typedef StackNode * LinkStack;

// 判断栈是否为空
int StackEmpty(LinkStack top)
{
    return top == NULL;
}

LinkStack Push(LinkStack top, DataType data)
{
    StackNode *p;
    p = (StackNode *)malloc(sizeof(StackNode));
    p->data = data;
    p->next = top;
    top = p;
    return top;
}

LinkStack Pop(LinkStack top, DataType *x)
{
    if (StackEmpty(top)) {
        printf("stack empty\n");
        exit(0);
    }
    StackNode *p = top;
    *x = p->data;
    top = p->next;
    free(p);
    return top;
}

DataType GetTop(LinkStack top)
{
    return top->data;
}

LinkStack top;  // 全局声明, 默认值为NULL， 局部声明, 默认值不确定
int main()
{
    top = Push(top, 12);
    DataType x;
    top = Pop(top, &x);
    printf("%d\n", x);
}