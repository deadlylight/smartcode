#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int* self;
    int selfsize;
    int* peer;
    int peersize;
    int done = 0;
    int last1 = 0;
    int last2 = 0;
    int left = 1 + ((nums1Size + nums2Size) / 2);
    int direct = (nums1Size + nums2Size) % 2;

    if (nums1Size == 0 && nums2Size == 0) {
        return (double)0;
    } else if (nums1Size == 0 || nums2Size == 0) {
        self = (nums2Size == 0) ? nums1 : nums2;
        peersize = 0;
    } else {
        if (nums1[0] < nums2[0]) {
            self = nums1;
            selfsize = nums1Size;
            peer = nums2;
            peersize = nums2Size;
        } else {
            self = nums2;
            selfsize = nums2Size;
            peer = nums1;
            peersize = nums1Size;
        }
    }
    while (left > 0) {
        int* tmp;
        int tmpsize;

        if (peersize == 0) {
            while (left > 0) {
                last2 = last1;
                last1 = *self;
                self++;
                left--;
            }
            break;
        }
        while (left > 0) {
            last2 = last1;
            last1 = *self;
            self++;
            selfsize--;
            left--;
            if (selfsize == 0) {
                break;
            }
            if (*self > *peer) {
                break;
            }
        }
        //swap
        tmp = self;
        self = peer;
        peer = tmp;
        tmpsize = selfsize;
        selfsize = peersize;
        peersize = tmpsize;
    }

    if (direct) {
        return (double)last1;
    } else {
        return ((double)last1 + last2) / 2;
    }
}

int main()
{
    int n1[] = {1,3};
    //int n2[] = {2, 7, 100};
    int n2[] = {2,10};

    //printf("%e\n", findMedianSortedArrays(n1, sizeof(n1)/sizeof(int), NULL, 0));
    printf("%e\n", findMedianSortedArrays(n1, sizeof(n1)/sizeof(int), n2, sizeof(n2)/sizeof(int)));

    return 0;
}
