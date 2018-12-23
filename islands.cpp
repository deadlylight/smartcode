#include<vector>
#include<queue>
#include<stdio.h>

using namespace std;

class Solution {
    int vsize, hsize, islands;
    queue<pair<int, int>> landq;
    vector<vector<char>> visited;
    void visit(vector<vector<char>>& grid, int y, int x) {
        if (y < 0) return;
        if (x < 0) return;
        if (y >= vsize) return;
        if (x >= hsize) return;
        if (grid[y][x] == 1 && visited[y][x] != 1) {
            visited[y][x] = 1;
            pair<int, int> p(y, x);
            landq.push(p);
        }
    }
    void checkIsland(vector<vector<char>>& grid)
    {
        if (landq.size() == 0) return;
        ++islands;
        while (landq.size() > 0) {
            pair<int, int> p = landq.front();
            landq.pop();
            visit(grid, p.first-1, p.second);
            visit(grid, p.first+1, p.second);
            visit(grid, p.first, p.second-1);
            visit(grid, p.first, p.second+1);
        }
    }
    public:
        int numIslands(vector<vector<char>>& grid) {
            islands = 0;
            vsize = grid.size();
            if (vsize == 0) {
                return 0;
            }
            hsize = grid[0].size();
            visited.clear();
            visited.resize(vsize);
            for (int y = 0; y < vsize; ++y) {
                visited[y].resize(hsize, 0);
            }
            for (int y = 0; y < vsize; ++y) {
                for (int x = 0; x < hsize; ++x) {
                    visit(grid, y, x);
                    checkIsland(grid);
                }
            }
            return islands;
        }
};


int main()
{
    vector<char> v1;
    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(0);
    vector<char> v2;
    v2.push_back(1);
    v2.push_back(1);
    v2.push_back(0);
    v2.push_back(1);
    v2.push_back(0);
    vector<char> v3;
    v3.push_back(1);
    v3.push_back(1);
    v3.push_back(0);
    v3.push_back(0);
    v3.push_back(0);
    vector<char> v4;
    v4.push_back(0);
    v4.push_back(0);
    v4.push_back(0);
    v4.push_back(0);
    v4.push_back(0);

    vector<vector<char>> grid;
    grid.push_back(v1);
    grid.push_back(v2);
    grid.push_back(v3);
    grid.push_back(v4);

    vector<vector<char>> grid2 = grid;
    Solution s;
    printf("%d\n", s.numIslands(grid));
    printf("%d\n", s.numIslands(grid2));
    return 0;
}
