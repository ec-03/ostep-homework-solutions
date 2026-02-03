#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
    int fd = open("test.txt", O_RDWR | O_CREAT, 0644);
    int rc = fork();
    if (rc == 0) {
        printf("Attempting to write from child\n");
        write(fd, "Hello from child\n", 17);
    }

    if (rc > 0) {
        printf("Attempting to write from parent\n");
        write(fd, "Hello from parent\n", 18);
    }

    return 0;
}

// both the child and the parent share the same file offset
// they can write to the same file, but may run into race conditions.