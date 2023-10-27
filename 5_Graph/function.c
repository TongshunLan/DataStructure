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


void CreateALGraph(GraphAdjList* G){
  int i = 0, j = 0, k = 0;
  EdgeNode* e = NULL;
  printf("请输入顶点数和边数：\n");
  scanf("%d, %d", &G->numVertexes, &G->numEdges);
  //建立顶点表
  for(i = 0; i < G->numVertexes; i++){
    scanf(&G->adjList[i].data);//输入顶点信息
    G->adjList[i].firstEdge = NULL;//置空边表
  }
  //建立边表（对于无向图，注意一条边，会引发两个顶点的邻接信息，下面是利用头插法）
  for(k = 0; k < G->numEdges; k++){
    printf("请输入边（Vi,Vj）上的顶点序号：\n");
    scanf("%d, %d", &i, &j);
    e = (EdgeNode*)malloc(sizeof(EdgeNode));//申请结点空间
    e->adjvex = j;//邻接序号为j
    e->next = G->adjList[i].firstEdge;//e指向当前顶点指向的结点
    G->adjList[i].firstEdge = e;
    e = (EdgeNode*)malloc(sizeof(EdgeNode));
    e->adjvex = i;//邻接序号为i
    e->next = G->adjList[j].firstEdge;
    G->adjList[j].firstEdge = e;
  }
}
