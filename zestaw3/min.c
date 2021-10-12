#include <stdio.h>

int heap_size;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int A[], int i)
{
    int l = 2 * i + 1, r = 2 * i + 2, largest;
    if (l < heap_size && A[l] > A[i])
        largest = l;
    else
        largest = i;
    if (r < heap_size && A[r] > A[largest])
        largest = r;
    if (largest != i)
    {
        swap(&A[i], &A[largest]);
        heapify(A, largest);
    }
}

void build_heap(int A[])
{
    for (int i = (heap_size - 2) / 2; i >= 0; --i)
    {
        heapify(A, i);
    }
}

int main()
{
    int k, sum = 0;
    scanf("%d %d", &heap_size, &k);
    int A[heap_size];
    for (int i = 0; i < heap_size; ++i)
    {
        scanf("%d", &A[i]);
    }
    build_heap(A);
    while (k--)
    {
        A[0] = A[0] / 2;
        heapify(A, 0);
    }
    for (int i = 0; i < heap_size; ++i)
    {
        sum += A[i];
    }
    printf("%d\n", sum);
    return 0;
}