int past(int h, int m, int s) {
    int result = 0;
    result = h*3600000 + m*60000 + s*1000;
    return result;
}
