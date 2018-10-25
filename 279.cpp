#include<stdio.h>
#include<queue>
#include<set>
using namespace std;

class Solution {
    public:
        int numSquares(int n) {
            int steps = 0;
            queue<int> workq;

            workq.push(n);
            while(!workq.empty()) {
                ++steps;
                int size = workq.size();
                while(size > 0) {
                    --size;
                    int v = workq.front();
                    workq.pop();
                    int i = 0;
                    while(1) {
                        ++i;
                        int left = v - i*i;
                        if (left == 0) {
                            return steps;
                        }
                        if (left < 0) {
                            break;
                        }
                        workq.push(left);
                    }
                }
            }
            return -1;
        }
};


int main()
{
    int x;
    Solution s;
    x=5; printf("%d, %d\n", x, s.numSquares(x));
    x=10; printf("%d, %d\n", x, s.numSquares(x));
    x=12; printf("%d, %d\n", x, s.numSquares(x));
    x=13; printf("%d, %d\n", x, s.numSquares(x));
    x=88889; printf("%d, %d\n", x, s.numSquares(x));
    return 0;
}
