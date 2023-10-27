#include <stdio.h>
#include <stdlib.h>
// 图的五种存储结构
// 1、邻接矩阵(缺点：边数相对顶点数较少时，造成物理存储浪费)
// 要点：一维数组存顶点，二维数组存边
typedef char VertexType;
typedef int EdgeType;
#define MAXVEX 100
#define INFINITY 65535 //用65535表示∞
typedef struct MGraph{
    VertexType vexs[MAXVEX];
    EdgeType arc[MAXVEX][MAXVEX];
    int numVertexes;//图中当前顶点数
    int numEdges;//图中当前的边数
}MGraph;
// 构造一个图（无向图）
void CreateMGraph(MGraph *G);

// 2、邻接表
// 要点：一维数组存顶点信息，链表存储边信息（包括权值）
//先建立边表
typedef struct EdgeNode{
    int adjvex;
    EdgeType weight;
    struct EdgeNode* next;
}EdgeNode;
//再建立顶点表
typedef struct VertexNode{
    VertexType data;
    EdgeNode* firstEdge;
}VertexNode;
//整合成邻接表
typedef struct GraphAdjList{
    VertexNode adjList[MAXVEX];
    int numVertexes, numEdges;//当前的顶点数和边数
}GraphAdjList;
//构造一个图
void CreateALGraph(GraphAdjList* G);

// 十字链表（只用于存储有向图）

// 邻接多重表（只能用于存储无向图）

// 边集数组