#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main() {
    pid_t pid;
    pid_t child_pids[3];

    printf("Parent Process ID: %d\n\n", getpid());

    // Create 3 child processes
    for (int i = 0; i < 3; i++) {

        pid = fork();

        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {

            printf("Child %d created (PID = %d)\n", i + 1, getpid());

            // Third child simulates an unresponsive process
            if (i == 2) {
                printf("Child %d is unresponsive...\n", i + 1);
                sleep(15);
            } else {
                sleep(2);
            }

            printf("Child %d completed.\n", i + 1);
            exit(EXIT_SUCCESS);
        }

        // Parent stores child PID
        child_pids[i] = pid;
    }

    printf("\nParent is monitoring child processes...\n");

    sleep(5);

    // Terminate the third child if still running
    printf("Terminating unresponsive child process (PID = %d)\n", child_pids[2]);
    kill(child_pids[2], SIGTERM);

    // Wait for all child processes
    for (int i = 0; i < 3; i++) {
        waitpid(child_pids[i], NULL, 0);
        printf("Child with PID %d has been cleaned up.\n", child_pids[i]);
    }

    printf("\nNo zombie processes remain.\n");

    return 0;
}
