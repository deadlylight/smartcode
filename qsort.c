#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX 30

static int round = 0;

void print(int * arr, int size)
{
    int i = 0;
    while (i < size) {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
}

void myqsort(int * arr, int size, int level)
{
    print(arr, size);
    int pivot;
    int i;
    int j;
    int tmp;
    if (size <= 1) {
        return;
    } else if (size == 2) {
        if (arr[0] > arr[1]) {
            tmp = arr[0];
            arr[0] = arr[1];
            arr[1] = tmp;
        }
        return;
    }

    round++;
    i = 0;
    j = size - 1;
    pivot = (arr[0] + arr[size/2] + arr[size-1]) / 3;
    pivot = arr[size/2];
    while (i < j) {
        while ((arr[i] < pivot) && (i < j)) {
            i++;
        }
        while ((arr[j] > pivot) && (j > i)) {
            j--;
        }
        if (i < j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
        printf("============\t======== ");
        print(arr,size);
    }
    printf("level=%d, pivot=%d, i=%d, j=%d\n", level, pivot, i, j);
    if (pivot == arr[i]) {
        if (i == 0) {
            i++;
        }
        if (i == size -1) {
            i--;
        }
    }
    assert(i+1 < size);
    myqsort(arr, i+1, level+1);
    myqsort(arr+i+1, size-i-1, level+1);
}

void fill(int ** parr, int size)
{
    int * arr = (int*)malloc(size*sizeof(int));
    int i;
    for (i = 0; i < size; i++) {
        arr[i] = rand() % (MAX*10);
    }
    *parr = arr;
}

void fill2(int ** parr, int * size)
{
    *parr = {286, 293, 286, 290};
    *size = 4;
}

int main(int argc, char** argv)
{
    int *arr;
    int size = rand() % MAX;
    if (argc > 1) {
        int seed;
        seed = atoi(argv[1]);
        srand(seed);
    }
    //fill(&arr, size);
    fill2(&arr, &size);
    myqsort(arr, size, 0);
    print(arr,size);
    return 0;
}
