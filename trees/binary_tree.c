#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

BinaryTree MakeEmpty(BinaryTree T)
{
  if (T != NULL)
  {
    MakeEmpty(T->Left);
    MakeEmpty(T->Right);
    free(T);
  }
  return NULL;
}

int Height(BinaryTree T)
{
  if (T == NULL)
    return -1;
  else /* leaf node*/
    if ((T->Left == NULL) && (T->Right == NULL))
      return 0;
    else
    { /* return height of taller subtree (l or r) + 1*/
      int l = Height(T->Left);
      int r = Height(T->Right);
      return l > r ? l + 1 : r + 1;
    }
}

BinaryTree InsertAtNode(ElementType X, BinaryTree T, char c)
{
  if (T == NULL)
  {
    /* Create and return a one-node tree */
    T = malloc(sizeof(struct BinaryNode));
    if (T == NULL)
    {
      printf("Out of space!!!\n");
      exit(1);
    }
    else
    {
      T->Element = X;
      T->Left = T->Right = NULL;
    }
  }

  BinaryTree new_node;
  new_node = malloc(sizeof(struct BinaryNode));
  new_node->Element = X;
  new_node->Left = new_node->Right = NULL;

  if (c == 'l')
    T->Left = new_node;
  else if (c == 'r')
    T->Right = new_node;
  else
  {
    printf("Node not inserted: Must specify 'l'eft or 'r'ight subtree of T\n");
  }
  return T; /* Do not forget this line!! */
}

void InOrder(BinaryTree T)
{

  if (T != NULL)
  {
    if (T->Left != NULL)
      InOrder(T->Left);
    printf("%c ", T->Element);
    if (T->Right != NULL)
      InOrder(T->Right);
  }
}

void PreOrder(BinaryTree T)
{

  if (T != NULL)
  {
    printf("%c ", T->Element);
    if (T->Left != NULL)
      PreOrder(T->Left);
    if (T->Right != NULL)
      PreOrder(T->Right);
  }
}

void PostOrder(BinaryTree T)
{

  if (T != NULL)
  {
    if (T->Left != NULL)
      PostOrder(T->Left);
    if (T->Right != NULL)
      PostOrder(T->Right);
    printf("%c ", T->Element);
  }
}
