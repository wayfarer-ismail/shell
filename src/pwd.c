//
// Created by ismail on 15/03/2023.
// Uses getcwd to print current working directory,
// source: https://stackoverflow.com/questions/298510/how-to-get-the-current-directory-in-a-c-program

#include <stdio.h>
#include <unistd.h>

int main() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working directory: %s\n", cwd);
        return 0;
    } else {
        fprintf(stderr, "error: Can't print working directory\n");
        return -1;
    }
}
