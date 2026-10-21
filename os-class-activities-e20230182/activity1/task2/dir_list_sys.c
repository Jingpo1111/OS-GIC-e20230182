/* dir_list_sys.c */
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>

int main() {
    char buffer[512];

    // 1. Open current directory
    DIR *dir = opendir(".");
    if (dir == NULL) {
        return 1;
    }

    // 2. Print header using write()
    char header[] = "Filename                            Size (bytes)\n";
    write(1, header, strlen(header));

    // 3. Loop through directory entries
    struct dirent *entry;
    struct stat fileStat;

    while ((entry = readdir(dir)) != NULL) {
        // 4. Get file information
        if (stat(entry->d_name, &fileStat) == 0) {
            // 5. Format and print using write()
            int len = snprintf(
                buffer,
                sizeof(buffer),
                "%-30s %10ld\n",
                entry->d_name,
                (long)fileStat.st_size
            );

            if (len > 0 && len < sizeof(buffer)) {
                write(1, buffer, len);
            }
        }
    }

    // 6. Close directory
    closedir(dir);

    return 0;
}
