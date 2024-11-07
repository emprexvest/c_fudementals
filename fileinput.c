#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

struct database_header_t {
    unsigned short version;
    unsigned short employees;
    unsigned int filesize;
};

int main(int argc, char *argv[]) {
    
    struct database_header_t head = {0};

    if(argc != 2) {
        printf("Useage: %s <filename>\n", argv[0]);
        return 0;
    }

    int fd = open(argv[1], O_RDWR | O_RDONLY, 0644);
    if(fd == -1) {
        perror("open");
        return -1;
    }

    if(read(fd, &head, sizeof(head)) != sizeof(head)) {
        perror("read");
        close(fd);
        return -1;
    }

    printf("DB Version: %hu\n", head.version);
    printf("DB Number of Employees: %hu\n", head.employees);
    printf("DB File Length: %u\n", head.filesize);


    close(fd);
    return 0;
}