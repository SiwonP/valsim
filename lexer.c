//Here is a lexer using an automata to recognize whether the token is a
//keyword of the language, an identificator, a number, etc..

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h"

int lex(char *str) {
    int state = 0;
    char c;
    token res;
    
    int pos = 0;
    c = str[pos];
    int b;

    while(str[pos] != NULL ) {
        switch(state) {
            case 0:
                switch(type_of(c)) {
                    pos++;
                    c = str[pos];
                    case 0: state = 2; break;
                    case 1: state = 1; break;
                    default: printf("error");
                }
                break;
            case 1:
                if (type_of(c) == 1) {
                    state = 1;
                }
                pos++;
                c = str[pos];
                break;
            case 2:
                if (type_of(c) == 0 || type_of(c) == 1) {
                    state = 2;
                }
                pos ++;
                c = str[pos];
                break;
            default: 
                printf("error2");
        }

        printf("%d", state);
    }

    return 1;
}

int type_of(char c) {
    char *b;
    b = strchr(ALPHA, c);
    if ( b != NULL ) {
        return 0;
    } else {
        b = strchr(NUM, c);
        if ( b != NULL ) {
            return 1;
        } else {
            return 2;
        }
    }
}

int main(void) {

    int res;
    char *test = "print";
    res = lex(test);

    return 1;
}
