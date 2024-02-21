#include "stackar.c"
#include <stdlib.h>
#include <stdio.h>

void PrintStack(Stack S)
{
  // Print stack contents without emptying it
  if (!IsEmpty(S))
  {
    printf("Top of stack: %d\n", Top(S));
    printf("Stack contents: ");
    for (int i = 0; i <= S->TopOfStack; i++)
    {
      printf("%d ", S->Array[i]);
    }
    printf("\n");
  }
  else
  {
    printf("Stack is empty\n");
  }
}

int main()
{
  Stack s;

  s = CreateStack(10);

  Push(5, s);
  Push(15, s);
  Push(25, s);
  Push(35, s);

  // PrintStack(s);
  printf("Top = %d\n", Top(s));
  Push(45, s);
  Pop(s);

  Push(55, s);
  Push(65, s);
  Push(75, s);
  Push(85, s);

  printf("TopAndPop = %d\n", TopAndPop(s));
  printf("Top = %d\n", Top(s));

  Push(95, s);
  Push(105, s);
  Push(115, s);
  printf("Top = %d\n", Top(s));

  // Test stack overflow
  // Push(125, s);

  // Empty stack
  MakeEmpty(s);
  // Top(s);

  DisposeStack(s);

  return 0;
}