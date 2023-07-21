#ifndef PARSER_H
#define PARSER_H

// parse_command consumes a string array, parses and exectues the command, and returns the exit status
int parse_command(char **cmd_arr, int argc);

// Updates the current dir the shell is in
void update_current_dir(char *dir);

#endif