#define ALPHA "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUM "0123456789"

int type_of(char);

int lex(char*);

typedef struct {
    char *content;
    char *type;
} token;
