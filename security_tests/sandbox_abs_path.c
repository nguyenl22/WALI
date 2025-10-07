#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

//sandbox dir=/proc/

int main() {
    int absolute_fd = openat(0, "/proc/", O_RDONLY);
    printf("absolute_fd fd %d\n", absolute_fd);
    return 0;
}