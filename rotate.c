#include<stdio.h>

#define MAX 5

#define PRINT(x) {\
    int i; \
    int j; \
    for (i = 0; i < MAX; i++) { \
        for (j = 0; j < MAX; j++) { \
            printf("%3d, ", x[i][j]); \
        } \
        printf("\n"); \
    } \
}

void rotate(int** matrix, int matrixRowSize, int *matrixColSizes) {
    int size = matrixRowSize;
    int start = 0;
    *matrixColSizes = matrixRowSize;

    if (size < 1) return;

    while (size > 1) {
        int i;
        int j;
        for (i = 0; i < size - 1; i++) {
#define VV(a, b) matrix[a+start][b+start]
            int tmp = VV(0, i);
            VV(0, i) = VV(size-1-i, 0);
            VV(size-1-i, 0) = VV(size-1, size-1-i);
            VV(size-1, size-1-i) = VV(i, size-1);
            VV(i, size-1) = tmp;

        }
        size -= 2;
        start += 1;
    }
}

int main()
{
    int i;
    int j;
    int arr[MAX][MAX];
    int *matrix[MAX];
    int out;

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            int v = i*MAX+j;
            arr[i][j] = v;
        }
        matrix[i] = arr[i];
    }
    PRINT(arr);
    rotate(matrix, MAX, &out);
    printf("====================================\n");
    PRINT(arr);

    return 0;
}

