#ifndef _QUEUE_H
#define _QUEUE_H

#include "LinearList.h"

//cycle queue
typedef struct Clqueue
{
    elmtype data[MAX_SIZE];
    int front;
    int rear;
}Clqueue;

bool InitClqueue(Clqueue *Q);
int getClqueuelen(Clqueue *Q);
bool enClqueue(Clqueue *Q, elmtype e);
bool deClqueuq(Clqueue *Q);

//node struct
typedef struct Qnode
{
    elmtype data;
    struct Node *next;
}Qnode;
//link queue
typedef struct linkQueue
{
    Qnode *front,*rear;
}linkQueue;

bool enLqueue(linkQueue *L, elmtype e);
bool deLqueue(linkQueue *L);

#endif