#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>

/*
ssize_t write(int fd, const void buf[.count], size_t count);
*/

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage of our program: %s <filename>\n", argv[0]);
        return 0;
    }
    int fd = open(argv[1], O_RDWR | O_CREAT, 0644);
    if(fd == -1) {
        perror("open");
        return -1;
    }

    char *mydata = "Hello there file!\n";
    write(fd, mydata, strlen(mydata));
    close(fd);

    return 0;
}