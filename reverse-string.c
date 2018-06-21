#include<stdio.h>


char * reverse(char * string)
{
    char * s = string;
    char * e = string;
    if (string == NULL) {
        return NULL;
    }

    while (*e) {
        e++;
    }
    e--;
    while (s < e) {
        char tmp = *s;
        *s = *e;
        *e = tmp;
        s++;
        e--;
    }
    return string;
}

int main(int argc, char** argv)
{
    char * string = argv[1];
    string = reverse(string);
    printf("%s\n", string);
    return 0;
}
