#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int p[2];

    if (pipe(p) < 0) return 1;

    int rc = fork();

    if (rc == 0) {
        dup2(p[1], STDOUT_FILENO);
        close(p[0]);
        printf("world");
    } else if (rc > 0) {
        dup2(p[0], STDIN_FILENO);
        close(p[1]);
        char subject[6];
        read(STDIN_FILENO, subject, 6);
        subject[5] = '\0';
        printf("hello, %s!\n", subject);
    }

    return 0;
}