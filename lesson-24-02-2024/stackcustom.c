#include "stackcustom.h"
#include "fatal.h"
#include <stdlib.h>

#define EmptyTOS (-1)
#define MinStackSize (5)

struct StackObject
{
  int Index;
  int Height;
};

struct StackRecord
{
  // Stack capacity
  int Capacity;
  // Index of the top of the stack
  int TopOfStack;
  ElementType *Array;
};

int IsEmpty(Stack S)
{
  return S->TopOfStack == EmptyTOS;
}

int IsFull(Stack S)
{
  return S->TopOfStack == S->Capacity - 1;
}

Stack CreateStack(int MaxElements)
{
  Stack S;

  /* 1*/ if (MaxElements < MinStackSize)
    /* 2*/ Error("Stack size is too small");

  /* 3*/ S = malloc(sizeof(struct StackRecord));
  /* 4*/ if (S == NULL)
    /* 5*/ FatalError("Out of space!!!");

  /* 6*/ S->Array = malloc(sizeof(ElementType) * MaxElements);
  /* 7*/ if (S->Array == NULL)
    /* 8*/ FatalError("Out of space!!!");
  /* 9*/ S->Capacity = MaxElements;
  /*10*/ MakeEmpty(S);

  /*11*/ return S;
}

void MakeEmpty(Stack S)
{
  S->TopOfStack = EmptyTOS;
}

void DisposeStack(Stack S)
{
  if (S != NULL)
  {
    free(S->Array);
    free(S);
  }
}

void Push(ElementType X, Stack S)
{
  if (IsFull(S))
    Error("Full stack");
  else
    S->Array[++S->TopOfStack] = X;
}

ElementType
Top(Stack S)
{
  if (!IsEmpty(S))
    return S->Array[S->TopOfStack];
  Error("Empty stack");
}

void Pop(Stack S)
{
  if (IsEmpty(S))
    Error("Empty stack");
  else
    S->TopOfStack--;
}

ElementType
TopAndPop(Stack S)
{
  if (!IsEmpty(S))
    return S->Array[S->TopOfStack--];
  Error("Empty stack");
}