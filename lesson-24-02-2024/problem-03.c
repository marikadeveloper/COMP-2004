/**
 * Given an array of integers heights representing the histogram's bar height
 * where the width of each bar is 1,
 * return the area of the largest rectangle in the histogram.
 *
 * Use a stack to solve it
 */

#include <stdio.h>
#include <stdlib.h>
#include "stackcustom.c"

void PrintStack(Stack S)
{
  // Print stack contents without emptying it
  if (!IsEmpty(S))
  {
    printf("Top of stack: index=%d height=%d\n", Top(S).Index, Top(S).Height);
    printf("Stack contents: \n");
    for (int i = 0; i <= S->TopOfStack; i++)
    {
      printf("index=%d height=%d\n", S->Array[i].Index, S->Array[i].Height);
    }
    printf("\n");
  }
  else
  {
    printf("Stack is empty\n");
  }
}

int main(void)
{
  int arrayLength = 6;
  int heights[6] = {2, 1, 5, 6, 2, 3};
  int maxArea = 0;
  int i;

  Stack s = CreateStack(arrayLength);

  ElementType first;
  first.Index = 0;
  first.Height = heights[0];
  Push(first, s);

  PrintStack(s);

  for (i = 1; i < arrayLength; i++)
  {
    const ElementType currentTop = Top(s);
    ElementType currentElement;
    currentElement.Height = heights[i];

    if (currentElement.Height < currentTop.Height)
    {
      // the top can not be extended any further because the top of the stack
      // is greater than the current elemtn
      int poppedElementsCount = 0;
      while (!IsEmpty(s) && Top(s).Height > currentElement.Height)
      {
        // calculate area of top of the stack's height
        const ElementType top = Top(s);
        const int potentialAreaWidth = i - top.Index;
        const int potentialAreaHeight = top.Height;
        const int potentialArea = potentialAreaHeight * potentialAreaWidth;

        if (potentialArea > maxArea)
        {
          maxArea = potentialArea;
        }

        // pop the top from the stack
        Pop(s);
        poppedElementsCount++;
      }

      // insert currentElement with index i - poppedElementsCount
      currentElement.Index = i - poppedElementsCount;
      Push(currentElement, s);
    }
    else
    {
      // if the current element is equal or greater than the top of the stack
      // means we can expand the area
      currentElement.Index = i;
      Push(currentElement, s);
    }
    PrintStack(s);
    printf("\n----\n");
  }

  // calculate the area of the remaining elements in the stack (if any)
  while (!IsEmpty(s))
  {
    const ElementType top = TopAndPop(s);
    const int potentialAreaWidth = i - top.Index;
    const int potentialAreaHeight = top.Height;
    const int potentialArea = potentialAreaHeight * potentialAreaWidth;

    if (potentialArea > maxArea)
    {
      maxArea = potentialArea;
    }

    i -= potentialAreaWidth;
  }

  printf("max area=%d\n", maxArea);

  return 0;
}