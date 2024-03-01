typedef char ElementType;

#ifndef _Binary_Tree_H
#define _Binary_Tree_H

struct BinaryNode;
typedef struct BinaryNode *BinaryTree;

struct BinaryNode
{
  ElementType Element;
  BinaryTree Left;
  BinaryTree Right;
};

BinaryTree MakeEmpty(BinaryTree T);
int Height(BinaryTree T);
BinaryTree InsertAtNode(ElementType X, BinaryTree T, char c);
void InOrder(BinaryTree T);
void PreOrder(BinaryTree T);
void PostOrder(BinaryTree T);

#endif