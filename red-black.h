#ifndef RED_BLACK_H
#define RED_BLACK_H

enum color { RED, BLACK, DOUBLE_BLACK };

typedef struct node {
  int value;
  enum color color;
  struct node *left;
  struct node *right;
  struct node *parent;
} node;

typedef node *tree;

void initialize(node* root);

void insertNode(tree *root, int value);
void removeNode(tree *root, int value);

int maxElement(tree root);
int minElement(tree root);
int height(tree root);

void printPreOrder(tree root);
void printInOrder(tree root);
void printPosOrder(tree root);
void printTree(tree root);

#endif