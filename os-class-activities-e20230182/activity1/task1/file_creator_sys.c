/* file_creator_sys.c */
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    // 1. Open or create the file
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    // 2. Write text to the file
    char text[] = "Hello from Operating Systems class!\n";
    write(fd, text, strlen(text));

    // 3. Close the file
    close(fd);

    // 4. Print confirmation to the terminal
    char msg[] = "File created successfully!\n";
    write(1, msg, strlen(msg));

    return 0;
}
