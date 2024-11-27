#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#include "file.h"
#include "common.h"
#include "parse.h"

void list_employees(struct dbheader_t *dbhdr, struct employee_t *employees) {

}

int add_employee(struct dbheader_t *dbhdr, struct employee_t *employees, char *addstring) {

}

int read_employees(int fd, struct dbheader_t *dbhdr, struct employee_t **employeesOut) {

}

// Might refactor this back into the project
// int output_file(int fd, struct dbheader_t *dbhdr, struct employee_t *employees) {

// }	

void output_file(int fd, struct dbheader_t *dbhdr) {
    if(fd < 0) {
        printf("Got a bad FD from the user\n");
        return STATUS_ERROR;
    }

    dbhdr->magic = htonl(dbhdr->magic);
    dbhdr->filesize = htonl(dbhdr->filesize);
    dbhdr->count = htons(dbhdr->count);
    dbhdr->version = htons(dbhdr->version);

    printf("Middle of output_file function FD:%d\n", fd);
    
    lseek(fd, 0, SEEK_SET);

    write(fd, dbhdr, sizeof(struct dbheader_t));

    // Remove if non-conditional implementation is working
    // if(lseek(fd, 0, SEEK_SET) == -1) {
    //     perror("lseek");
    //     return STATUS_ERROR;
    // };

    // if(write(fd, dbhdr, sizeof(struct dbheader_t)) != sizeof(struct dbheader_t)) {
    //     perror("write");
    //     return STATUS_ERROR;
    // }

    // if(write(fd, dbhdr, sizeof(struct dbheader_t) != sizeof(struct dbheader_t))) {
    //     perror("write");
    //     return STATUS_ERROR;
    // }

    // printf("Output from Out_file function:\n");
    // printf("Magic number output:0X%08x\n", dbhdr->magic);
    // printf("Version count 0X%08x\n", dbhdr->version);

    // return STATUS_SUCCESS;
    return;
}	

int validate_db_header(int fd, struct dbheader_t **headerOut) {
    if(fd < 0) {
        printf("Got a bad FD from the user\n");
        return STATUS_ERROR;
    }

    struct dbheader_t *header = calloc(1, sizeof(struct dbheader_t));
    if(header == NULL) {
        printf("Malloc failed to return database header\n");
        return STATUS_ERROR;
    }

    if(read(fd, header, sizeof(struct dbheader_t)) != sizeof(struct dbheader_t)) {
        printf("validate_db_header struct size%zu\n", sizeof(struct dbheader_t));
        perror("read");
        free(header);
        return STATUS_ERROR;
    }

    header->magic = ntohl(header->magic);
    header->filesize = ntohl(header->filesize);
    header->version = ntohs(header->version);
    header->count = ntohs(header->count);

    if(header->magic != HEADER_MAGIC) {
        printf("Improper header magic\n");
        free(header);
        return -1;
    }

    if(header->version != 1) {
        printf("Improper header version\n");
        free(header);
        return -1;
    }

    struct stat dbstat = {0};
    fstat(fd, &dbstat);
    if(header->filesize != dbstat.st_size) {
        printf("Corrupted database\n");
        free(header);
        return -1;
    }

    *headerOut = header;

    // Not in original source code
    return STATUS_SUCCESS;
}

int create_db_header(int fd, struct dbheader_t **headerOut) {
    struct dbheader_t *header = calloc(1, sizeof(struct dbheader_t));
    if(header == NULL) {
        printf("Malloc failed to print dbheader\n");
        return STATUS_ERROR;
    }

    printf("Middle of create_db_header:%d\n", fd);

    header->version = 0x1;
    header->count = 0;
    header->magic = HEADER_MAGIC;
    header->filesize = sizeof(struct dbheader_t);

    *headerOut = header;

    if (lseek(fd, 0, SEEK_SET) == -1) {
        perror("lseek");
        free(header);
        return STATUS_ERROR;
    }

    if (write(fd, header, sizeof(struct dbheader_t)) != sizeof(struct dbheader_t)) {
        perror("write");
        free(header);
        return STATUS_ERROR;
    }

    printf("Create db_header structure values:\n");
    printf("Version:%d\n", header->version);
    printf("Count:%d\n", header->count);
    printf("Magic Number:0X%0x\n",header->magic);
    printf("Filesize:%d\n", header->filesize);

    printf("Create db header function completed successfully %d\n", STATUS_SUCCESS);
    return STATUS_SUCCESS;
}


