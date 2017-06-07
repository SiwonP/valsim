typedef struct Element Element;

struct Element{
    void *el;
    Element *next;
};

typedef struct List List;

struct List {
    Element *premier;
};

List *initialisation(void*);

void insert_at_the_end(List*, void*);

void display_list(List*, void(*f)(void*));
