#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void handle_sigusr1(int sig) {
    printf("Error: Input starts with a '-' indicating a negative number.\n");
    exit(1);
}

void handle_sigusr2(int sig) {
    printf("Error: Input is not a valid number.\n");
    exit(1);
}

int main() {
    char input[100];
    printf("Enter a positive integer: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character if present
    input[strcspn(input, "\n")] = 0;

    // Set up signal handlers
    signal(SIGUSR1, handle_sigusr1);
    signal(SIGUSR2, handle_sigusr2);

    // Check if input starts with '-'
    if (input[0] == '-') {
        raise(SIGUSR1);
    }

    // Check if input is a valid number
    for (int i = 0; i < strlen(input); i++) {
        if (!isdigit(input[i])) {
            raise(SIGUSR2);
        }
    }

    printf("You entered a valid positive integer: %s\n", input);
    return 0;
}