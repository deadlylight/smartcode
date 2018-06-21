#include <stdio.h>

int check_same(char * s1, char * s2)
{
    int len1;
    int len2;
    int i, j;
    if (s1 == NULL) {
        return 0;
    }
    if (s2 == NULL) {
        return 0;
    }
    for (len1 = 0; s1[len1] != 0; len1++);
    for (len2 = 0; s2[len2] != 0; len2++);
    if (len1 != len2) {
        return 0;
    }
    for (i = 0; i < len1; i++) {
        for (j = 0; j < len2; j++) {
            if (s1[i] == s2[j]) {
                s2[j] = 0;
                break;
            }
        }
    }
    for (j = 0; j < len2; j++) {
        if (s2[j] != 0) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char** argv)
{
    printf("%d\n", check_same(argv[1], argv[2]));
    return 0;
}
