#include "function.h"

void CreateGraph(MGraph *G) {
  printf("请输入顶点数和边数：\n");
  scanf("%d, %d", &G->numVertexes, &G->numEdges);
  int i = 0, j = 0, k = 0, w = 0;
  // 建立顶点表
  for (i = 0; i < G->numVertexes; i++) {
    scanf(&G->vexs[i]);
  }
  // 初始化边表(全部置为无穷大)
  for (i = 0; i < G->numVertexes; i++) {
    for (j = 0; j < G->numVertexes; j++) {
      G->arc[i][j] = INFINITY;
    }
  }
  // 建立边表
  for (k = 0; k < G->numEdges; k++) {
    printf("请输入边（Vi，Vj）的下标和权w：\n");
    scanf("%d, %d, %d", &i, &j, &w);
    G->arc[i][j] = w;
    G->arc[j][i] = G->arc[i][j];  // 无向图邻接矩阵对称
  }
}