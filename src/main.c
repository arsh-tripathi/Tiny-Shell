#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "include/lexer.h"

int main(void) {
    printf("\e[1;1H\e[2J");
    printf("=============================================\n");
    printf("================= My Shell ==================\n");
    printf("=============================================\n");

    while (true) {
        char *command = malloc(sizeof(char)*100);
        int *argc = malloc(sizeof(int));
        *argc = 0;
        printf("> ");
        int retval = scanf(" %[^\n]s", command);
        if (retval == 0) {
            break;
        }
        char **command_arr = lex_string(command, argc);
        // for (int i = 0; i < *argc; i++) {
        //     if (i == 0) {
        //         printf("This is the main command: %s\n The arguments are as follows:\n", command_arr[i]);
        //     } else {
        //         printf("%s\n", command_arr[i]);
        //     }
        // }
        if (strcmp(command, "exit") == 0) {
            printf("Exiting.....");
            break;
        }
        
        free(command);
        free(argc);
        free(command_arr);
        // printf("%s\n",command);
    }
}