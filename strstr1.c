#include<stdio.h>


char * strstr1(char * txt, char *patten)
{
    char * p1;
    char * p2;
    char * start;
    if ((txt == NULL) || (patten == NULL)) {
        return NULL;
    }
    if (patten[0] == 0) {
        return txt;
    }
    for (start = txt;  *start; start++) {
        p1 = start;
        p2 = patten;
        while (*p1 && *p2) {
            if (*p1 != *p2) {
                break;
            }
            p1++;
            p2++;
        }
        if (*p2 == 0) {
            return start;
        }
    }
    return NULL;
}

int main(int argc, char ** argv)
{
    char * ret = strstr1(argv[1], argv[2]);
    if (ret) {
        printf("%s\n", ret);
    } else {
        printf("%p\n", ret);
    }
    return 0;
}
