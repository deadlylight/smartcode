#include<vector>
#include<stack>
#include<stdio.h>
#include<queue>

using namespace std;

class Solution {
    struct PP
    {
        int r;
        int c;
        PP(int a, int b) {
            r =a ;
            c = b;
        }
    };
    public:
        vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
            const int rows = matrix.size();
            const int columns = matrix[0].size();
            const static int invalid = 1000000;
            vector<vector<int>> ret(rows);
            queue<PP> s;

            for (int i = 0; i < rows; i++) {
                ret[i].resize(columns, invalid);
                for (int j = 0; j < columns; j++) {
                    if (matrix[i][j] == 0) {
                        s.push(PP(i,j));
                        ret[i][j] = 0;
                    }
                }
            }
            while (s.size() > 0) {
                int cursize = s.size();
                while (cursize > 0) {
                    cursize--;
                    PP p = s.front();
                    s.pop();
                    int r = p.r;
                    int c = p.c;
                    int val = ret[r][c] + 1;
#define CHECK(x, y, v) if (x >= 0 && x < rows) if (y >=0 && y < columns) \
                    if (ret[x][y] > v) {\
                        ret[x][y] = v;\
                        s.push(PP(x, y));\
                    }
                    CHECK(r-1, c, val);
                    CHECK(r+1, c, val);
                    CHECK(r, c-1, val);
                    CHECK(r, c+1, val);
                }
            }
            return ret;
        }
};

int main()
{
    vector<int> v;
    vector<vector<int>> vv;
#define PPP(a,b,c,d) v.clear(); v.push_back(a); v.push_back(b); v.push_back(c); v.push_back(d); vv.push_back(v);
    PPP(1,0,1,1);
    PPP(1,1,1,1);
    PPP(1,1,0,1);

    Solution s;
    vector<vector<int>> ret = s.updateMatrix(vv);

    for (int i = 0; i < ret.size(); i++) {
        for (int j = 0; j < ret[0].size(); j++) {
            printf("%8d ", ret[i][j]);
        }
        printf("\n");
    }

    return 0;
}
