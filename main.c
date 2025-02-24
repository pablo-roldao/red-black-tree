#include "red-black.h"
#include <stdio.h>

int main() {
  int option;
  tree tree = NULL;

  do {
    scanf("%d", &option);

    switch (option) {
    case 1: {
      int value;
      scanf("%d", &value);
      tree = insertNode(tree, value);
      break;
    }
    case 2: {
      printPreOrder(tree);
      printf("\n");
      break;
    }
    case 3: {
      int value;
      scanf("%d", &value);
      tree = removeNode(tree, value);
      break;
    }
    }
  } while (option != 99);

  return 0;
}