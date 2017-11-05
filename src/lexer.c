//Here is a lexer using an automata to recognize whether the token is a
//keyword of the language, an identificator, a number, etc..

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./h/lexer.h"

int lex(FILE *file, List *liste) {
    char tok[32] = {0};
    int pos = 0;
    //int pos2 = 0;
    int state = 0;
    char c = fgetc(file);

    //token toks[128] = {0};

    while(c != EOF) {
        switch(state) {
            case 0:
                //Initial step of recognition
                if ( c >= '0' && c <= '9' ) {
                    state = 2;
                } else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                    state = 1;
                } else if ( c == '+') {
                    state = 3;
                } else if ( c == '-') {
                    state = 4;
                } else if (c == '=') {
                    state = 5;
                } else if (c == '(') {
                    state = 6;
                } else if (c == ')') {
                    state = 7;
                } else if (c == ' ' || c == '\n') {
                    state = 8;
                }
                tok[pos] = c;
                pos++;
                c = fgetc(file);
                break;
            case 1:
                //recognition of identifiers that may either variables or reserved words
                if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
                    state = 1;
                    tok[pos] = c;
                    pos++;
                    c = fgetc(file);
                } else {
                    tok[pos] = '\0';
                    save_token(tok, "id", liste);
                    pos = 0;
                    state = 0;
                }
                break;
            case 2:
                //recognition of integers
                if ( c >= '0' && c <= '9' ) {
                    state = 2;
                    tok[pos] = c;
                    pos++;
                    c = fgetc(file);
                } else if ( c == '.') {
                    state = 9;
                    tok[pos] = c;
                    pos++;
                    c = fgetc(file);
                } else {
                    tok[pos] = '\0';
                    save_token(tok, "int", liste);
                    pos = 0;
                    state = 0;
                }
                break;
            case 3:
                //recognition of + operator
                state = 0;
                tok[pos]='\0';
                pos = 0;
                save_token(tok, "op", liste);
                break;
            case 4:
                //recognition of - operator
                tok[pos] = '\0';
                pos = 0;
                state = 0;
                save_token(tok, "op", liste);
                break;
            case 5:
                //recognition of = operator
                tok[pos] = '\0';
                pos = 0;
                state = 0;
                save_token(tok, "op", liste);
                break;
            case 6:
                //recognition of ( 
                tok[pos] = '\0';
                pos = 0;
                state = 0;
                save_token(tok, "sep",  liste);
                break;
            case 7:
                //recognition of )
                tok[pos] = '\0';
                pos = 0;
                state = 0;
                save_token(tok, "sep", liste);
                break;
            case 8:
                pos = 0;
                state = 0;
                break;
            case 9:
                //recognition of float
                if ( c >= '0' && c <= '9') {
                    state = 9;
                    tok[pos] = c;
                    pos++;
                    c = fgetc(file);
                } else {
                    tok[pos] = '\0';
                    pos = 0;
                    state = 0;
                    save_token(tok, "float", liste);
                }
                break;
            default:
               printf("WTF\n");
               printf("state : %d\n", state);
               printf("char : %c\n", c);
        }
    }
    
    return 1;
}

void save_token(char *tok, char *type, List *liste) {
    token *t = (token*)malloc(sizeof(*t));
    char *copyTok = malloc(sizeof(*tok));
    char *copyType = malloc(sizeof(*type));
    strcpy(copyTok, tok);
    strcpy(copyType, type);
    t->content = copyTok;
    t->type = copyType;

    insert_at_the_end(liste, t);
}
