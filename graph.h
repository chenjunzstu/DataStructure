#ifndef _GRAPH_H
#define _GRAPH_H

#define MAXVertex 10

typedef char Vdatatype;
//结点和头结点分开定义，普通结点记录邻接顶点信息
typedef struct Node{
    int nextVertex;
    struct Node *next;
} *Node;

//头结点记录元素
typedef struct HeadNode{
    Vdatatype data;
    struct Node *next;
} *HeadNode;

typedef struct Graph{
    int vertexNum;//顶点数
    int edgeNum;//边数
    struct HeadNode vertex[MAXVertex];
} *Graph;

//初始化
Graph create();
//添加节点
void addVertex(Graph g, Vdatatype data);
//添加边
void addEdge(Graph g, int a, int b);

#endif