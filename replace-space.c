#include<stdio.h>

char string[8192];


char * replace_space(char * string)
{
    int len;
    int newlen;
    int space_count = 0;
    if (string == NULL) {
        return NULL;
    }
    for (len = 0; string[len] != 0; len++) {
        if (string[len] == ' ') {
            space_count++;
        }
    }
    newlen = len + space_count*2;
    string[newlen] = 0;
    while (newlen > 0) {
        newlen--;
        len--;
        if (string[len] == ' ') {
            string[newlen] = '0';
            newlen--;
            string[newlen] = '2';
            newlen--;
            string[newlen] = '%';
        } else {
            string[newlen] = string[len];
        }
    }
    return string;
}

int main(int argc, char** argv)
{
    int i;
    for (i = 0; argv[1][i] != 0; i++) {
        string[i] = argv[1][i];
    }
    string[i] = 0;
    printf("%s\n", replace_space(string));
    return 0;
}
