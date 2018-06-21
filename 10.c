#include <stdio.h>
#define bool int
#define true 1
#define false 0

bool isMatch(char* s, char* p) {
    if (!s) {
        return false;
    }
    if (!p) {
        return false;
    }
    if (*p == '*') {
        return false;
    }
    while (*s) {
        int match = 0;
        char preceding = 0;
        while (*p) {
            match = 0;
            if(p[1] == '*') {
                preceding = p[0];
                p++;
                while (*p == '*') {
                    p++;
                    
                }
                if (isMatch(s, p)) {
                    return true;
                }
                while (*s && (preceding == '.' || preceding == *s)) {
                    s++;
                    if (isMatch(s, p)) {
                        return true;
                    }
                }
                if (!*s && !*p) {
                    return true;
                }
                return false;
            }
            if (*p == '.') {
                match = 1;
            }
            if (*p == *s) {
                match = 1;
            }
            s++;
            p++;
            break;
        }
        if (!match) {
            return false;
        }
    }
    while (*p) {
        if (p[1] != '*') {
            return false;
        }
        p += 2;
    }
    return true;
}

int main(int argc, char** argv)
{
    printf("%s\t\t\t%s\t\t\t%d\n", argv[1], argv[2], isMatch(argv[1], argv[2]));

    return 0;
}
