#include <stdio.h>

int main() {
    char line[256];
    char c = 'a';
    int i = 0;
    while (c != '.') {
        scanf("%c", &c);
        line[i] = c;
        i++;
    }
    printf("\"");
    for (int j = i-2; j >= 0; j--) {
        printf("%c", line[j]);
    }
    printf("\"");
    return 0;
}