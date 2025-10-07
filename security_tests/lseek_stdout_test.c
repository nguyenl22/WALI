#include <stdio.h>
#include <unistd.h>

int main() {
    printf("[lseek_stdout_test.c]: STDOUT_FILENO %d\n", STDOUT_FILENO);
    lseek(STDOUT_FILENO, 10, SEEK_SET);
    printf("[lseek_stdout_test.c]: STDERR_FILENO %d\n", STDERR_FILENO);
    lseek(STDERR_FILENO, 10, SEEK_SET);
}