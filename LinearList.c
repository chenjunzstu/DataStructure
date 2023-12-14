#include "LinearList.h"
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

bool getElm(Seqlist *L, unsigned int i, elmtype *e)
{
    if(L->listLength == 0 || i > L->listLength - 1)
    {
        return false;
    }

    *e = L->data[i];
    return true;
}

bool insertElm(Seqlist *L, unsigned int i, elmtype e)
{
    if(L->listLength == MAX_SIZE || i < 1 || i > MAX_SIZE - 1)
    {
        return false;
    }

    if(i < L->listLength)
    {
        for(int k = L->listLength; k > i; k--)
        {
            L->data[k] = L->data[k - 1];
        }
    }

    L->data[i] = e;
    L->listLength++;
    return true;
}

bool delElm(Seqlist *L, unsigned int i)
{
    if(L->listLength == 0 || i > L->listLength -1)
    {
        return false;
    }
    if(i < L->listLength - 1)
    {
        for(int k = i; k < L->listLength - 1; k++)
        {
            L->data[k] = L->data[k + 1];
        }
    }
    L->listLength--;
    return true;
}

bool SL_getElm(Node *L, int i, elmtype *e)
{
    Node* p;
    p = L->next;
    int j;
    for(j = 0; j != i; j++)
    {
        p = p->next;
    }
    if(j > i || !p)
    {
        return false;
    }
    *e = p->data;
    return true;
}

bool SL_insertElm(Node *L, int i, elmtype e)
{
    Node* p;
    p = L->next;
    int j;
    if(i == 0)
    {
        Node* s = (Node*)malloc(sizeof(Node));
        s->data = e;
        s->next =L->next;
        L->next = s;
        return true;
    }
    for(j = 0; j < i - 1; j++)
    {
        p = p->next;
    }
    if(j > i - 1|| !p)
    {
        return false;
    }
    Node* s = (Node*)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool SL_delElm(Node *L, int i)
{
    Node *p,*q;
    p = L->next;
    int j;
    if(i == 0)
    {
        L->next = p->next;
        free(p);
        return true;
    }
    for(j = 0; j != i - 1; j++)
    {
        p = p->next;
    }
    if(j > i - 1|| !(p->next))
    {
        return false;
    }
    q = p->next;
    p->next = q->next;
    free(q);
    return true;
}

void creSLHead(Node **L, int n)
{
    Node *p;
    srand(time(0));
    *L = (Node*)malloc(sizeof(Node));
    (*L)->next = NULL;
    for(int i = 0; i < n; i++)
    {
        p = (Node*)malloc(sizeof(Node));
        p->data = rand()%100 + 1;
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

void cerSLTail(Node **L, int n)
{
    Node *p,*q;
    srand(time(0));
    *L = (Node*)malloc(sizeof(Node));
    (*L)->next = NULL;
    q = *L;
    for(int i = 0; i < n; i++)
    {
        p = (Node*)malloc(sizeof(Node));
        p->data = rand()%100 + 1;
        q->next = p;
        q = p;
    }
    q->next = NULL;
}

bool delSLList(Node **L)
{
    Node *p,*q;
    p = (*L)->next;
    while (p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return true;
}
