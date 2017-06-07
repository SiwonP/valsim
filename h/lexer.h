int lex(FILE*);

typedef struct {
    char content[32];
    char type[16];
} token;

int save_token(char*, char*, int, token*);
