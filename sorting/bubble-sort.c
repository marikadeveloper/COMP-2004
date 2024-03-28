#include <stdio.h>

void printArray(int a[], int n);

void bubbleSort(int a[], int n)
{
  int temp;
  int last = n - 1;
  while (last >= 1)
  {
    for (int i = 0; i < last; i++)
    {
      if (a[i] > a[i + 1])
      {
        temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
      }
    }
    printArray(a, n);
    last--;
  }
}

void printArray(int a[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");
}

int main()
{
  int a[] = {5, 2, 4, 6, 1, 3};
  int n = sizeof(a) / sizeof(a[0]);

  printf("Before sorting: ");
  printArray(a, n);

  bubbleSort(a, n);

  printf("After sorting: ");
  printArray(a, n);

  return 0;
}