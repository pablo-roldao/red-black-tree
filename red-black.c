#include "red-black.h"
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return (a > b) ? a : b; }

tree leftRotate(tree a) {
  tree c = a->right;
  tree b = c->left;

  c->left = a;
  a->right = b;

  return c;
}

tree rightRotate(tree d) {
  tree b = d->left;
  tree c = b->right;

  b->right = d;
  d->left = c;

  return b;
}

tree insertNode(tree root, int value) {
  //to do

  return root;
}

void printPreOrder(tree root) {
  if (root != NULL) {
    printf("[%d %d]", root->value, root->black);
    printPreOrder(root->left);
    printPreOrder(root->right);
  }
}

node *getSuccessor(tree root) {
  if (root == NULL || root->right == NULL) {
    return NULL;
  }

  node *successor = root->right;
  while (successor->left != NULL) {
    successor = successor->left;
  }
  return successor;
}

tree removeNode(tree root, int value) {
  // to do

  return root;
}