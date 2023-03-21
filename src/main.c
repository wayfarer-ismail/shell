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

int exec(char path[80], char **args, void *envp);

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

    pid_t pid = fork();
    if (pid == 0) { // child process
        char path[MAX_LINE];
        sprintf(path, "%s/%s", util_path, args[0]); // construct full path

        // execute command
        if (exec(path, args, NULL) < 0) {
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

int exec(char path[MAX_LINE], char **args, void *envp) {
    sprintf(path, "%s/%s", util_path, args[0]); // construct full path

    int fd;
    if (check_redirect(args, &fd) != 0) {
        return 1;
    }
    // execute command
    if (execve(path, args, envp) < 0) {
        fprintf(stderr, "Exec failed\n");
    }

    close(fd);
    // Reset standard output to the saved file descriptor
    if (dup2(fd, STDOUT_FILENO) == -1) {
        fprintf(stderr, "error resetting file descriptor to standard\n");
        perror("dup2");
        return 1;
    }
    return 0;
}
