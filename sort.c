#include <stdlib.h>
#include "sort.h"

void swap(Sqlist *sl, int i, int j)
{
    int t = sl->r[i];
    sl->r[i] = sl->r[j];
    sl->r[j] = t;
}

void bubbleSore(Sqlist *sl)
{
    int flag = 1;
    for(int i = 1; i < sl->length; i++)
    {
        for(int j = 1; j < sl->length - i + 1; j++)
        {
            if(sl->r[j] > sl->r[j+1])
            {
                flag = 0;
                swap(sl, j, j+1);
            }
        }
        if(flag)
        {
            break;
        }
    }
}

void selectSort(Sqlist *sl)
{
    for(int i = 1; i < sl->length; i++)
    {
        int min = i;
        for(int j = i + 1; j <= sl->length; j++)
        {
            if(sl->r[min] > sl->r[j])
            {
                min = j;
            }
        }
        swap(sl, min, i);
    }
}

void insertSort(Sqlist *sl)
{
    for(int i = 2; i <= sl->length; i++)
    {
        int j = i, tmp = sl->r[i];   //j直接变成i，因为前面的都是有序的了，tmp相当于是抽出来的牌暂存一下
        while (j > 0 && sl->r[j - 1] > tmp) 
        {   //只要j>0并且前一个还大于当前待插入元素，就一直往前找
            sl->r[j] = sl->r[j - 1];   //找的过程中需要不断进行后移操作，把位置腾出来
            j--;
        }
        sl->r[j] = tmp;  //j最后在哪个位置，就是是哪个位置插入
    }
}

void shellSort(Sqlist *sl)
{
    int dealt = sl->length / 2;
    while(dealt >= 1)
    {
        for(int h = 1; h <= dealt; h++)
        {
            for(int i = h + dealt; i <= sl->length; i += dealt)
            {
                for(int j = h; j < i; j += dealt)
                {
                    if(sl->r[i] < sl->r[j])
                    {
                        int t = sl->r[i];
                        for(int k = i; k > j; k -= dealt)
                        {
                            sl->r[k] = sl->r[k-dealt];
                        }
                        sl->r[j] = t;
                        break;
                    }
                }
            }
        }
        dealt /= 2;
    }
}

void heapAdjust(Sqlist *sl, int s, int len)
{
    int t = sl->r[s],j;
    for(j = 2 * s; j <= len; j *=2)
    {
        if(sl->r[j] < sl->r[j + 1] && j < len)
        {
            j++;
        }
        if(t >= sl->r[j])
        {
            break;
        }
        sl->r[s] = sl->r[j];
        s = j;
    }
    sl->r[s] = t;
}

void heapSort(Sqlist *sl)
{
    for(int i = sl->length / 2; i > 0; i--)
    {
        heapAdjust(sl, i, sl->length);
    }
    for(int i = sl->length; i > 1; i--)
    {
        swap(sl, i, 1);
        heapAdjust(sl, 1, i - 1);
    }
}

void mergeSort(int arr[], int tmp[], int start, int end)
{
    if(start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    mergeSort(arr, tmp, start, mid);
    mergeSort(arr, tmp, mid + 1, end);
    merge(arr, tmp, start, mid, mid + 1, end);
}

void merge(int arr[], int tmp[], int left, int leftEnd, int right, int rightEnd)
{
    int i = left, size = rightEnd - left + 1;
    while(left <= leftEnd && right <=rightEnd)
    {
        if(arr[left] <= arr[right])
        {
            tmp[i++] = arr[left++];
        }
        else
        {
            tmp[i++] = arr[right++];
        }
    }
    while (left <= leftEnd)    //如果右边看完了，只剩左边，直接把左边的存进去
    {
        tmp[i++] = arr[left++];
    }
    while (right <= rightEnd)   //同上
    {
        tmp[i++] = arr[right++];
    }
    for(int j = 0; j < size; j++, rightEnd--)
    {
        arr[rightEnd] = tmp[rightEnd];
    }
}

void quickSort(Sqlist *sl, int start, int end)
{
    if(start >= end)
    {
        return;
    }
    int left = start, right = end, val = sl->r[left];
    while(left < right)
    {
        while(sl->r[right] >= val && left < right)
        {
            right--;
        }
        sl->r[left] = sl->r[right];
        while(sl->r[left] <= val && left < right)
        {
            left++;
        }
        sl->r[right] = sl->r[left];
    }
    sl->r[left] = val;
    quickSort(sl, start, left - 1);
    quickSort(sl, left + 1, end);
}
