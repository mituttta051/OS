#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>


int main() {
  char s[1024];
  printf("Enter number of subscribers\n");
  fgets(s, 1024, stdin);
  int n = atoi(s);
  pid_t pid;
  char* publisher_fifo = "/tmp/ex1";
  for (int i = 0; i < n; i++) {
    pid = fork();
  }

  if (pid == 0) {
    mkfifo(publisher_fifo, 0666);
  } else {
    char buffer[1024];
    printf("Enter message: \n");
    fgets(buffer, 1024, stdin);
  }


}