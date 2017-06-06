typedef struct Element Element;

struct Element{
    void *el;
    Element *next;
};

typedef struct List List;

struct List {
    Element *premier;
};


