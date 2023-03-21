/*
    I have implemented the head utility, it accepts even/odd option and a specified amount of lines to print.
    All the options work correctly but I have not implemented a feature of head where if a negative number is passed for n
        the head funtion prints until EOF-n lines, instead my implementation just prints the whole file when given a negative n
    The programme acts like the default head function when a file is not specifed and reads from standard in instead,
        I tested it by piping an the output of grep into it and it worked as expected.

*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void parityerror();
void printversion();
void printhelp();

int main(int argc, char *argv[]) {

    int use_odd = 0, use_even = 0, num_lines = 10, opt;

    while ( ( opt = getopt(argc, argv, "n:Vheo" ) ) != -1) {
        switch (opt) {
            case 'n':
                num_lines = atoi(optarg);
                break;
            case 'V':
                printversion();
                exit(EXIT_SUCCESS);
                break;
            case 'h':
                printhelp();
                exit(EXIT_SUCCESS);
                break;
            case 'e':
                if (use_odd) {parityerror();}
                use_even = 1;
                break;
            case 'o':
                if (use_even) {parityerror();}
                use_odd = 1;
                break;
            default:
                fprintf(stderr, "unknown commands, try : %s -h\n", argv[ 0 ]);
                exit(EXIT_FAILURE);
        }
    }


    FILE *fp;
    char *filename = NULL;

    if (argc > optind) {
        filename = argv[optind];
    }

    if (filename == NULL) {
        fp = stdin;
    } else {
        fp = fopen (filename, "r");
        if (fp == NULL) {
            fprintf(stderr, "Error: Cannot open file '%s'\n", filename);
            exit(EXIT_FAILURE);
        }

    }


    int i = 1, printed_lines =0;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, fp)) != -1) {
        if (num_lines > 0 && printed_lines == num_lines) break;


        if (use_odd == 1 && i %2 == 1 ||
            use_even == 1 && i %2 == 0 ||
            use_even == 0 && use_odd == 0) {

            printf("%s", line); printed_lines++;
        }
        i++;
    }

    fclose(fp);
    free(line);
    exit(EXIT_SUCCESS);

}

void printversion() {
    printf("version No.: v2.3 \nname: Ismail \nemail: ismailelbahja03@gmail.com \nstudent number: 21344991 \n");
}

void parityerror() {
    fprintf(stderr, "Can't choose both even and odd, must choose one or neither \n");
    exit(EXIT_FAILURE);
}

void printhelp() {
    printf("%s \n%s \n%s \n%s \n", "-n K output the first K lines",
           "-V Output version info: Your name, email, and student number.",
           "-h display all options ( something like this text describing the options ) and exit the application",
           "-e|-o print even|odd lines.");
}