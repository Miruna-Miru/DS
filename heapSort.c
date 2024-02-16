#include<stdio.h>

void swap(int *a, int *b)
{
    int tem = *a;
    *a = *b;
    *b = tem;
}

void maxHeapify(int arr[], int n, int i)
{
    int largest = i, left, right;
    left = 2 * i + 1;
    right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

void heapSort(int arr[], int n)
{
    buildMaxHeap(arr, n);
    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        maxHeapify(arr, i, 0);
    }
}

void display(int arr[], int x)
{
    for (int i = 0; i < x; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n = 7, arr[] = {323, 7, 23, 734, 5, 76, 3};
    display(arr, n);
    heapSort(arr, n);
    display(arr, n);

    return 0;
}
