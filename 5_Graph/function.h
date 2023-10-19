#include <stdio.h>
// 图的五种存储结构
// 1、邻接矩阵
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

// 邻接表

// 十字链表

// 邻接多重表

// 边集数组