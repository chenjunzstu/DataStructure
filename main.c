#include <stdio.h>
#include "sort.h"

Sqlist array = {
    {0,2,4,9,88,69,94,99,1},
    8
};

int tmp[20];
void printSqlist(Sqlist L)
{
    for(int i = 1; i <= L.length; i++)
    {
        printf("%d ", L.r[i]);
    }
    printf("\n");
}
int main()
{
    quickSort(&array, 1, 8);
    printSqlist(array);
    return 0;
}