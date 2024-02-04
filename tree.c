#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

void preOrder(Btree bt)
{
    if(bt == NULL)
    {
        return;
    }
    printf("%d\n",bt->data);
    preOrder(bt->left);
    preOrder(bt->right);
}

void inOrder(Btree bt)
{
    if(bt == NULL)
    {
        return;
    }
    inOrder(bt->left);
    printf("%d",bt->data);
    inOrder(bt->right);
}

void postOrder(Btree bt)
{
    if(bt == NULL)
    {
        return;
    }
    printf("%d",bt->data);
    inOrder(bt->left);
    inOrder(bt->right);
}
BiThrTree pre;
void inThrTree(BiThrTree btt)
{
    if(btt)
    {
        inThrTree(btt->lchild);
        if(!btt->lchild)
        {
            btt->Ltag = Thread;
            btt->lchild = pre;
        }
        printf("%c\n",btt->data);
        if(!pre->rchild)
        {
            pre->Rtag = Thread;
            pre->rchild = btt;
        }
        pre = btt;
        inThrTree(btt->rchild);
    }
}