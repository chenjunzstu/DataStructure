#ifndef _LINEARLIST_H
#define _LINEARLIST_H

#define MAX_SIZE 20
#define true 1
#define false 0

typedef int elmtype;
typedef int bool;

//Sequential storage liner list
typedef struct Seqlist
{
    elmtype data[MAX_SIZE];//data
    int listLength;//current list length
}Seqlist;

//get the data of Seqlist,save in the e
bool getElm(Seqlist* L, unsigned int i, elmtype* e);
//insert the data to Seqlist,the data before i
bool insertElm(Seqlist* L, unsigned int i, elmtype e);
//delete the data of Seqlist
bool delElm(Seqlist* L, unsigned int i);


//simple link list
typedef struct Node
{
    elmtype data;
    struct Node* next;
}Node;

bool SL_getElm(Node* L, int i, elmtype* e);
bool SL_insertElm(Node* L, int i, elmtype e);
bool SL_delElm(Node* L, int i);
//create simple link list
void creSLHead(Node **L, int n);
void cerSLTail(Node **L, int n);
//delete simple link list
bool delSLList(Node **L);

#endif