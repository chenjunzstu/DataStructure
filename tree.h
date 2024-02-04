#ifndef _TREE_H
#define _TREE_H

#include "LinearList.h"

struct BTreeNode{
    elmtype data;
    struct BTreeNode * left;
    struct BTreeNode * right;
};
typedef struct BTreeNode * Btree;

void preOrder(Btree bt);
void inOrder(Btree bt);
void postOrder(Btree bt);

typedef enum{
    Link,
    Thread
} pointerTag;


typedef struct BiThrNode{
    char data;
    struct BiThrNode *lchild,*rchild;
    pointerTag Ltag;
    pointerTag Rtag;
}BiThrNode,*BiThrTree;

void inThrTree(BiThrTree btt);
#endif