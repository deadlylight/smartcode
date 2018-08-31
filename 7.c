

int reverse(int x) {
    int negtive = 0;
    long long result = 0;

    if (x == 0) return 0;
    if (x < 0) {
        x = -x;
        negtive = 1;
    }
    while ( x > 0) {
        int tmp = x % 10;
        x /= 10;
        result *= 10;
        result += tmp;
        if (result > 0x7fffffff) return 0;
    }
    if (negtive) {
        result = -result;
    }

    return result;
}

#include <stdio.h>
int main()
{
    printf("%d, %d\n", XX, reverse(XX));
    return 0;
}
