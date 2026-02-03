#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int rc = fork();

    if (rc == 0) {
        printf("child process\n");
        int wr = wait(NULL);
        printf("wait returned: %d\n", wr);
    } else if (rc > 0) {
        int wr = wait(NULL);
        printf("parent process\npid of child was %d, wait returned: %d\n", rc, wr);
    }

    return 0;
}

// using wait in a process with no children results in an instant return of -1