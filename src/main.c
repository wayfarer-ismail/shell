//
// Created by ismail on 14/03/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LINE 80 // maximum length of a command
extern char **environ;

int shell();

void readline(char *line);

void parse_args(char **args, char *token);

int main(void)
{
    int status = 1; // status of child process

    while (status == 1) {
        status = shell();
        printf("Status %i\n", status);
    }

    printf("bye\n");
    return 0;
}

int shell() {
    printf("# ");
    fflush(stdout);

    // read commands from stdin
    char line[MAX_LINE];
    readline(line);

    // parse input
    char **args = malloc(sizeof(char *));
    char *token = strtok(line, " ");
    parse_args(args, token);


    // exit shell if user enters "exit"
    if (strcmp(args[0], "exit") == 0) {
        free(args);
        return -1;
    }

    pid_t pid = fork();
    if (pid == 0) { // child process
        if (execve(args[0], args, NULL) < 0) { // execute command
            fprintf(stderr, "Exec failed\n");
        }
    } else if (pid > 0) { // parent process
        int status;
        waitpid(pid, &status, 0); // wait for child process to finish
    } else {
        return -1; //if fork fails then stop programme
    }

    return 1;
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