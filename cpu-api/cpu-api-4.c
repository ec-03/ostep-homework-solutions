#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int rc = fork();

    if (rc == 0) {
        printf("child process about to run ls\n");
        execl("/bin/ls", "ls", "-la", NULL);
        printf("shouldn't be reached\n");
    } else if (rc > 0) {
        printf("parent process\n");
    }
    
    return 0;
}