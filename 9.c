
#define bool int
#define true 1
#define false 0


bool isPalindrome(int x) {
    long long result = 0;
    int old = x;

    if (x == 0) return true;
    if (x < 0) return false;

    while ( x > 0) {
        int tmp = x % 10;
        x /= 10;
        result *= 10;
        result += tmp;
        if (result > 0x7fffffff) return false;
    }
    return old == result;

}


#include<stdio.h>
int main()
{
    printf("%d, %d\n", XX, isPalindrome(XX));
    return 0;
}
