#include "stack.h"
#include <stdlib.h>

bool push(Odstack *S, elmtype e)
{
    if(S->SKtop == MAX_SIZE - 1)
    {
        return false;
    }
    S->SKtop++;
    S->data[S->SKtop] = e;
    return true;
}

bool pop(Odstack *S, elmtype e)
{
    if(S->SKtop < 0)
    {
        return false;
    }
    S->SKtop--;
    return true;
}

bool link_push(LinkStack *S, elmtype e)
{
    LinkStack *p = (LinkStack*)malloc(sizeof(LinkStack));
    p->data = e;
    p->next = S->top;
    S->top = p;
    return true;
}

bool link_pop(LinkStack *S)
{
    LinkStack *p;
    if(!(S->top))
    {
        return false;
    }
    p = S->top;
    free(p);
    return true;    
}
