//
// Created by ismail on 15/03/2023.
//

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    if (argc != 2) {
        fprintf(stderr, "error: usage # sleep [seconds]\n");
    } else {
        int seconds = atoi(argv[1]);
        clock_t end_time = clock() + seconds * CLOCKS_PER_SEC;
        printf("sleeping for %i seconds \n", seconds);
        while (clock() < end_time); // wait for the given amount of seconds
    }

    return 0;
}
