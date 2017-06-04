#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main(int argc, char *argv[]) {
    FILE *file = NULL;
    file = fopen(argv[1], "r");
    char **tokens;
    if (file != NULL) {
        char content[128];
        fgets(content, sizeof(content), file);
        printf("%s", content);
        tokens = tokenize(content);
        int position = 0;
        while(tokens[position] != NULL) {
            printf("%s\n", tokens[position]);
            position++;
        }
    }
    return 0;
}
   
