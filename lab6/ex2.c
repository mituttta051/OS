#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void handle_sigalrm(int s) {
    printf("Child %d received SIGALRM\n", getpid());
    exit(0);

}

int main() {
    pid_t pid = fork();

    if (pid == 0) {
      signal(SIGALRM, handle_sigalrm);
      alarm(3);
      while (1) {
        printf("Hello, World!\n");
        sleep(1);
      }
    } else {
      wait(NULL);
    }
}
