#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

//sandbox dir=/home/ => reject
//sandbox dir=/home/ dir=/proc => allow
//sandbox dir=/home dir=/proc dir=/tmp => allow
int main() {
    int base_fd = open("/proc/", O_RDONLY);
    int child_dir_fd = openat(base_fd, "self", O_RDONLY);
    printf("child_dir_fd fd %d\n", child_dir_fd);
    return 0;
}