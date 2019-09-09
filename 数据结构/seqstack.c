#include <stdio.h>
#include <stdlib.h>

#define StackSize 100

typedef char DataType;
typedef struct {
    DataType data[StackSize];
    int top;
} SeqStack;

void InitStack(SeqStack *s)
{
    s->top = -1;
}

int StackEmpty(SeqStack *s)
{
    return s->top == -1;
}

int StackFull(SeqStack *s)
{
    return s->top == StackSize - 1;
}

void Push(SeqStack *s, DataType data)
{
    if (StackFull(s)) {
        printf("stack overflow");
        exit(0);
    }
    s->data[++s->top] = data;
}

DataType Pop(SeqStack *s)
{
    if (StackEmpty(s)) {
        printf("stack underflow");
        exit(0);
    }
    return s->data[s->top--];
}

DataType GetTop(SeqStack *s)
{
    if (StackEmpty(s)) {
        printf("stack underflow");
        exit(0);
    }
    return s->data[s->top--];
}

int main()
{
    SeqStack s;
    InitStack(&s);
    printf("top:%d\n", s.top);
    Push(&s, 'a');
    Push(&s, 'b');
    Push(&s, 'c');
    Push(&s, 'd');
    Push(&s, 'e');
    for (int i = 0; i <= s.top; i++) {
        printf("No.%d:%c\n", i, s.data[i]);
    }
    DataType x = Pop(&s);
    printf("pop:%c\n", x);
    printf("top:%d\n", s.top);
}