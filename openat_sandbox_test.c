#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Open the base directory
    int dir_fd = open("/ltn/temp/", O_RDONLY);
    if (dir_fd == -1) {
        perror("Failed to open base directory");
        return 1;
    }
    printf("Base directory opened successfully (FD: %d)\n", dir_fd);

    // Use openat() to open "frog" relative to the base directory
    int file_fd = openat(dir_fd, "frog", O_RDONLY);
    if (file_fd == -1) {
        perror("Failed to open 'frog' relative to base directory");
        close(dir_fd); // Close the directory descriptor before exiting
        return 1;
    }
    printf("File 'frog' opened successfully (FD: %d)\n", file_fd);

    // Perform operations on the file (if necessary)

    // Close the file and directory descriptors
    close(file_fd);
    close(dir_fd);

    return 0;
}
