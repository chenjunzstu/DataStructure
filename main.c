#include <stdio.h>
#include "LinearList.h"

void begin()
{
    printf("Thanks for checking!\n");
    printf("This project achieves data structure for computer beginers by C.\n");
    printf("You can communicate on issues if you find mistakes or have problems.\n");
}
void printSLList(Node *L)
{
    Node *p;
    p = L->next;
    printf("SLList data: ");
    while(p->next)
    {
        printf("%d ", p->data);
        p=p->next;
    }
    printf("%d ", p->data);
    printf("\n");
}
void printSeqlist(Seqlist L)
{
    for (int i = 0; i < L.listLength; i++)
    {
        if(i == 0)
        {
            printf("Data: ");
        }
        printf("%d ",L.data[i]);
        if(i == L.listLength - 1)
        {
            printf("\n");
        }
    }
}
int main()
{
    begin();

    return 0;
}