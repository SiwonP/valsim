#include "list.h"

int lex(FILE*, List*);

typedef struct {
    char *content;
    char *type;
} token;

int save_token(char*, char*, int, List*);
