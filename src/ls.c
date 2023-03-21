//
// Created by ismail on 15/03/2023.
// Looked at the source code for ls and copied the base functionality.

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(void) {
    DIR *dir;
    struct dirent *entry;

    dir = opendir(".");

    if (dir == NULL) { // error opening directory
        fprintf(stderr, "Error opening directory\n");
        return 1;
    }

    while ((entry = readdir(dir)) != NULL) { // print directory contents
        printf("%s ", entry->d_name);
    }
    printf("\n");

    closedir(dir);
    return 0;
}
