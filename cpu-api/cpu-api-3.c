#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int p[2]; //pipe

    if (pipe(p) < 0) return 1;

    int rc = fork();

    if (rc == 0) {
        printf("hello\n");
        write(p[1], "1", 1);
    } else if (rc > 0) {
        char buffer;
        read(p[0], &buffer, 1);
        printf("goodbye\n");
    }

    return 0;
}

// we may use a pipe to signal from one process to another