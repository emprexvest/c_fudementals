#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    int fd = open("./asdfasdf", O_RDONLY);
    if(fd == -1) {
        perror("open");
        return -1;
    }

    return 0;
}