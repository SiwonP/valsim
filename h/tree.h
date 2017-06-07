typedef struct Tree Tree;

struct Tree {
    void *el;
    Tree *left;
    Tree *right;
};

