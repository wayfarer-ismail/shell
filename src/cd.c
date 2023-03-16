//
// Created by ismail on 16/03/2023.
// no errors are raised when executed and it detects non-existant directories, but it does not change the directory.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: cd <directory_name>\n");
        return 1;

    } else if (chdir(argv[1]) != 0) {
        fprintf(stderr, "No such file or directory as %s\n", argv[1]);
        return 1;

    } else {
        printf("Changed directory to %s\n", argv[1]);
        return 0;
    }
}