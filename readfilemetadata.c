#include <stdio.h>
#include <stdlib.h>
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
    struct stat dbStat = {0};

    if(argc != 2) {
        printf("Useage %s <filename>\n", argv[0]);
        return 0;
    }

    int fd = open(argv[1], O_RDWR | O_RDONLY, 0644);
    if(fd == -1) {
        perror("open");
        return -1;
    }

    if(read(fd, &head, sizeof(head)) != sizeof(head)){
        perror("read");
        close(fd);
        return -1;
    }

    printf("DB Version: %hu\n", head.version);
    printf("DB Number of Employees: %hu\n", head.employees);
    printf("DB Filesize: %u\n", head.filesize);

    if(fstat(fd, &dbStat) < 0){
        perror("fstat");
        close(fd);
        return -1;
    };

    printf("DB File Length reported, reported by fstat: %lu\n", dbStat.st_size);

    if(dbStat.st_size != head.filesize) {
        printf("File size mismatch: possible hacker\n");
        close(fd);
        return -1;
    }

    close(fd);
    return 0;
}