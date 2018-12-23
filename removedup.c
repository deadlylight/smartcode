#include<stdio.h>

int singleNumber(int* nums, int numsSize) {
    int i;
    int ret = nums[0];
    for (i = 1; i < numsSize; i++) {
        ret = ret ^ nums[i];
        printf("%d, %d\n", nums[i], ret);
    }
    return ret;
}


int main()
{
    int nums[] = {3,4,5, 6,9,1,1,2 ,6,9,5,4,3};
    printf("%d\n", singleNumber(nums, sizeof(nums)/ sizeof(int)));
    return 0;
}
