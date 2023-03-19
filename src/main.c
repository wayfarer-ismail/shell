//
// Created by ismail on 14/03/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include "util.h"

extern char **environ;
char util_path[MAX_LINE];

int shell();

int main(void)
{
    int status = 0; // status of child process

    sprintf(util_path, "%s", getcwd(NULL, 0)); // construct path to where commands are stored

    while (status == 0) {
        status = shell();
        //printf("Status %i\n", status);
    }

    printf("bye\n");
    return 0;
}

int shell() {
    printDateTime();
    printf("# ");
    fflush(stdout);

    signal(SIGINT, sig_handler); // watch for ctrl-c

    // read commands from stdin
    char line[MAX_LINE];
    readline(line);

    // parse input
    char **args = malloc(sizeof(char *));
    char *token = strtok(line, " \n");
    parse_args(args, token);


    // exit shell if user enters "exit"
    if (strcmp(args[0], "exit") == 0) {
        free(args);
        return -1;
    } else if (strcmp(args[0], "cd") == 0) {
        cd(args);
        free(args);
        return 0;
    }

    // set default directory to /home/user/my_program
    chdir("/home/user/my_program");
    pid_t pid = fork();
    if (pid == 0) { // child process
        char path[MAX_LINE];
        sprintf(path, "%s/%s", util_path, args[0]); // construct full path
        // execute command
        if (execve(path, args, NULL) < 0) {
            fprintf(stderr, "Exec failed\n");
        }

    } else if (pid > 0) { // parent process
        signal(SIGINT, sig_handler); // watch for ctrl-c
        int status;
        waitpid(pid, &status, 0); // wait for child process to finish
        signal(SIGINT, SIG_DFL); //restore default behaviour
    } else {
        return -1; //if fork fails then stop programme
    }

    return 0;
}