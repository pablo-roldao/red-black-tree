#include "red-black.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  node *tree;
  int opcao;
  initialize(tree);

  while (1) {
    scanf("%d", &opcao);

    switch (opcao) {
      int value;
    case 1:
      scanf("%d", &value);
      insertNode(&tree, value);
      break;
    case 2:
      printPreOrder(tree);
      printf("\n");
      break;
    case 3:
      scanf("%d", &value);
      removeNode(&tree, value);
      break;
    case 4:
      printf("%d\n", minElement(tree));
      break;
    case 5:
      printf("%d\n", height(tree));
      break;
    case 6:
      printInOrder(tree);
      printf("\n");
      break;
    case 7:
      printPosOrder(tree);
      printf("\n");
      break;
    case 8:
      printf("%d\n", maxElement(tree));
      break;
    case 9:
      printTree(tree);
      printf("\n");
      break;

    case 99:
      exit(0);
    }
  }
}