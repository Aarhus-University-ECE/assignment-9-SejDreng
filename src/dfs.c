/*
 * Search an expression using DFS.
 */

#include <stdio.h>		/* scanf, printf */
#include <stdlib.h>		/* abort */
#include <stdbool.h>		/* bool, true, false */
#include "dfs.h"



void DFT (Bnode * root)
{
	// Implement DFS
	// Hint: You can use print_node, print_tree and/or print_stack.

  // Creating a new stack for my numbers
  stack *treestack = malloc(sizeof(stack));
  treestack->top = NULL;

  // Pushing my root to the stack
  push(treestack,root);

  //Creating a while loop to run through the whole tree
  while (!isEmpty(treestack))
  {
    // Creating a new Bnode to keep track of the location in the tree. It's defined as the last thing pushed to the tree, and is theirefore able to continue the loop.
    Bnode* head = pop(treestack);
    printf("%d\n", head->num);

    // Checking if theres children, and if so checking them.
    if(head->rchild != NULL)
    {
      push(treestack,head->rchild);
    }
     if(head->lchild != NULL)
    {
      push(treestack,head->lchild);
    }
  }
  




/*
  if(root->visited == false)
  {
    root->visited = true;
    push(treestack, root);
    print_node(root);
    printf(" ");

    if(root->lchild != NULL)
    {
       if(root->lchild->visited == false)
       {
          DFT(root->lchild);
       }
    }
    if(root->rchild != NULL)
    {
       if(root->rchild->visited == false)
       {
          DFT(root->rchild);
       }
    }
  }
  else
  {
    if(root->lchild != NULL)
    {
       if(root->lchild->visited == false)
       {
          DFT(root->lchild);
       }
    }
    if(root->rchild != NULL)
    {
       if(root->rchild->visited == false)
       {
          DFT(root->rchild);
       }
    }
  }
  print_stack(treestack);


  }
*/
}




Bnode *make_node (int num, Bnode * left, Bnode * right)
{
	Bnode *new_node = malloc(sizeof(Bnode));
  new_node->lchild = left;
  new_node->rchild = right;
  new_node->num = num;
  new_node->visited = false; 
  return new_node;
}


/*
void print_node (node * p)
{

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("%d", p->num);
}


void print_tree (node * p, int depth)
{
  for (int i = 0; i < depth; i = i + 1)
    printf (" ");
  printf ("| ");

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("[%d]\n", p->num);


  if (p->lchild)
    {
      print_tree (p->lchild, depth + 1);
    }

  if (p->rchild)
    print_tree (p->rchild, depth + 1);
}

*/

void push (stack* s, Bnode* bnode)
{
    //implement push here
    node *element = malloc(sizeof(node)); //Creating a pointer of type node, which for now points to somewhere.
    element->next = s->top; //Making element->next point to s->head, so it csan continue later on.
    s->top = element; // Making s->head equal to element.
    element->data = bnode; // Then we can insert our data into the stack.
}

bool isEmpty (stack* s)
{
  return s->top == NULL;
}


// Utility function to pop topp  
// element from the stack 

Bnode *pop (stack *s)
{
    if (s->top != NULL) // If the list isn't empty, then we would like to return some data.
    {
      Bnode* x = s->top->data; // We get our data.
      s->top = s->top->next; //Making s->head point to the last element.
      return x;
    } 
  return NULL;   
}

/*

void print_stack (stack * topp)
{
  struct stack *temp = topp;

  while (temp != NULL)
    {

      print_node (temp->node);
      printf ("\n");

      temp = temp->next;
    }

  printf ("====\n");

  return;
}
*/



