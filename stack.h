#ifndef _STACK_H
#define _STACK_H
#include "LinearList.h"

typedef struct Odstack
{
    elmtype data[MAX_SIZE];
    int SKtop;
}Odstack;

bool push(Odstack *S, elmtype e);
bool pop(Odstack *S, elmtype e);

typedef struct LinkStack
{
    elmtype data;
    struct LinkStack *next;
    struct LinkStack *top;
}LinkStack;

bool link_push(LinkStack *S, elmtype e);
//delete stack top
bool link_pop(LinkStack *S);

#endif