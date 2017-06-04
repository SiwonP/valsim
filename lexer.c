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
    int state = 0;
    char c = fgetc(file);

    //token 

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
                } else {
                    printf("integer : ");
                    tok[pos] = '\0';
                    pos = 0;
                    printf("%s\n", tok);
                    state = 0;
                }
                break;
            case 3:
                //recognition of + operator
                printf("+ op : ");
                state = 0;
                tok[pos]='\0';
                printf("%s\n", tok);
                pos = 0;
                break;
            case 4:
                //recognition of - operator
                printf("- op : ");
                tok[pos] = '\0';
                pos = 0;
                printf("%s\n", tok);
                state = 0;
                //c = fgetc(file);
                break;
            case 5:
                //recognition of = operator
                printf("= op : ");
                tok[pos] = '\0';
                pos = 0;
                printf("%s\n", tok);
                state = 0;
                //c = fgetc(file);
                break;
            default:
               printf("WTF");
        }
        //printf("%c\n",c);
    }
    
    return 1;
}

int save_token(void) {

    return 1;
}
