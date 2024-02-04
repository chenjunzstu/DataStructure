#ifndef _SORT_H
#define _SORT_H

#define MAXSIZE 10000
typedef struct{
    int r[MAXSIZE + 1];
    int length;
}Sqlist;

void swap(Sqlist *sl, int i, int j);
void bubbleSore(Sqlist *sl);
void selectSort(Sqlist *sl);
void insertSort(Sqlist *sl);
void shellSort(Sqlist *sl);
void heapAdjust(Sqlist *sl, int s, int len);
void heapSort(Sqlist *sl);
void mergeSort(int arr[], int tmp[], int start, int end);
void merge(int arr[], int tmp[], int left, int leftEnd, int right, int rightEnd);
void quickSort(Sqlist *sl, int start, int end);

#endif