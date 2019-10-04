#include <stdio.h>
#include <limits.h>

#define MaxVertexNum 8
typedef char VertexType;
typedef int Adjmatrix;
typedef struct {
    VertexType vexs[MaxVertexNum];  /*顶点数组*/
    Adjmatrix arcs[MaxVertexNum][MaxVertexNum];  /*二维数组组成的正方形矩阵*/
} MGraph;

/* 用邻接矩阵表示法构造无向图G, n为顶点数量, e为边的数量 */
void CreateMGraph(MGraph * G, int n, int e)
{
    int i, j, k, w;
    // printf("请输入点位数和边数(n,e):");
    // scanf("%d,%d", &n, &e);
    printf("请输入点位值(如5个结点传入abcde):");
    for (i = 0; i < n; i++) {
        scanf("%c", &G->vexs[i]);  // %c前面必须有空格, 否则上面输入的回车会带到此处来
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            G->arcs[i][j] = INT_MAX;
        }
    }

    printf("请输入边和权重(格式为:d,d,d):\n");
    for (k = 0; k < e; k++) {
        scanf(" %d,%d,%d", &i, &j, &w);
        G->arcs[i][j] = w;
        G->arcs[j][i] = w;
    }
}

/**
 * 深度优先遍历
 * i 为遍历的起始点
 * n 为顶点数量
*/
void DFS(MGraph G, int i, int n)
{
    static int visited[MaxVertexNum];
    printf("%c(%d)->", G.vexs[i], i);
    visited[i] = 1;
    for (int j = 0; j < n; j++) {
        if (visited[j] == 0 && G.arcs[i][j] != INT_MAX) {
            DFS(G, j, n);
        }
    }
}

/**
 * 广度优先遍历
 * i 为遍历起始点
 * n 为顶点数量
*/
void BFS(MGraph G, int i, int n)
{
    int visited[n];
    int k, j;
    for (j = 0; j < n; j++) {
        visited[j] = 0;
    }
    int Q[n], head = 0, rear = 0;     // 模拟队列
    printf("%c(%d)->", G.vexs[i], i);
    visited[i] = 1;
    Q[rear++] = i;
    while (head != rear) {  // 当队列不为空时
        k = Q[head++];
        for (j = 0; j < n; j++) {
            if (visited[j] == 0 && G.arcs[k][j] != INT_MAX) {
                visited[j] = 1;
                printf("%c(%d)->", G.vexs[j], j);
                Q[rear++] = j;
            }
        }
    }
}

int main()
{
    MGraph G;
    int n = 5, e = 5;
    CreateMGraph(&G, n, e);
    // DFS(G, 0, n);
    DFS(G, 0, n);
    printf("\n");
    BFS(G, 0, n);
    return 0;
}