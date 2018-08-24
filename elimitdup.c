#include <stdio.h>

#define DUPCHAR '_'

void elimitdup(char * s)
{
    char * p1 = s;
    char * p2 = s;
    if (!s) return;

    while (*p2) {
        *p1 = *p2;
        p1++;
        if (*p2 == DUPCHAR) {
            while (*p2 == DUPCHAR) p2++;
        } else {
            p2++;
        }
    }
    *p1 = 0;
}


int main(int argc, char** argv)
{
    elimitdup(argv[1]);
    if (argc > 1) printf("%s\n", argv[1]);
    return 0;
}
