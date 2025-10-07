#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 4096

int main() {
    char buffer1[BUFFER_SIZE];
    memset(buffer1, 0, BUFFER_SIZE);
    char buffer2[BUFFER_SIZE];
    memset(buffer2, 0, BUFFER_SIZE);

    int fd = open("temp1.txt", O_CREAT | O_WRONLY | O_TRUNC);
    if (fd == -1) {
        return -1;
    }

    /* Should success */
    ssize_t num_bytes = write(fd, buffer1, 2);
    if (num_bytes == -1) {
        printf("First write failed \n");
        return -1;
    }

    /*  Should fail */
    num_bytes = write(fd, buffer2, BUFFER_SIZE);
    if (num_bytes == -1) {
        printf("Second write failed \n");
        return -1;
    }

    close(fd);
    remove("temp1.txt");
    return 0;
}