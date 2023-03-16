//
// Created by ismail on 16/03/2023.
// source: https://www.geeksforgeeks.org/mkdir-system-call/

#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: mkdir <directory name>\n");
        return 1;
    }

    if (mkdir(argv[1], 0) == -1) {
        printf("Error: Unable to create directory %s\n", argv[1]);
        return 1;
    }

    printf("Directory %s created successfully.\n", argv[1]);
    return 0;
}