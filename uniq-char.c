#include<stdio.h>


int uniq_string(char * string)
{
    char * p;
    char bitmap[(unsigned int)((unsigned char)-1) + 1] = {0};
    if (string == NULL) {
        return 1;
    }
    for (p = string; *p; p++) {
        char b = bitmap[((*p)/8)] & (1 << ((*p)%8));
        if (b != 0) {
            return 0;
        }
        bitmap[((*p)/8)] |= (1 << ((*p)%8));
    }
    return 1;
}

int main(int argc, char** argv)
{
    printf("%d\n", uniq_string(argv[1]));
    return 0;
}
