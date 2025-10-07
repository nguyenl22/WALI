#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

//--dir=/home --dir=/proc => permit
//--dir=/home --dir=tmp => not permit
int main() {
    int fd = open("/proc/../proc/././self", O_RDONLY);
    printf("fd is %d\n", fd);
}