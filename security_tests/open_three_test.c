#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fds[5];
    const char *filenames[5] = {
        "temp1.txt", "temp2.txt", "temp3.txt", "temp4.txt", "temp5.txt"
    };

    // Open files
    for (int i = 0; i < 5; i++) {
        fds[i] = open(filenames[i], O_CREAT | O_WRONLY | O_TRUNC, 0644);
        if (fds[i] == -1) {
            perror("open failed");
            return 1;
        }
        printf("Opened %s with fd %d\n", filenames[i], fds[i]);
    }

    // Close files and remove them
    for (int i = 0; i < 5; i++) {
        close(fds[i]);
        if (unlink(filenames[i]) == -1) {
            perror("unlink failed");
        } else {
            printf("Removed %s\n", filenames[i]);
        }
    }

    return 0;
}
