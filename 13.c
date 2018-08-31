

int romanToInt(char* s) {
    static int valuemap[256] = {0};
#define combine4 'I'+'V'*256
#define combine9 'I'+'X'*256
#define combine40 'X'+'L'*256
#define combine90 'X'+'C'*256
#define combine400 'C'+'D'*256
#define combine900 'C'+'M'*256

    int result = 0;
    valuemap['I'] = 1;
    valuemap['V'] = 5;
    valuemap['X'] = 10;
    valuemap['L'] = 50;
    valuemap['C'] = 100;
    valuemap['D'] = 500;
    valuemap['M'] = 1000;

    if (!s) return 0;
    while (*s) {
        unsigned short combine = *((unsigned short*)s);
        switch (combine) {
            case combine4:
                result += 4;
                s++;
                break;
            case combine9:
                result += 9;
                s++;
                break;
            case combine40:
                result += 40;
                s++;
                break;
            case combine90:
                result += 90;
                s++;
                break;
            case combine400:
                result += 400;
                s++;
                break;
            case combine900:
                result += 900;
                s++;
                break;
            default:
                result += valuemap[*s];
        }
        s++;
    }
    return result;
}

#include <stdio.h>
int main(int argc, char** argv)
{
    printf("%d\n", romanToInt(argv[1]));
    return 0;
}

