int power(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if ((b & 1))
            ans *= a;
        a *= a;
        b = (b >> 1);
    }
    return ans;
}
