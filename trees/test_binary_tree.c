#include "binary_tree.h"
#include <stdio.h>

int main()
{
  BinaryTree root;

  root = InsertAtNode('R', NULL, 'l');

  root = InsertAtNode('a', root, 'l');
  root = InsertAtNode('b', root, 'r');
  printf("root-left: %c\n", root->Left->Element);
  printf("root-right: %c\n", root->Right->Element);

  root->Left = InsertAtNode('c', root->Left, 'l');
  root->Left = InsertAtNode('d', root->Left, 'r');

  root->Right = InsertAtNode('e', root->Right, 'l');
  root->Right = InsertAtNode('f', root->Right, 'r');

  root->Left->Right = InsertAtNode('g', root->Left->Right, 'l');
  root->Right->Left = InsertAtNode('f', root->Right->Left, 'r');

  printf("Tree height: %d \n", Height(root));
  printf("InOrder Traversal: ");
  InOrder(root);
  printf("\n");
  printf("PreOrder Traversal: ");
  PreOrder(root);
  printf("\n");
  printf("PostOrder Traversal: ");
  PostOrder(root);
  printf("\n");

  MakeEmpty(root);
}
