#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

//Test unpermitted acces to /proc/self/mem in openat with base directory and complicated relative path

int main() {
    int fd = open("/proc/self/", O_RDONLY);
    printf("base directory fd %d\n", fd);
    printf("pid is %d \n", getpid());
    int proc_self_mem_fd = openat(fd, "../self/../../proc/self/mem", O_RDONLY);
    printf("/proc/self/mem fd %d\n", proc_self_mem_fd);
    return 0;
}