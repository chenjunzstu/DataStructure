#include "queue.h"
#include <stdlib.h>

bool InitClqueue(Clqueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return true;
}

int getClqueuelen(Clqueue *Q)
{
    return ((Q->rear - Q->front + MAX_SIZE) % MAX_SIZE);
}

bool enClqueue(Clqueue *Q, elmtype e)
{
    //queue is full
    if((Q->rear + 1) % MAX_SIZE == Q->front)
    {
        return false;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAX_SIZE;
    return true;
}

bool deClqueuq(Clqueue *Q)
{
    //queue is empty
    if(Q->front == Q->rear)
    {
        return false;
    }
    Q->front = (Q->front + 1) % MAX_SIZE;
    return true;
}

bool enLqueue(linkQueue *L, elmtype e)
{
    Qnode *s = (Qnode*)malloc(sizeof(Qnode));
    s->data = e;
    s->next = NULL;
    L->rear->next = s;
    L->rear = s;
    return true;
}

bool deLqueue(linkQueue *L)
{
    if(L->rear == L->front)
    {
        return false;
    }
    Qnode *p = L->front->next;
    if(L->rear == p)
    {
        L->rear = L->front;
    }
    free(p);
    return true;
}
