#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int counter = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* increment_counter(void *arg) {
    for (int i = 0; i < 1000; i++) {
        pthread_mutex_lock(&mutex);
        int temp = counter;
        temp++;
        counter = temp;
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[1000];

    for (int i = 0; i < 1000; i++) {
        pthread_create(&threads[i], NULL, increment_counter, NULL);
    }

    for (int i = 0; i < 1000; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Counter at the end: %d\n", counter);
    return 0;
}