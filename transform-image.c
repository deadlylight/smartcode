#include <stdio.h>

#define N 9
int arr[N][N];

void print(int (*img)[N], int n)
{
    int i;
    int j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%4d", img[i][j]);
        }
        printf("\n");
    }
}

void transform(int img[][N], int n)
{
    int bound1 = (n+1)/2;
    int bound2= n /2;
    int last = n -1;
    int i;
    int j;
    for(i = 0; i < bound1; i++) {
        for (j = 0; j < bound2; j++) {
            int tmp = img[i][j];
            img[i][j] = img[last-j][i];
            img[last-j][i] = img[last-i][last-j];
            img[last-i][last-j] = img[j][last-i];
            img[j][last-i] = tmp;
        }
    }
}

int main(int argc, char** argv)
{
    int i;
    int j;
    int n = atoi(argv[1]);

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            arr[i][j] = i*N+j;
        }
    }
    print(arr, n);
    transform(arr, n);
    printf("=================================\n");
    print(arr, n);
    return 0;
}
