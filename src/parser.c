#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "include/dirent.h"
#include "include/parser.h"

char *CURRENT_DIR;
static void ls(char **args, int argc);
static void echo(char **args, int argc);

int parse_command(char **cmd_arr, int argc) {
    if (strcmp(cmd_arr[0], "pwd") == 0) {
        printf("%s\n", CURRENT_DIR);
    } else if (strcmp(cmd_arr[0], "ls") == 0) {
        ls(cmd_arr, argc);
    } else if (strcmp(cmd_arr[0], "echo") == 0) {
        echo(cmd_arr, argc);
    } else if (strcmp(cmd_arr[0], "exit") == 0) {
        printf("exit dosen't consume arguments\n");
    } else {
        printf("Invalid command: %s is not recognised\n", cmd_arr[0]);
    }
    return 0;
}

void update_current_dir(char *dir) {
    CURRENT_DIR = realloc(CURRENT_DIR, sizeof(char) * 200);
    strcpy(CURRENT_DIR, dir);
}

static void ls(char **args, int argc) {
    int op_a = 0;
    int op_l = 0;
    if (argc > 2) {
        printf("ls can only accept one argument, %i arguments provided\n", argc);
        return;
    }
    if (argc == 2) {
        if (strcmp(args[1], "-a") == 0) {
            op_a = 1;
        } else if (strcmp(args[1], "-l") == 0) {
            op_l = 1;
        } else if (strcmp(args[1], "-al") == 0) {
            op_a = 1;
            op_l = 1;
        } else {
            printf("Only valid arguments for ls are -a -l and -al\n");
            return;
        }
    }
    struct dirent *d;
    DIR *dh = opendir(CURRENT_DIR);
    if (!dh) {
        if (errno = ENOENT) {
            printf("Directory doesn't exist\n");
        } else {
            printf("Directory is not redable");
        }
        return;
    }
    while ((d = readdir(dh)) != NULL) {
        if (!op_a && d->d_name[0] == '.') {
            continue;
        }
        printf("%s ", d->d_name);
        if (op_l) {
            printf("\n");
        }
    }
    if (!op_l) {
        printf("\n");
    }
}

static void echo(char **args, int argc) {
    for (int i = 1; i < argc; i++) {
        printf("%s ", args[i]);
    }
    printf("\n");
}