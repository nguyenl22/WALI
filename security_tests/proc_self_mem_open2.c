#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
//Test unpermitted acces to /proc/self/mem in open with complicated path
int main() {
    int fd = open("/proc/../proc/././self/mem", O_RDONLY);
    printf("pid is %d \n", getpid());
    printf("/proc/self/mem fd %d\n", fd);
    return 0;
}