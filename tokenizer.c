#include <string.h>
#include <stdlib.h>
#include "tokenizer.h"

char **tokenize(char *input) {
    char *ch = " " ;
    char *token = NULL;
    char **tokens = malloc(64 * sizeof(char*));
    char position = 0;

    token = strtok(input, ch);

    while (token != NULL) {
        tokens[position] = token;
        token = strtok(NULL, ch);
        position++;
    }

    tokens[position] = NULL;

    return tokens;
}
