#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "include/lexer.h"
#include "include/parser.h"

int main(int argc, char *argv[]) {
    printf("\e[1;1H\e[2J");
    printf("=============================================\n");
    printf("================= My Shell ==================\n");
    printf("=============================================\n");

    if (argc > 2) {
        printf("Usage: ./shell.exe home_dir_path(C:\\Users if not specified)\n");
    } else if (argc == 2) {
        update_current_dir(argv[1]);  
    } else {
        update_current_dir("C:\\Users");
    }

    while (true) {
        char *command = malloc(sizeof(char)*100);
        int *argc = malloc(sizeof(int));
        *argc = 0;
        printf("> ");
        int retval = scanf(" %[^\n]s", command);
        if (retval == 0) {
            break;
        }

        // Handle the exit command
        if (strcmp(command, "exit") == 0) {
            printf("Exiting.....");
            break;
        }
        
        // lex and parse the command
        char **command_arr = lex_string(command, argc);
        int return_code = parse_command(command_arr, *argc);

        // free allocated memory
        free(command);
        free(argc);
        free(command_arr);
    }
}