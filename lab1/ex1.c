#include <stdio.h>
#include <float.h>
#include <limits.h>

int main() {
    int a;
    unsigned short b;
    signed long c;
    float d;
    double e;

    a = INT_MAX;
    b = USHRT_MAX;
    c = LONG_MAX;
    d = FLT_MAX;
    e = DBL_MAX;

    printf("%lu %d\n", sizeof(a), a);
    printf("%lu %u\n", sizeof(b), b);
    printf("%lu %ld\n", sizeof(c), c);
    printf("%lu %f\n", sizeof(d), d);
    printf("%lu %lf\n", sizeof(e), e);

}