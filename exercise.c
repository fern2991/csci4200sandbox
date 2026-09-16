#include <stdio.h>

long scale_and_swap(long *xp, long *yp, long scale) {
    long x = *xp;
    long y = *yp;

    *xp = y * scale;
    *yp = x;

    return x + y;
}

int main() {
    long a = 10;
    long b = 20;
    long result = scale_and_swap(&a, &b, 3);
    printf("Result: %ld, a: %ld, b: %ld\n", result, a, b);
    return 0;
}

