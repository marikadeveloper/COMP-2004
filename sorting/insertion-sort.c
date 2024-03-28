#include <stdio.h>

typedef int ElementType;

void InsertionSort(ElementType A[], int N)
{
  int j, P;
  ElementType Tmp;

  for (P = 1; P < N; P++)
  {
    Tmp = A[P];
    for (j = P; j > 0 && A[j - 1] > Tmp; j--)
    {
      A[j] = A[j - 1];
    }
    A[j] = Tmp;
  }
}

void printArray(ElementType A[], int N)
{
  for (int i = 0; i < N; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
}

int main()
{
  ElementType A[] = {3, 1, 4, 9, 2, 6, 5};
  int N = sizeof(A) / sizeof(ElementType);

  printf("Before sorting:\n");
  printArray(A, N);

  InsertionSort(A, N);

  printf("After sorting:\n");
  printArray(A, N);

  return 0;
}