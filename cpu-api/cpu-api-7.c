#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int rc = fork();

    if (rc == 0) {
        printf("printf in child class, before closing\n");
        close(STDOUT_FILENO);
        printf("printf in child class, after closing\n");
    } else if (rc > 0) {
        wait(NULL);
        printf("printf in parent class\n");
    }

    return 0;
}

// closing the standard output file is local to the child process