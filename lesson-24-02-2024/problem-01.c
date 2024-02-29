#include <stdio.h>
#include <stdlib.h>

/**
 * Two integer arrays of size n and m are given. They have only single digit integers
 * Another integer k is given, where k <= n + m.
 *
 * Problem: find the largest integer with k digits that can be formed using the elements
 * of a1 and a2 without repetition
 *
 * example:
 * k = 3
 * a1 = {3, 1, 2, 8};
 * a2 = {1, 1, 4, 2, 7, 6};
 * output -> 876
 *
 * k = 10
 * output -> 8764322111
 */

// Sort in descending order
int compare(const void *a, const void *b)
{
  return *(int *)b - *(int *)a;
}

// O(nlogn) + O(mlogm) + O(k) = O(nlogn + mlogm + k) = O(nlogn)
void largestNumber(int a1[], int n, int a2[], int m, int k)
{
  qsort(a1, n, sizeof(int), compare); // Time complexity: O(nlogn)
  qsort(a2, m, sizeof(int), compare); // Time complexity: O(mlogm)

  // for each digit in k we need to find the largest number in a1 and a2
  // that can be formed without repetition
  int i = 0, j = 0;
  int result[k];

  for (int l = 0; l < k; l++)
  {
    if (i < n && (j >= m || a1[i] > a2[j]))
    {
      result[l] = a1[i];
      i++;
    }
    else if (j < m)
    {
      result[l] = a2[j];
      j++;
    }
  }

  for (int l = 0; l < k; l++)
  {
    printf("%d", result[l]);
  }
}

int main(void)
{
  int n = 4;
  int a1[4] = {3, 1, 2, 8};

  int m = 7;
  int a2[7] = {1, 1, 4, 2, 7, 6};

  int k = 3;

  largestNumber(a1, n, a2, m, k);

  return 0;
}