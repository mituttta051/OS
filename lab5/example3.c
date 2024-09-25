#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int counter = 0;

void* increment_counter(void *arg) {
    int temp = counter;
    temp++;
    counter = temp;
    printf("Counter: %d\n", counter);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, increment_counter, NULL);
    pthread_create(&thread2, NULL, increment_counter, NULL);
    sleep(1);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Counter at the end: %d\n", counter);
}