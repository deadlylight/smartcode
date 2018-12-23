char* reverseString(char* s) {
    char *p = s;
    int len;
    int i;
    if (!s) return NULL;
    while (*p) p++;
    len = p - s;
    for (i = 0; i < len/2; i++) {
        char tmp = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = tmp;
    }
    return s;
}
