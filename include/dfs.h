#include <stdbool.h>		/* bool, true, false */

typedef struct Bnode
{
  int num;
  bool visited;
  struct Bnode *lchild;
  struct Bnode *rchild;
} Bnode;


Bnode *make_node (int num, Bnode * left, Bnode * right);


//void print_node (node * p);

//void print_tree (node * p, int depth);

void DFT (Bnode* root);

typedef struct node
{
  Bnode* data;
  struct node *next;
} node;


typedef struct stack {
  node* top;
}stack;

Bnode *pop (stack* s);

void push (stack * topp, Bnode * node);

bool isEmpty (stack * topp);

//node *top (stack * topp);

Bnode *pop (stack * topp);

//void print_stack (stack * topp);

