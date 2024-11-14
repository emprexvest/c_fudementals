#include <stdio.h>
#include <stdbool.h>
#include <getopt.h>
#include <stdlib.h>
#include <stdbool.h>

// #include "common.h"
// #include "file.h"
// #include "parse.h"

void print_usage(char *argv[]) {
    printf("Usage: %s -n -f <database file>\n", argv[0]);
    printf("\t -n - create new databsse file\n");
    printf("\t -f - (required) database file \n");
    
    return;
}

int main(int argc, char *argv[]) { 
	char *filepath = NULL;
    bool newfile = false;
    int c;

    while((c = getopt(argc, argv, "nf:")) != -1) {
        switch(c) {
            case 'n':
                newfile = true;
                break;
            case 'f':
                filepath = optarg;
                break;
            case '?':
                printf("Unknown option -%c\n",c);
                break;
            default:
                return -1;
        }
    }

    if(filepath == NULL) {
        printf("Filepath is a required argument\n");
        print_usage(argv);
    }

    printf("Newfile: %d\n", newfile);
    printf("Filepath: %s\n", filepath);

    return 0;
}