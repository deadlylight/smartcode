#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX 10000

static int round = 0;

void print(int * arr, int size)
{
    int i = 0;
    while (i < size) {
        printf("%.8d\n", arr[i]);
        i++;
    }
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
    static int arr[] = {286, 293, 285, 290};
    *parr = arr;
    *size = 4;
}

void insertsort(int* arr, int size)
{
    int i;
    int j;
    int v;
    for (i = 1; i < size; i++) {
        v = arr[i];
        for (j = i-1; j >= 0; j--) {
            if (v >= arr[j]) {
                arr[j+1] = v;
                break;
            } else {
                arr[j+1] = arr[j];
                arr[j] = v;
            }
        }
    }
}















































void insertsort2(int *arr, int size)
{
    int i;
    int j;
    for (i = 1; i < size; i++) {
        int tmp = arr[i];
        for(j = i-1; (j >= 0) && arr[j] > tmp; j--) {
            arr[j+1] = arr[j];
        }
        arr[j+1] =tmp;
    }
}

void shellsort(int *arr, int size)
{
    int step;
    int i;
    int j;
    for (step = size/2; step > 0; step /= 2)
    {
        for (i = step; i < size; i++) {
            int tmp = arr[i];
            for (j = i - step; (j >=0) && (arr[j] > tmp); j -= step) {
                arr[j+step] = arr[j];
            }
        //    arr[j+step] = tmp;
        }
    }
}

int main(int argc, char** argv)
{
    int *arr;
    int size;
    if (argc > 1) {
        int seed;
        seed = atoi(argv[1]);
        srand(seed);
    }
    size = rand() % MAX;
    fill(&arr, size);
    //fill2(&arr, &size);

    //myqsort(arr, size, 0);
    //insertsort(arr, size);
    //insertsort2(arr, size);
    shellsort(arr, size);

    print(arr,size);
    return 0;
}
