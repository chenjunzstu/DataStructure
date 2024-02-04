#include "graph.h"
#include <stdlib.h>

Graph create()
{
    Graph g = malloc(sizeof(struct Graph));
    g->edgeNum = 0;
    g->vertexNum = 0;
    return g;
}

void addVertex(Graph g, Vdatatype data)
{
    if(g->vertexNum >= MAXVertex)
    {
        return;
    }
    g->vertex[g->vertexNum].data = data;
    g->vertex[g->vertexNum].next = NULL;
    g->vertexNum++;
}

void addEdge(Graph g, int a, int b)
{
    Node newNode = malloc(sizeof(struct Node));
    newNode->next = NULL;
    newNode->nextVertex = b;
    if(!g->vertex[a].next) 
    {    
        //如果头结点下一个都没有，那么直接连上去
        g->vertex[a].next = newNode;
    } 
    else 
    {   //否则说明当前顶点已经连接了至少一个其他顶点了，有可能会出现已经连接过的情况，所以说要特别处理一下
        do 
        {
            if(g->vertex[a].next->nextVertex == b) 
                return;   //如果已经连接了对应的顶点，那么直接返回
            if(g->vertex[a].next->next) 
                g->vertex[a].next = g->vertex[a].next->next;   //否则继续向后遍历
            else 
                break;   //如果没有下一个了，那就找到最后一个结点了，直接结束
        } while (1);
        g->vertex[a].next->next = newNode;
    }
  	g->edgeNum++;   //边数计数+1
}
