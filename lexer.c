//Here is a lexer using an automata to recognize whether the token is a
//keyword of the language, an identificator, a number, etc..

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>
#include "lexer.h"

int main(void) {
    int state = 0;
    char c;

    regex_t alpha;
    regex_t num;
    regex_t alphaNum;
    regex_t sym;
    regex_t spaces;

    regcomp(&alpha, "[:alpha:]", REG_EXTENDED);
    regcomp(&num, "[:digit:]", REG_EXTENDED);
    regcomp(&alphaNum, "[:alnum:]", REG_EXTENDED);
    regcomp(&spaces, "[:space:]", REG_EXTENDED);

    while(1) {
        switch(state) {
            case 0:
                if ( c >= '0' && c <= '9' ) {
                    state = 3;
                } else if ( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ) {
                    state = 1;
                }
                //Initial step of recognition
                break;
            case 1:
                //recognition of identifiers that may either variables or reserved words
                if ( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
                    state = 1;
                }
                break;
            case 2:
                //recognition of spaces such as ' ' \n \t
                break;
            case 3:
                //recognition of integers
                if ( c >= '0' && c <= '9' ) {
                    state = 3;
                }
                break;
            default:
               printf("WTF");
        }
    }

    return 1;
}
