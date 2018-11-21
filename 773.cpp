
#include<vector>
#include<queue>
#include<set>
using namespace std;


class Solution {
    public:
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
            vector<vector<int>> ret = image;
            int oldColor = image[sr][sc];
            if (oldColor == newColor) return ret;
            floodFill(image, ret, oldColor, newColor, sr, sc);
            return ret;
        }
        void floodFill(vector<vector<int>>& oldImage, vector<vector<int>>& newImage, int oldColor, int newColor, int sr, int sc)
        {
            newImage[sr][sc] = newColor;
#define FF(x, y) if ((x) >= 0 && (x) < oldImage.size()) \
            if ((y) >=0 && (y) < oldImage[0].size()) \
            if (oldImage[x][y] == oldColor && newImage[x][y] != newColor) \
            floodFill(oldImage, newImage, oldColor, newColor, x, y);
            FF(sr, sc-1);
            FF(sr, sc+1);
            FF(sr-1, sc);
            FF(sr+1, sc);
        }
};
