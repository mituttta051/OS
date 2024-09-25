#include <stdio.h>
#include <stdlib.h>

int tri(int* p, int n);

int main() {
    const int x = 1;
    const int* q = &x;
    int * const p = malloc(3 * sizeof(int));
    *p = *q;
    *(p + 1) = *q;
    *(p + 2) = 2 * *q;
    printf("%p\n", p);
    printf("%p\n", p + 1);
    printf("%p\n", p + 2);


    int n = 4;
    int result = tri(p, n);
    printf("Tribonacci number T%d = %d\n", n, result);

    free(p);
    return 0;
}

int const_tri(int* p, int n) {
    if (n == 0) {
        return *p;
    }
    if (n == 1) {
        return *(p + 1);
    }
    if (n == 2) {
        return *(p + 2);
    }
    return tri(p, n - 1) + tri(p, n - 2) + tri(p, n - 3);
}