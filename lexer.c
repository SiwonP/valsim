//Here is a lexer using an automata to recognize whether the token is a
//keyword of the language, an identificator, a number, etc..

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include "lexer.h"

int lex(FILE *file) {
    char tok[32] = {0};
    int pos = 0;
    int pos2 = 0;
    int state = 0;
    char c = fgetc(file);

    token toks[128] = {0};

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
                    printf("identifier : ");
                    tok[pos] = '\0';
                    pos2 = save_token(tok, "id", pos2, toks);
                    pos = 0;
                    printf("%s\n", tok);
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
                    printf("integer : ");
                    tok[pos] = '\0';
                    pos2 = save_token(tok, "int", pos2, toks);
                    pos = 0;
                    printf("%s\n", tok);
                    state = 0;
                }
                break;
            case 3:
                //recognition of + operator
                printf("op : ");
                state = 0;
                tok[pos]='\0';
                printf("%s\n", tok);
                pos = 0;
                pos2 = save_token(tok, "op", pos2, toks);
                break;
            case 4:
                //recognition of - operator
                printf("op : ");
                tok[pos] = '\0';
                pos = 0;
                printf("%s\n", tok);
                state = 0;
                pos2 = save_token(tok, "op", pos2, toks);
                break;
            case 5:
                //recognition of = operator
                printf("op : ");
                tok[pos] = '\0';
                pos = 0;
                printf("%s\n", tok);
                state = 0;
                pos2 = save_token(tok, "op", pos2, toks);
                break;
            case 6:
                //recognition of ( 
                printf("sep : ");
                tok[pos] = '\0';
                pos = 0;
                printf("%s\n", tok);
                state = 0;
                pos2 = save_token(tok, "sep", pos2, toks);
                break;
            case 7:
                //recognition of )
                printf("sep : ");
                tok[pos] = '\0';
                pos = 0;
                printf("%s\n", tok);
                state = 0;
                pos2 = save_token(tok, "sep", pos2, toks);
                break;
            case 8:
                pos = 0;
                state = 0;
                break;
            case 9:
                //recognition of float
                if ( c >= '0' && c <= '9') {
                    state = 9;
                } else {
                    printf("float : ");
                    tok[pos] = '\0';
                    pos = 0;
                    printf("%s\n", tok);
                    state = 0;
                    pos2 = save_token(tok, "float", pos2, toks);
                }
                break;
            default:
               printf("WTF\n");
               printf("state : %d\n", state);
               printf("char : %c\n", c);
        }
        //printf("%c\n",c);
    }
    
    int i = 0;
    for (i = 0; i < pos2; i++) {
        printf("[%s : %s]\n", toks[i].content, toks[i].type);
    }
    return 1;
}

int save_token(char *tok, char *type, int pos, token *toks) {
    strcpy(toks[pos].content, tok);
    strcpy(toks[pos].type, type);

    //printf("%d\n", pos);
    return pos + 1;
}
