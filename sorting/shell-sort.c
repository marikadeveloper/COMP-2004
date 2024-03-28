#include <stdio.h>

void ShellSort(int A[], int N)
{
  int i, j, Increment;
  int Tmp;
  for (Increment = N / 2; Increment > 0; Increment /= 2)
  {
    for (i = Increment; i < N; i++)
    {
      Tmp = A[i];
      for (j = i; j >= Increment; j -= Increment)
      {
        if (Tmp < A[j - Increment])
        {
          A[j] = A[j - Increment];
        }
        else
        {
          break;
        }
      }
      A[j] = Tmp;
    }
  }
}

void printArray(int A[], int N)
{
  for (int i = 0; i < N; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
}

int main()
{
  int A[] = {12, 34, 54, 2, 3};
  int N = sizeof(A) / sizeof(A[0]);
  ShellSort(A, N);
  printArray(A, N);
  return 0;
}