#include <unistd.h>
#include <stdio.h>
#include <signal.h>
int main() {
    int n = 4;
    pid_t value = fork();
    printf("%d", value);
    //printf("Hello from [%d - %d - %p]\n", getpid(), n, &n);
    if (getpid() == 0) {
        printf("I'm child!");
        return 0;
    } else {
        printf("I'm parent");
        //kill(child_id, SIGKILL);
        return 0;
    }

    return 0;
}