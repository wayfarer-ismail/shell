//
// Created by ismail on 14/03/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* The maximum length command */
extern char **environ;

int shell();

int main(void)
{
    int status = 1; /* status of child process */

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
    fgets(line, sizeof(line), stdin);

    // parse input
    char **args = malloc(sizeof(char *));
    char *token = strtok(line, " ");
    int count = 0;
    while (token != NULL) {
        args[count++] = token;
        args = realloc(args, (count + 1) * sizeof(char *));
        token = strtok(NULL, " ");
    }
    args[count] = NULL;

    for (int j = 0; j < count; ++j) {
        printf("%s ", args[j]);
    }


    // exit shell if user enters "exit"
    if (strcmp(args[0], "exit") == 0) {
        return -1;
    }

    pid_t pid = fork();
    if (pid == 0) { // child process
        if (execve(args[0], args, environ) < 0) { // execute command
            fprintf(stderr, "Exec failed\n");
            return 1;
        }
    } else if (pid > 0) { // parent process
        int status;
        waitpid(pid, &status, 0); /* wait for child process to finish */
    } else {
        return 0;
    }

    return 1;
}

