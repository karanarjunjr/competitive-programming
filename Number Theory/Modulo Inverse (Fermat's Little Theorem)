int gcd(int a, int b) {
    if (b == 0)
        return a;
    a %= b;
    return gcd(b, a);
}

int power(int a, int b, int M) {
    int ans = 1;
    while (b > 0) {
        if ((b & 1))
            ans = (a * ans) % M;
        a = (a * a) % M;
        b = (b >> 1);
    }
    return ans;
}

int modInverse(int a, int M) {
    if (gcd(a, M) != 1)
        return -1;
    return power(a, M - 2, M);
}
