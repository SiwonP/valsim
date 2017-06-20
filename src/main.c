#include <stdio.h>
#include <stdlib.h>
#include "../h/lexer.h"

int main(int argc, char *argv[]) {
    FILE *file = NULL;
    char *begin = "begin";
    List *liste = initialisation();
    file = fopen(argv[1], "r");
    if (file != NULL) {
        lex(file, liste);
    }
    display_list(liste);
    return 0;
}
   
