#include <stdio.h>
#include <fcntl.h>   // For open()
#include <unistd.h>  // For dup2(), close()

int main() {
    // Step 1: Open a file to redirect stdout to it
    int file_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file_fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Step 2: Use dup2 to redirect stdout to the file
    if (dup2(file_fd, STDOUT_FILENO) == -1) {
        perror("Error with dup2");
        close(file_fd);
        return 1;
    }

    // Step 3: Print a message, which will now be written to the file
    printf("This output will be redirected to the file 'output.txt'\n");

    // Step 4: Close the file descriptor
    close(file_fd);

    return 0;
}
