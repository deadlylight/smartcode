#include <stdlib.h>
#include <stdio.h>

char* intToRoman(int num) {
    static int steps[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1, 0};
    static char* numstrs[1001] = {0};
    int index = 0;
    int* psteps;
    char* result;

    numstrs[1] = "I";
    numstrs[4] = "IV";
    numstrs[5] = "V";
    numstrs[9] = "IX";
    numstrs[10] = "X";
    numstrs[40] = "XL";
    numstrs[50] = "L";
    numstrs[90] = "XC";
    numstrs[100] = "C";
    numstrs[400] = "CD";
    numstrs[500] = "D";
    numstrs[900] = "CM";
    numstrs[1000] = "M";
#define append(x) result[index++] = x[0]; if (x[1]) result[index++] = x[1];

    if (num == 0) return "";
    result = malloc(64);
    if (!result) return "";

    for (psteps = steps; *psteps; psteps++) {
        while (num >= *psteps) {
            char* numstr = numstrs[*psteps];
            append(numstr);
            num -= *psteps;
        }
    }
    result[index++] = 0;
    return result;
}

int main()
{
    printf("%s\n", intToRoman(XX));
    return 0;
}
