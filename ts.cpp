#include<stdio.h>
#include<stack>
#include<vector>
#include<queue>
#include<set>
#include<map>

using namespace std;

#if 0
int findTargetSumWays(int* nums, int numsSize, int S) {
    if (numsSize == 0) {
        return S == 0;
    }
    return findTargetSumWays(nums+1, numsSize-1, S + nums[0]) + findTargetSumWays(nums+1, numsSize-1, S-nums[0]);
}
#endif
#if 1
class Solution {
    public:
        int findTargetSumWays(vector<int>& nums, int S) {
            stack<int> works;
            unordered_map<int, int> used;
            int size = nums.size();
            int ret = 0;

            works.push(0);
            while(works.size() > 0) {
                int tmp = works.top();
                works.pop();
                int sum = tmp >> 16;
                int index = tmp & 0xffff;
                int sum1 = sum + nums[index];
                int sum2 = sum - nums[index];
                if (index == size -1) {
                    ret += (S == sum1);
                    ret += (S == sum2);
                    //printf("sum1=%d, sum2=%d\n", sum1, sum2);
                } else {
                    works.push((sum1<<16)|(index+1));
                    works.push((sum2<<16)|(index+1));
                }
            }
            return ret;
        }
};
#endif

#if 0
class Solution {
    public:
        int findTargetSumWays(vector<int>& nums, int S) {
            queue<int> workq;
            int step = 0;
            workq.push(0);
            int size = nums.size();
            int ret = 0;
            while (step < size) {
                int qsize = workq.size();
                while (qsize > 0) {
                    --qsize;
                    int sum = workq.front();
                    workq.pop();
                    int sum1 = sum + nums[step];
                    int sum2 = sum - nums[step];
                    if (step == size -1) {
                        ret += (sum1 == S);
                        ret += (sum2 == S);
                    } else {
                        workq.push(sum1);
                        workq.push(sum2);
                    }
                }
                ++step;
            }
            return ret;

        }
};
#endif
int main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    int target = 3;
    printf("%d\n", s.findTargetSumWays(nums, target));
    return 0;
}
