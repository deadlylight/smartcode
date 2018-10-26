#include<vector>
#include<stack>
#include<stdio.h>
using namespace std;

class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& T) {
            stack<pair<int, int>> works;
            vector<int> result(T.size());
            for (int i = 0; i < T.size(); ++i) {
                int v = T[i];
                while (!works.empty()) {
                    pair<int, int> p = works.top();
                    if (v <= p.first) {
                        break;
                    }
                    works.pop();
                    //printf("out %d, %d\n", p.first, p.second);
                    result[p.second] = i - p.second;
                }
                //printf("in %d, %d\n", v, i);
                pair<int, int> newp(v, i);
                works.push(newp);
            }

            while (!works.empty()) {
                pair<int, int> p = works.top();
                result[p.second] = 0;
                works.pop();
            }
            return result;
        }
};

int main()
{
    vector<int> in;
    vector<int> out;
    Solution s;

    in.push_back(73);
    in.push_back(74);
    in.push_back(75);
    in.push_back(71);
    in.push_back(69);
    in.push_back(72);
    in.push_back(76);
    in.push_back(73);
    out = s.dailyTemperatures(in);
    for(int i = 0; i < out.size(); i++) {
        printf("%d ", out[i]);
    }
    printf("\n");
    return 0;
}
