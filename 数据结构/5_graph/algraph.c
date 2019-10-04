#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 10
typedef struct node {       // 边表结点结构体
    int adjvex;             // 顶点的序号
    struct node *next;
} EdgeNode;

typedef char VertexType;
typedef struct vnode {      // 顶点表结点结构体
    VertexType vertex;      // 顶点
    EdgeNode *link;         // 边表头指针
}VNode, Adjlist[MaxVertexNum];
typedef Adjlist ALGaph;

/**
 * 创建无向邻接图
 * n 顶点数
 * e 边数
*/
void CreateALGraph(ALGaph GL, int n, int e)     // GL为数组, 数组传参时内部传的便是指向数组的指针, 所有不用加*
{
    int i, j, k;
    for (i = 0; i < n; i++) {
        GL[i].vertex = getchar();
        GL[i].link = NULL;
    }
    EdgeNode *p;
    for (k = 0; k < e; k++) {
        printf("请输入边[%d]:", k);
        scanf("%d,%d", &i, &j);
        p = (EdgeNode *)malloc(sizeof(EdgeNode));
        p->adjvex = j;
        p->next = GL[i].link;
        GL[i].link = p;
        p = (EdgeNode *)malloc(sizeof(EdgeNode));
        p->adjvex = i;
        p->next = GL[j].link;
        GL[j].link = p;
    }
}

/**
 * 深度优先遍历
 * i 起始点
*/
void DFS(ALGaph GL, int i)
{
    static int visited[MaxVertexNum] = {0};
    printf("%c->", GL[i].vertex);
    visited[i] = 1;
    EdgeNode *p;
    p = GL[i].link;
    int j;
    while (p != NULL) {
        j = p->adjvex;
        if (!visited[j]) {
            DFS(GL, j);
        }
        p = p->next;
    }
}

void BFS(ALGaph GL, int i, int n)
{
    int visited[n];
    for (int k = 0; k < n; ++k) {
        visited[k] = 0;
    }

    EdgeNode *p;
    int Q[n], head = 0, rear = 0;
    printf("%c->", GL[i].vertex);
    visited[i] = 1;
    Q[rear++] = i;
    while (rear != head) {
        p = GL[Q[head++]].link;
        while (p != NULL) {
            if (visited[p->adjvex] == 0) {
                printf("%c->", GL[p->adjvex].vertex);
                visited[p->adjvex] = 1;
                Q[rear++] = p->adjvex;
            }
            p = p->next;
        }
    }
}

int main()
{
    ALGaph GL;
    int n = 5, e = 5;
    CreateALGraph(GL, n, e);
    DFS(GL, 0);
    printf("\n");
    BFS(GL, 0, n);
    printf("\n");
    BFS(GL, 3, n);
    return 0;
}