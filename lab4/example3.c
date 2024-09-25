#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#define VECTOR_SIZE 120

int main() {
    int u[VECTOR_SIZE];
    int v[VECTOR_SIZE];
    for (int i = 0; i < VECTOR_SIZE; i++) {
        u[i] = rand() % 100;
        v[i] = rand() % 100;
    }

    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int segment_size = VECTOR_SIZE / n;
    pid_t pids[n];

    FILE *pFile = fopen("temp.txt", "w+");
    if (pFile == NULL) {
        perror("Failed to open file");
        return 1;
    }
    fclose(pFile);

    for (int i = 0; i < n; i++) {
        pids[i] = fork();
        if (pids[i] == 0) {
            int temp = 0;
            for (int j = i * segment_size; j < (i + 1) * segment_size; j++) {
                temp += u[j] * v[j];
            }

            pFile = fopen("temp.txt", "a");
            if (pFile != NULL) {
                fprintf(pFile, "%d\n", temp);
                fclose(pFile);
            } else {
                perror("Failed to open file in child process");
            }
            exit(0);
        }
    }

    // Wait for all child processes to finish
    for (int i = 0; i < n; i++) {
        waitpid(pids[i], NULL, 0);
    }

    // Main process aggregates the results
    pFile = fopen("temp.txt", "r");
    if (pFile == NULL) {
        perror("Failed to open file for reading");
        return 1;
    }

    int final_result = 0;
    int temp;
    while (fscanf(pFile, "%d", &temp) != EOF) {
        final_result += temp;
    }
    fclose(pFile);

    printf("Final dot product result: %d\n", final_result);

    return 0;
}