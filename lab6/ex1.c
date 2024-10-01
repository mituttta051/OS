#include <stdio.h>
#include <signal.h>
#include <stdlib.h>


int main() {
  while(1) {
    printf("Hello World\n");
  }
  return 0;
}

// sh commands: gcc ex1.c -o ex1
// ./ex1 &> output.txt &
// kill -s SIGTERM <pid>