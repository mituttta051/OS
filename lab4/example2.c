#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("Child PID: %d\n", getpid());
        //kill(getpid(), SIGKILL);
        sleep(3);
        printf("Parent of me is pid=%d\n", getppid());
    } else {
        printf("Parent PID: %d\n", getpid());
        //sleep(3);
        wait(NULL);
        kill(getpid(), SIGKILL);
        return 0;
        printf("Parent process finished sleeping\n");
    }

    return 0;
}