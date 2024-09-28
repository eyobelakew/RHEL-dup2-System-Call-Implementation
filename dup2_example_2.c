#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    // Open input and output files
    int input_fd = open("input.txt", O_RDONLY);
    if (input_fd == -1) {
        perror("Error opening input file");
        return 1;
    }

    int output_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (output_fd == -1) {
        perror("Error opening output file");
        close(input_fd);
        return 1;
    }

    // Redirect stdin to input.txt
    if (dup2(input_fd, STDIN_FILENO) == -1) {
        perror("Error redirecting stdin");
        close(input_fd);
        close(output_fd);
        return 1;
    }

    // Redirect stdout to output.txt
    if (dup2(output_fd, STDOUT_FILENO) == -1) {
        perror("Error redirecting stdout");
        close(input_fd);
        close(output_fd);
        return 1;
    }

    // Read from stdin (input.txt) and write to stdout (output.txt)
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), stdin)) {
        printf("%s", buffer);  // This will write to output.txt
    }

    // Close file descriptors
    close(input_fd);
    close(output_fd);

    return 0;
}
