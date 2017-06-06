#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"

int main(int argc, char *argv[]) {
    FILE *file = NULL;
    file = fopen(argv[1], "r");
    if (file != NULL) {
        lex(file);
    }
    return 0;
}
   
