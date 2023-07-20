#ifndef LEXER_H
#define LEXER_H

// lex_string(string) consumes a string and seperates it into lexical terms and updates 
// the argument counter pointer as well
char **lex_string(char *string, int*argc);

#endif