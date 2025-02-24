#ifndef RED_BLACK_H
#define RED_BLACK_H

typedef struct node {
  int value;
  struct node *left;
  struct node *right;
  struct node *parent;
  int black;
} node;

typedef node *tree;

tree insertNode(tree root, int value);
void printPreOrder(tree root);
tree removeNode(tree root, int value);

#endif