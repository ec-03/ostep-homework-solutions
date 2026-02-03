#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    int x = 100;
    int rc = fork();
    if (rc == 0) {
        printf("child original: %d\n", x);
        x = 200;
        printf("child new: %d\n", x);
    }
    if (rc > 0) {
        int _ = wait(NULL);
        printf("parent original: %d\n", x);
        x = 300;
        printf("parent new: %d\n", x);
    }

    return 0;
}

// the variable in the child process is separate from the parent process after forking.