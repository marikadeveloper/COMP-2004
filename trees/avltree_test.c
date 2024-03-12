#include "avltree.h"
#include <stdio.h>

void PostOrder(AvlTree T)
{
    if (T!=NULL)
    {
        PostOrder(T->Left);
        PostOrder(T->Right);
        printf("%d ", T->Element);
    }
}

void PreOrder(AvlTree T)
{
    if (T!=NULL)
    {
        printf("%d ", T->Element);
        PreOrder(T->Left);
        PreOrder(T->Right);
    }
}

int main()
{
    AvlTree t;
    
    t = Insert (1, t);
    t = Insert (2, t);
    
    t = Insert (9, t);
    printf("PostOrder Traversal: ");
    PostOrder(t);
    printf("\n");
    
    printf("PreOrder Traversal: ");
    PreOrder(t);
    printf("\n");

    t = Insert (3, t);
    printf("PostOrder Traversal: ");
    PostOrder(t);
    printf("\n");
    printf("PreOrder Traversal: ");
    PreOrder(t);
    printf("\n");
    
    t = Insert (4, t);
    printf("PostOrder Traversal: ");
    PostOrder(t);
    printf("\n");
    printf("PreOrder Traversal: ");
    PreOrder(t);
    printf("\n");
    
    
    t = Insert (5, t);
    printf("PostOrder Traversal: ");
    PostOrder(t);
    printf("\n");
    printf("PreOrder Traversal: ");
    PreOrder(t);
    printf("\n");
    
    
    t = Insert (6, t);
    printf("PostOrder Traversal: ");
    PostOrder(t);
    printf("\n");
    printf("PreOrder Traversal: ");
    PreOrder(t);
    printf("\n");
    
    
    t = Insert (7, t);
    printf("PostOrder Traversal: ");
    PostOrder(t);
    printf("\n");
    printf("PreOrder Traversal: ");
    PreOrder(t);
    printf("\n");
    
    
    t = Insert (8, t);
    printf("PostOrder Traversal: ");
    PostOrder(t);
    printf("\n");
    printf("PreOrder Traversal: ");
    PreOrder(t);
    printf("\n");
    
}