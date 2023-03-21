//
// Created by ismail on 21/03/2023.
//

#include <stdio.h>

int main(int argc, char *argv[]) {
    int i;

    // simply print all arguments
    for (i = 1; i < argc; i++) {
        printf("%s ", argv[i]);
    }
    printf("\n");

    return 0;
}