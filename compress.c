#include <stdio.h>
#include <stdlib.h>

char * compress(char * old)
{
    char * new;
    char * p1, *p2;
    int len;
    if (old == NULL) {
        return old;
    }
    for (len = 0; old[len] != 0; len++);
    if (len == 0) {
        return old;
    }
    new = (char *)malloc(len*2);
    if (new == NULL) {
        return old;
    }
    p1 = old;
    p2 = new;
    while (*p1) {
        int count = 1;
        int width = 1;
        int tmp;
        char c = *p1;
        p1++;
        while (*p1 == c) {
            count++;
            p1++;
        }
        *p2 = c;
        p2++;
        for (tmp = count; tmp / 10 > 0; tmp = tmp /10) {
            width++;
        }
        tmp = width;
        while (tmp > 0) {
            tmp--;
            p2[tmp] = (count%10) + '0';
            count = count / 10;
        }
        p2 += width;
    }
    *p2 = 0;
    if ((p2 - new) < (p1 - old)) {
        return new;
    }
    printf("tmp=%s\n",new);
    free(new);
    return old;
}

int main(int argc, char** argv)
{
    printf("%s\n", compress(argv[1]));
    return 0;
}
