//
// Created by ismail on 16/03/2023.
// source for printDateTime(): https://stackoverflow.com/questions/1442116/how-to-get-the-date-and-time-values-in-a-c-program

#include "util.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
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
    char *path;
    if (args[1] == NULL) {
        path = getenv("HOME");
    } else {
        path = args[1];
    }

    if (chdir(path) != 0) {
        fprintf(stderr, "No such file or directory as %s\n", args[1]);
        return 1;
    } else {
        printf("Changed directory to %s\n", path);
    }

    char cwd[MAX_LINE];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working directory: %s\n", cwd); // print current working directory
    } else {
        perror("getcwd() error");
    }

    // Add the updated directory to the PATH
    setenv("PATH", cwd, 1);

    return 0;
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


int check_redirect(char **args, int *Pfd) {
    // Look for output redirection
    char* filename = NULL;
    for (int i = 0; args[i] != NULL; i++) {
        if (strcmp(args[i], ">") == 0) {
            if (args[i+1] != NULL) {
                filename = args[i+1];
            }
            args[i] = NULL;
            break;
        }
    }

    if (filename == NULL) { // no output redirection
        return 0;
    }

    // Open the file
    *Pfd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (*Pfd == -1) {
        fprintf(stderr, "error opening file to redirect standard output\n");
        perror("open");
        return 1;
    }

    // Redirect standard output to the file
    if (dup2(*Pfd, 1) == -1) {
        perror("dup2");
        return 1;
    }

    return 0;
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
}

void sig_handler(int signo) {
    if (signo == SIGINT) {
        printf("\n");
        printDateTime();
        printf("# ^C\n");
        printDateTime();
        printf("# ");

        fflush(stdout);
    }
}

