#include <stdio.h>

void printArray(int A[], int N)
{
  for (int i = 0; i < N; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
}

void ShellSort(int A[], int N)
{
  int i, j, Increment;
  int Tmp;
  int swapCount = 0;

  int increments[] = {7, 3, 1};

  for (int k = 0; k < sizeof(increments) / sizeof(increments[0]); k++)
  {
    Increment = increments[k];
    if (Increment >= N)
    {
      continue;
    }
    printf("Increment: %d\n", Increment);
    for (i = Increment; i < N; i++)
    {
      Tmp = A[i];
      for (j = i; j >= Increment; j -= Increment)
      {
        printf("comparing %d with %d\n", Tmp, A[j - Increment]);
        if (Tmp < A[j - Increment])
        {
          printf("swapping %d with %d\n", Tmp, A[j - Increment]);
          A[j] = A[j - Increment]; //
          swapCount++;
        }
        else
        {
          break;
        }
      }
      A[j] = Tmp;
    }

    printArray(A, N);
    printf("\n");
  }
}

int main()
{
  int A[] = {-46, 73, 10, -89, 55, -32, 28, 91, -15, -79, 64, -3, 42, -68, 7, -20, 86, -95, 49, -52};

  int N = sizeof(A) / sizeof(A[0]);
  ShellSort(A, N);
  printArray(A, N);
  return 0;
}