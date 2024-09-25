//write a program channel.c which runs two processes (publisher
//and subscriber) and one (unnamed) pipe between them.
//The publisher process reads a message from stdin and sends it to
//the subscriber who prints the message to stdout.
//The maximum size of a single message is 1024 bytes.

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("Failed to create pipe");
        return 1;
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("Failed to fork");
        return 1;
    }

    if (pid == 0) {
      // subscriber
      char buffer[1024];
      close(pipefd[1]);
      long nbytes = read(pipefd[0], buffer, 1024);
      printf("Received message: %s", buffer);
        close(pipefd[0]);
    } else {
      // publisher
      char buffer[1024];
      close(pipefd[0]);
      printf("Enter a message: ");
      fgets(buffer, 1024, stdin);
      write(pipefd[1], buffer, 1024);
      close(pipefd[1]);
    }
}