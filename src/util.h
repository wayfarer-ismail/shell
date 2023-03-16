//
// Created by ismai on 16/03/2023.
//

#ifndef ASSIGNMENT2_UTIL_H
#define ASSIGNMENT2_UTIL_H

#endif //ASSIGNMENT2_UTIL_H

#include <stdio.h>
#include <time.h>

#define MAX_LINE 80 // maximum length of a command
void printDateTime();

int cd(char **args);

void readline(char *line);

void parse_args(char **args, char *token);
