//
// Created by ismail on 21/03/2023.
//

#include <stdio.h>
#include <unistd.h>

int main() {
    char *username;

    username = getlogin();
    if (username != NULL) {
        printf("%s\n", username);
    }

    return 0;
}