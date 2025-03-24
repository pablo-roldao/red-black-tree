#include "red-black.h"
#include <stdio.h>
#include <stdlib.h>

node *nullNode;

void initialize(node *root) {
  root = NULL;
  nullNode = (tree)malloc(sizeof(struct node));
  nullNode->color = DOUBLE_BLACK;
  nullNode->value = 0;
  nullNode->left = NULL;
  nullNode->right = NULL;
}

enum color color(node *node) {
  if (node == NULL || node->color == BLACK) {
    return BLACK;
  } else {
    return RED;
  }
}

int isLeftChild(node *node) {
  return (node->parent != NULL && node == node->parent->left);
}

node *brother(node *node) {
  if (isLeftChild(node)) {
    return node->parent->right;
  } else {
    return node->parent->left;
  }
}

node *uncle(node *node) { return brother(node->parent); }

void leftRotate(tree *root, node *x) {
  node *y = x->right;
  x->right = y->left;
  if (y->left != NULL)
      y->left->parent = x;
  y->parent = x->parent;
  if (x->parent == NULL)
      *root = y;
  else if (x == x->parent->left)
      x->parent->left = y;
  else
      x->parent->right = y;
  y->left = x;
  x->parent = y;
}

void rightRotate(tree *root, node *x) {
  node *y = x->left;
  x->left = y->right;
  if (y->right != NULL)
      y->right->parent = x;
  y->parent = x->parent;
  if (x->parent == NULL)
      *root = y;
  else if (x == x->parent->right)
      x->parent->right = y;
  else
      x->parent->left = y;
  y->right = x;
  x->parent = y;
}

void adjust(tree *root, node *n) {
  while (n->parent != NULL && color(n->parent) == RED) {
      node *u = uncle(n);
      if (color(u) == RED) {
          n->parent->color = BLACK;
          u->color = BLACK;
          n->parent->parent->color = RED;
          n = n->parent->parent;
      } else {
          if (isLeftChild(n->parent)) {
              if (!isLeftChild(n)) {
                  n = n->parent;
                  leftRotate(root, n);
              }
              n->parent->color = BLACK;
              n->parent->parent->color = RED;
              rightRotate(root, n->parent->parent);
          } else {
              if (isLeftChild(n)) {
                  n = n->parent;
                  rightRotate(root, n);
              }
              n->parent->color = BLACK;
              n->parent->parent->color = RED;
              leftRotate(root, n->parent->parent);
          }
      }
  }
  (*root)->color = BLACK;
}

void insertNode(tree *root, int value) {
  node *position = *root;
  node *parent = NULL;

  while (position != NULL) {
      parent = position;
      if (value > position->value)
          position = position->right;
      else
          position = position->left;
  }

  node *newNode = (node *)malloc(sizeof(node));
  newNode->value = value;
  newNode->left = newNode->right = NULL;
  newNode->parent = parent;
  newNode->color = RED;

  if (parent == NULL) {
      *root = newNode;
  } else {
      if (value > parent->value)
          parent->right = newNode;
      else
          parent->left = newNode;
  }

  adjust(root, newNode);
}

void printNode(tree root) {
  if (root->color == RED) {
    printf("[%d R]", root->value);
  } else {
    printf("[%d B]", root->value);
  }
}

tree sibling(tree node) {
  if (isLeftChild(node))
    return node->parent->right;
  else
    return node->parent->left;
}

void printTree(tree root) {
  if (root != NULL) {
    printNode(root);
    printTree(root->left);
    printTree(root->right);
  }
}

int max(int a, int b) { return (a > b) ? a : b; }

int height(tree root) {
  if (root == NULL) {
    return 0;
  }
  return 1 + max(height(root->right), height(root->left));
}

int maxElement(tree root) {
  if (root == NULL)
    return -1;
  if (root->right == NULL)
    return root->value;
  else
    return maxElement(root->right);
}

int minElement(tree root) {
  if (root == NULL)
    return -1;
  if (root->left == NULL)
    return root->value;
  else
    return minElement(root->left);
}

void printPreOrder(tree root) {
  if (root != NULL) {
    printNode(root);
    printPreOrder(root->left);
    printPreOrder(root->right);
  }
}

void printPosOrder(tree root) {
  if (root != NULL) {
    printPosOrder(root->left);
    printPosOrder(root->right);
    printNode(root);
  }
}

void printInOrder(tree root) {
  if (root != NULL) {
    printInOrder(root->left);
    printNode(root);
    printInOrder(root->right);
  }
}

void restructure(tree *root, tree node) {
  if (node->parent == NULL) {
    node->color = BLACK;
    return;
  }

  if (color(node->parent) == BLACK && color(sibling(node)) == RED &&
      color(sibling(node)->right) == BLACK &&
      color(sibling(node)->left) == BLACK) {

    if (isLeftChild(node))
      leftRotate(root, node->parent);
    else
      rightRotate(root, node->parent);

    node->parent->parent->color = BLACK;
    node->parent->color = RED;

    restructure(root, node);
    return;
  }

  if (color(node->parent) == BLACK && color(sibling(node)) == BLACK &&
      color(sibling(node)->right) == BLACK &&
      color(sibling(node)->left) == BLACK) {

    sibling(node)->color = RED;
    restructure(root, node->parent);
    return;
  }

  if (color(node->parent) == RED && color(sibling(node)) == BLACK &&
      color(sibling(node)->right) == BLACK &&
      color(sibling(node)->left) == BLACK) {

    sibling(node)->color = RED;
    node->parent->color = BLACK;
    return;
  }

  if (isLeftChild(node) && color(sibling(node)) == BLACK &&
      color(sibling(node)->left) == RED &&
      color(sibling(node)->right) == BLACK) {

    sibling(node)->color = RED;
    sibling(node)->left->color = BLACK;
    rightRotate(root, sibling(node));
    restructure(root, node);
    return;
  }

  if (!isLeftChild(node) && color(sibling(node)) == BLACK &&
      color(sibling(node)->right) == RED &&
      color(sibling(node)->left) == BLACK) {

    sibling(node)->color = RED;
    sibling(node)->right->color = BLACK;
    leftRotate(root, sibling(node));
    restructure(root, node);
    return;
  }

  if (isLeftChild(node) && color(sibling(node)) == BLACK &&
      color(sibling(node)->right) == RED) {

    sibling(node)->color = color(node->parent);
    node->parent->color = BLACK;
    sibling(node)->right->color = BLACK;
    leftRotate(root, node->parent);
    return;
  }

  if (!isLeftChild(node) && color(sibling(node)) == BLACK &&
      color(sibling(node)->left) == RED) {

    sibling(node)->color = color(node->parent);
    node->parent->color = BLACK;
    sibling(node)->left->color = BLACK;
    rightRotate(root, node->parent);
    return;
  }
}

void removeNode(tree *root, int value) {
  tree position;
  position = *root;

  while (position != NULL) {
    if (value == position->value) {
      if (position->left != NULL && position->right != NULL) {
        position->value = maxElement(position->left);
        removeNode(&(position->left), position->value);
        break;
      }

      if (position->left == NULL && position->right != NULL) {
        position->right->color = BLACK;
        position->right->parent = position->parent;

        if (position->parent == NULL) {
          *root = position->right;
        } else {
          if (isLeftChild(position)) {
            position->parent->left = position->right;
          } else {
            position->parent->right = position->right;
          }
        }
        break;
      }

      if (position->right == NULL && position->left != NULL) {
        position->left->color = BLACK;
        position->left->parent = position->parent;

        if (position->parent == NULL) {
          *root = position->left;
        } else {
          if (isLeftChild(position)) {
            position->parent->left = position->left;
          } else {
            position->parent->right = position->left;
          }
        }
        break;
      }

      if (position->left == NULL && position->right == NULL) {
        if (position->parent == NULL) {
          *root = NULL;
          break;
        }

        if (position->color == RED) {
          if (isLeftChild(position)) {
            position->parent->left = NULL;
          } else {
            position->parent->right = NULL;
          }
          break;
        } else {
          nullNode->parent = position->parent;
          if (isLeftChild(position)) {
            position->parent->left = nullNode;
          } else {
            position->parent->right = nullNode;
          }

          restructure(root, nullNode);
          break;
        }
      }
    }

    if (value > position->value) {
      position = position->right;
    } else {
      position = position->left;
    }
  }
}

void remove_double_black(tree *root, tree node) {
  if (node == nullNode)
    if (isLeftChild(node))
      node->parent->left = NULL;
    else
      node->parent->right = NULL;
  else
    node->color = BLACK;
}
