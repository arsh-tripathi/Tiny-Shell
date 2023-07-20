#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "include/lexer.h"

char **lex_string(char *s, int* argc) {
    char **string_arr = malloc(sizeof(char *) * 100);
    int length = strlen(s);
    int j = 0;
    int k = 0;
    string_arr[0] = malloc(sizeof(char) * 100);
    bool was_whitespace = false;
    for (int i = 0; i < length; i++) {
        if ((33 <= s[i]) && (s[i] <= 126)) {
            if (was_whitespace) {
                string_arr[j][k] = '\0';
                k = 0;
                j++;
                string_arr[j] = malloc(sizeof(char)*100);
            }
            string_arr[j][k] = s[i];
            k++;
            was_whitespace = false;
        } else {
            was_whitespace = true;
        }
    }
    string_arr[j][k] = '\0';
    *argc = j + 1;
    return string_arr;
}