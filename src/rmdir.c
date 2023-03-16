//
// Created by ismail on 16/03/2023.
//

#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: rmdir <directory name>\n");
        return 1;
    }

    if (rmdir(argv[1]) != 0) {
        fprintf(stderr, "Error: unable to directory %s\n", argv[1]);
        return 1;
    }

    printf("Directory %s removed successfully\n", argv[1]);
    return 0;
}
