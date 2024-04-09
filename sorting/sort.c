/* This file contains a collection of sorting routines */

#include <stdlib.h>
#include <stdio.h>

typedef int ElementType;

void Swap(ElementType *Lhs, ElementType *Rhs)
{
  ElementType Tmp = *Lhs;
  *Lhs = *Rhs;
  *Rhs = Tmp;
}

// print array
void printArray(int a[], int n)
{
  for (int i = 0; i < n; ++i)
  {
    printf("%d  ", a[i]);
  }
  printf("\n");
}

// perform the bubble sort
void Bubblesort(ElementType a[], int n)
{

  // loop to access each array element
  for (int step = 0; step < n - 1; ++step)
  {

    // loop to compare array elements
    for (int i = 0; i < n - step - 1; ++i)
    {

      // compare two adjacent elements
      // change > to < to sort in descending order
      if (a[i] > a[i + 1])
      {

        // swapping occurs if elements
        // are not in the intended order
        ElementType temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
      }
    }
  }
}

void Insertionsort(ElementType A[], int N)
{
  int j, P;
  ElementType Tmp;

  /* 1*/ for (P = 1; P < N; P++)
  {
    /* 2*/ Tmp = A[P];
    /* 3*/ for (j = P; j > 0 && A[j - 1] > Tmp; j--)
      /* 4*/ A[j] = A[j - 1];
    /* 5*/ A[j] = Tmp;
  }

  printf("Array after insertion sort: ");
  printArray(A, N);
}

void Shellsort(ElementType A[], int N)
{
  int i, j, Increment;
  ElementType Tmp;

  /* 1*/ for (Increment = N / 2; Increment > 0; Increment /= 2)
    /* 2*/ for (i = Increment; i < N; i++)
    {
      /* 3*/ Tmp = A[i];
      /* 4*/ for (j = i; j >= Increment; j -= Increment)
        /* 5*/ if (Tmp < A[j - Increment])
          /* 6*/ A[j] = A[j - Increment];
        else
          /* 7*/ break;
      /* 8*/ A[j] = Tmp;
    }
}

#define LeftChild(i) (2 * (i) + 1)

void PercDown(ElementType A[], int i, int N)
{
  int Child;
  ElementType Tmp;

  /* 1*/ for (Tmp = A[i]; LeftChild(i) < N; i = Child)
  {
    /* 2*/ Child = LeftChild(i);
    /* 3*/ if (Child != N - 1 && A[Child + 1] > A[Child])
      /* 4*/ Child++;
    /* 5*/ if (Tmp < A[Child])
      /* 6*/ A[i] = A[Child];
    else
      /* 7*/ break;
  }
  /* 8*/ A[i] = Tmp;
}

void Heapsort(ElementType A[], int N)
{
  int i;

  /* 1*/ for (i = N / 2; i >= 0; i--) /* BuildHeap */
    /* 2*/ PercDown(A, i, N);
  /* 3*/ for (i = N - 1; i > 0; i--)
  {
    /* 4*/ Swap(&A[0], &A[i]); /* DeleteMax */
    /* 5*/ PercDown(A, 0, i);
  }
}

void Merge(ElementType A[], ElementType TmpArray[],
           int Lpos, int Rpos, int RightEnd)
{
  int i, LeftEnd, NumElements, TmpPos;

  LeftEnd = Rpos - 1;
  TmpPos = Lpos;
  NumElements = RightEnd - Lpos + 1;

  /* main loop */
  while (Lpos <= LeftEnd && Rpos <= RightEnd)
    if (A[Lpos] <= A[Rpos])
      TmpArray[TmpPos++] = A[Lpos++];
    else
      TmpArray[TmpPos++] = A[Rpos++];

  while (Lpos <= LeftEnd) /* Copy rest of first half */
    TmpArray[TmpPos++] = A[Lpos++];
  while (Rpos <= RightEnd) /* Copy rest of second half */
    TmpArray[TmpPos++] = A[Rpos++];

  /* Copy TmpArray back */
  for (i = 0; i < NumElements; i++, RightEnd--)
    A[RightEnd] = TmpArray[RightEnd];
}

void MSort(ElementType A[], ElementType TmpArray[],
           int Left, int Right)
{
  int Center;

  if (Left < Right)
  {
    Center = (Left + Right) / 2;
    MSort(A, TmpArray, Left, Center);
    MSort(A, TmpArray, Center + 1, Right);
    Merge(A, TmpArray, Left, Center + 1, Right);
  }
}

void Mergesort(ElementType A[], int N)
{
  ElementType *TmpArray;

  TmpArray = malloc(N * sizeof(ElementType));
  if (TmpArray != NULL)
  {
    MSort(A, TmpArray, 0, N - 1);
    free(TmpArray);
  }
  else
  {
    printf("No space for tmp array!!!");
    exit(1);
  }
}

ElementType
Median3(ElementType A[], int Left, int Right)
{
  int Center = (Left + Right) / 2;

  if (A[Left] > A[Center])
    Swap(&A[Left], &A[Center]);
  if (A[Left] > A[Right])
    Swap(&A[Left], &A[Right]);
  if (A[Center] > A[Right])
    Swap(&A[Center], &A[Right]);

  /* Invariant: A[ Left ] <= A[ Center ] <= A[ Right ] */

  Swap(&A[Center], &A[Right - 1]); /* Hide pivot */
  return A[Right - 1];             /* Return pivot */
}

#define Cutoff (3)

void Qsort(ElementType A[], int Left, int Right)
{
  int i, j;
  ElementType Pivot;

  printf("\nArray before partitioning: ");
  printArray(A + Left, Right - Left + 1);

  if (Left + Cutoff <= Right)
  {
    Pivot = Median3(A, Left, Right);
    printf("Pivot: %d\n", Pivot);
    printf("Array after pivot: ");
    printArray(A + Left, Right - Left + 1);

    i = Left;
    j = Right - 1;
    printf("i = %d, j = %d\n", A[i], A[j]);
    for (;;)
    {
      while (A[++i] < Pivot)
      {
      }
      while (A[--j] > Pivot)
      {
      }
      if (i < j)
      {
        printf("* Swapping %d with %d\n", A[i], A[j]);
        Swap(&A[i], &A[j]);
      }
      else
        break;
    }
    printf("* Restoring pivot: swapping %d with %d\n", A[i], A[Right - 1]);
    Swap(&A[i], &A[Right - 1]); /* Restore pivot */

    printf("Array after partitioning: ");
    printf("\nLeft array: ");
    printArray(A + Left, i - Left);
    printf("Right array: ");
    printArray(A + i + 1, Right - i);

    Qsort(A, Left, i - 1);
    Qsort(A, i + 1, Right);

    // the code goes here when the insertion sort sorted the last bits of the array
    // this is the backtracking part of the quicksort
    printf("-> Array after sorting: ");
    printArray(A + Left, Right - Left + 1);
  }
  else /* Do an insertion sort on the subarray */
  {
    Insertionsort(A + Left, Right - Left + 1);
  }
}

/* This code doesn't work */
#if 0

/* 3*/          i = Left + 1; j = Right - 2;
/* 4*/          for( ; ; )
                {
/* 5*/              while( A[ i ] < Pivot ) i++;
/* 6*/              while( A[ j ] > Pivot ) j--;
/* 7*/              if( i < j )
/* 8*/                  Swap( &A[ i ], &A[ j ] );
                    else
/* 9*/                  break;
                }

#endif

void Quicksort(ElementType A[], int N)
{
  Qsort(A, 0, N - 1);
}

/* Places the kth smallest element in the kth position */
/* Because arrays start at 0, this will be index k-1 */
void Qselect(ElementType A[], int k, int Left, int Right)
{
  int i, j;
  ElementType Pivot;

  if (Left + Cutoff <= Right)
  {
    Pivot = Median3(A, Left, Right);
    i = Left;
    j = Right - 1;
    for (;;)
    {
      while (A[++i] < Pivot)
      {
      }
      while (A[--j] > Pivot)
      {
      }
      if (i < j)
        Swap(&A[i], &A[j]);
      else
        break;
    }
    Swap(&A[i], &A[Right - 1]); /* Restore pivot */

    if (k <= i)
      Qselect(A, k, Left, i - 1);
    else if (k > i + 1)
      Qselect(A, k, i + 1, Right);
  }
  else /* Do an insertion sort on the subarray */
    Insertionsort(A + Left, Right - Left + 1);
}

int main()
{
  int a[] = {63, 87, 144, 118, -2, 46, -16, 7, -32, 99, 68, 37, 128, 55, -12, 76};

  // find the array's length
  int n = sizeof(a) / sizeof(a[0]);

  printf("Array Before Sorting: ");
  printArray(a, n);

  // uncomment the appropriate sort algorithm you want to use

  // Bubblesort(a, n);
  // Insertionsort( a, n );
  // Shellsort( a, n );
  Quicksort(a, n);
  // Mergesort( a, n );
  // Heapsort( a, n );

  printf("Sorted Array in Ascending Order ");
  printArray(a, n);
}

/*
The below code generates different permutations of int elements
inside a 7000 element array and sorts the array using the different
sort algorithms - Comment/Uncomment to run it, as necessary
*/

/*
     #define MaxSize 7000
     int Arr1[ MaxSize ];
     int Arr2[ MaxSize ];



     void
     Permute( ElementType A[ ], int N )
     {
         int i;

         for( i = 0; i < N; i++ )
             A[ i ] = i;
         for( i = 1; i < N; i++ )
             Swap( &A[ i ], &A[ rand( ) % ( i + 1 ) ] );
     }

     void
     Checksort( ElementType A[ ], int N )
     {
         int i;
         for( i = 0; i < N; i++ )
             if( A[ i ] != i )
                 printf( "Sort fails: %d %d\n", i, A[ i ] );
         printf( "Check completed\n" );
     }

     void
     Copy( ElementType Lhs[ ], const ElementType Rhs[ ], int N )
     {
         int i;
         for( i = 0; i < N; i++ )
             Lhs[ i ] = Rhs[ i ];
     }

     int main( )
     {
         int i;

         for( i = 0; i < 10; i++ )
         {
             Permute( Arr2, MaxSize );
             Copy( Arr1, Arr2, MaxSize );
             InsertionSort( Arr1, MaxSize );
             Checksort( Arr1, MaxSize );

             Copy( Arr1, Arr2, MaxSize );
             Shellsort( Arr1, MaxSize );
             Checksort( Arr1, MaxSize );

             Copy( Arr1, Arr2, MaxSize );
             Heapsort( Arr1, MaxSize );
             Checksort( Arr1, MaxSize );

             Copy( Arr1, Arr2, MaxSize );
             Mergesort( Arr1, MaxSize );
             Checksort( Arr1, MaxSize );

             Copy( Arr1, Arr2, MaxSize );
             Quicksort( Arr1, MaxSize );
             Checksort( Arr1, MaxSize );

             Copy( Arr1, Arr2, MaxSize );
             Qselect( Arr1, MaxSize / 2 + 1 + i, 0, MaxSize - 1 );
             if( Arr1[ MaxSize / 2 + i ] != MaxSize / 2 + i )
                 printf( "Select error: %d %d\n", MaxSize / 2 + i ,
                                         Arr1[ MaxSize / 2 + i ] );
             else
                 printf( "Select works\n" );
         }

         return 0;
     }
 */
