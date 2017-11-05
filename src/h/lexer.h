#ifndef LEXER_H
#define LEXER_H

#include "list.h"

int lex(FILE*, List*);

void save_token(char*, char*, List*);

#endif
