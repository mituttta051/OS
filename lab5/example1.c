//Write a C program that demonstrates thread creation and deletion
//using the pthread create function.
//Create two threads.
//Inside each thread’s start routine function, use printf to display a
//message containing the thread id (pthread t).
//After a brief execution, terminate the threads. Ensure that the
//program prints the messages from both
//

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void *thread1_routine(void *arg) {
    printf("Thread 1: %lu\n", pthread_self());
    pthread_exit(NULL);
}
void *thread2_routine(void *arg) {
    printf("Thread 2: %lu\n", pthread_self());
    pthread_exit(NULL);

}

int main() {
    pthread_t thread1, thread2;


    pthread_create(&thread1, NULL, thread1_routine, NULL);
    pthread_create(&thread2, NULL, thread2_routine, NULL);
    sleep(1);
    pthread_cancel(thread1);
    pthread_cancel(thread2);



    return 0;
}