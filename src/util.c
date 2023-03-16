//
// Created by ismail on 16/03/2023.
// source for printDateTime(): https://stackoverflow.com/questions/1442116/how-to-get-the-date-and-time-values-in-a-c-program

#include "util.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <sys/unistd.h>

void printDateTime() {
    time_t now;
    struct tm *local;
    char date_time[20];

    now = time(NULL);
    local = localtime(&now);

    strftime(date_time, sizeof(date_time), "[%d/%m %H:%M]", local);

    printf("%s", date_time);
}

int cd(char **args) {
    if (chdir(args[1]) != 0) {
        fprintf(stderr, "No such file or directory as %s\n", args[1]);
        return 1;

    } else {
        printf("Changed directory to %s\n", args[1]);
        return 0;
    }
}

void readline(char *line) {
    fflush(stdin);
    fgets(line, MAX_LINE, stdin);

    // trim newline character
    size_t len = strlen(line);
    if (len > 0 && line[len-1] == '\n') {
        line[len-1] = '\0';
    }
}

void parse_args(char **args, char *token) {
    int count = 0;
    while (token != NULL) {
        args[count] = malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(args[count], token);
        count++;
        token = strtok(NULL, " \n");
    }
    args[count] = NULL;

    for (int j = 0; j < count; ++j) {
        printf("%s ", args[j]);
    }
}

