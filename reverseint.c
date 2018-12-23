int reverse(int x) {
    int y = x;
    int ret = 0;
    if (x < 0) {
        y = -x;
    }
    while (y) {
        int tmp = y % 10;
        int newret = ret*10 + tmp;
        if (newret < ret) return 0;
        y /= 10;
        ret = newret;
    }
    if (x < 0) {
        ret = -ret;
    }
    return ret;
}
