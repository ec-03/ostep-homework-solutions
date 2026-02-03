#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int rc = fork();

    if (rc == 0) {
        printf("child process\n");
        int wr = waitpid(0, NULL, 0);
        printf("wait returned: %d\n", wr);
    } else if (rc > 0) {
        int wr = waitpid(rc, NULL, 0);
        printf("parent process\npid of child was %d, wait returned: %d\n", rc, wr);
    }

    return 0;
}

// waitpid is useful to wait for a specific child process to terminate