
void visit(char** grid, int gridRowSize, int gridColSize, int i, int j) {
    grid[i][j] = 2;
#define TRYNEXT(x, y) if (x>=0 && x<gridRowSize && y>=0 && y<gridColSize && grid[x][y]==1) visit(grid, gridRowSize, gridColSize, x, y);
    TRYNEXT((i-1), j);
    TRYNEXT((i+1), j);
    TRYNEXT(i, (j-1));
    TRYNEXT(i, (j+1));
}

int numIslands(char** grid, int gridRowSize, int gridColSize) {
    int i, j;
    int count = 0;
    for (i = 0; i < gridRowSize; i++) {
        for (j = 0; j < gridColSize; j++) {
            if (grid[i][j] == 1) {
                count++;
                visit(grid, gridRowSize, gridColSize, i, j);
            }
        }
    }
    for (i = 0; i < gridRowSize; i++) {
        for (j = 0; j < gridColSize; j++) {
            if (grid[i][j] == 2) {
                grid[i][j] = 1;
            }
        }
    }
    return count;
}

char grida[][5] = {
    {1,1,1,1,0},
    {1,1,0,1,0},
    {1,1,1,0,1},
    {0,0,1,0,0},
    {0,0,0,0,0},
};

#include<stdio.h>
int main()
{
    char* gridb[5] = {
        grida[0],
        grida[1],
        grida[2],
        grida[3],
        grida[4],
    };
    printf("%d\n", numIslands(gridb, 5, 5));
    return 0;
}
