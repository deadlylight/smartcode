#include<stdio.h>
#include <assert.h>
#include<stdlib.h>
#include <algorithm>
#include<vector>
using namespace std;


int getcount(vector<int>& nums, int target)
{
    int size = nums.size();
    if (nums[0] > target) return 0;
    if (nums[size-1] < target) return 0;
    
    int first = -1;
    int last = -1;
    if (nums[0] == target) {
        first = 0;
    }
    if (nums[size-1] == target) {
        last = size-1;
    }

    //find first
    if (first == -1) {
        int start = 0;
        int end = size-1;
        while (start < end-1) {
            int half = (start + end)/2 ;
 //           printf("start=%d, half=%d, end=%d, val=%d\n", start, half, end, nums[half]);
            if (nums[half] < target) {
                start = half;
            } else {
                end = half;
            }
        }
        if (nums[start+1] == target) {
            first = start+1;
        }
    }
    if (first == -1) {
        return 0;
    }
   // printf("find first=%d\n", first);
    
    //find last
    if (last == -1) {
        int start = first;
        int end = size-1;
        while (start < end-1) {
            int half = (start + end)/2 ;
     //       printf("start=%d, half=%d, end=%d, val=%d\n", start, half, end, nums[half]);
            if (nums[half] > target) {
                end = half;
            } else {
                start = half;
            }
        }
        last = end -1;
    }

//    printf("fist=%d, first-v=%d, firstv=%d, last=%d, lastv=%d last+1v=%d\n",
//            first, first == 0 ? -1 : nums[first-1], nums[first], last, nums[last], last == size-1 ? 0xfffffff : nums[last+1]);
    return last - first + 1;

}


#define MAX 100
int getr()
{
    return rand() % MAX + 30;
}

int main(int argc, char** argv)
{
    vector<int> nums;
    if (argc > 1) {
        srand(atoi(argv[1]));
    }
    int totalcount = 0;
    int total = getr();
    int targetcount = 0;
    int targetval = -1;
    while (total-- > 0) {
        int count = getr();
        int val = getr();
        nums.insert(nums.end(), count, val);
        totalcount += count;
        if (targetval == -1 || targetval == val) {
            targetcount += count;
            targetval = val;
        }
    }
    sort(nums.begin(), nums.end());
//    printf("init done, totalcount=%d, targetval=%d, targetc=%d\n", totalcount, targetval, targetcount);
    for (int i = 0; i < nums.size(); i++) {
 //       printf("yunfei, %d\n", nums[i]);
    }
    int ret = getcount(nums, targetval);
//    printf("targetv=%d, targetc=%d, ret=%d\n", targetval, targetcount, ret);
    assert(targetcount == ret);
    return 0;
}
