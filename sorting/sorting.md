# Sorting

## Assumptions for sorting algorithm

- keys are given in an input array
- keys are integer type, no duplicates (unless mentioned)
- number of keys (size of array) is known, usually denoted by N
- 'sorting' means **ascending** order (unless mentioned otherwise)
- after sorting, the sorted keys are stored in the same array (same storage space) as the input array

## Sorting problem and time complexity bounds

Sorting is a fundamental problem in computer science. The goal is to take a list of items and rearrange them in a specific order. The most common order is numerical or lexicographical order, but it can be anything that can be compared. Sorting is a key operation in many algorithms and is used to solve a variety of problems.

### Inversion

Given an array a[0], a[1], a[2],... a pair of elements a[i] and a[j] are inverted if i < j but a[i] > a[j].

The number of inversions in an array is a measure of how unsorted the array is. If the array is already sorted, the number of inversions is 0.

#### Example

3, 7, 1, 4, 6, 2, 5

All inversions:

- (3, 1), (3, 2)
- (7, 1), (7, 4), (7, 6), (7, 2), (7, 5)
- (4, 2)
- (6, 2), (6, 5)

**Notes**

- The **largest** element in the array is inverted with every element that comes after it;
- The **smallest** element is inverted with every element that comes before it.

#### Time complexity

Assume 1 swap takes 1 time-step
A sorting algo that makes fewer swaps takes fewer time-steps and gives better time complexity.

#### Best-case for the number of inversions

Example: 1,2,3,4,5,6 (sorted array)
Best case: Zero inversions

#### Worst-case for the number of inversions

Example: 6,5,4,3,2,1 (reverse sorted array)
Every pair of elements must be swapped. The number of pairs is N(N-1)/2. (calculated using permutations)
Worst case: N \* (N-1) / 2 inversions so O(N^2)

### Time complexity bounds

Sorting an array = fixing all inversions in the array

Worst case no. of inversions = O(N^2) **upper bound**

Best case no. of inversions = 0
But we still have to go through all the elements at least once to check if the array is sorted or not. So, the best case is O(N) **lower bound**

## Bubble Sort

Idea:

- Move the largest element to the right of the array
- Shrink the array (from the right) by 1
- Repeat the above steps until array shrinks to size 1

```c
int last = n-1;
while (last >= 1)
{
  for (int i = 0; i < last; i++) {
    if (a[i] > a[i+1]) {
      swap(a[i], a[i+1]);
    }
  }
  last--;
}
```

### Time complexity

Outer loop size: N-1 to 1 = O(N)
Inner loop size: 0 to N - 2 = O(N)

Time complexity: O(N)\*O(N) = **O(N^2)**

## Shaker Sort - Bidirectional Bubble Sort

Idea:

- Right pass:
  - Move the largest element to the right end of the array
  - Shrink the array from the right by 1
- Left pass:
  - Move the smallest element to the left end of the array
  - Shrink the array from the left by 1
- Repeat the above steps until the array shrinks to size 1

## Selection Sort - Another variation of Bubble Sort

Idea:

- Find the largest element in the array and swap it with the rightmost element in the array (one swap)
- Shrink the array from the right by 1
- Repeat the above steps until the array shrinks to size 1

## Insertion Sort

N-1 passes

At each pass p:

- Ensure that elements in positions 0 through p-1 are sorted
- Find the correct position between 0 to p-1 to insert a[p]

```c
void InsertionSort( ElementType A[], int N ) {
  int j, P;
  ElementType Tmp;

  for( P = 1; P < N; P++ ) {
    Tmp = A[ P ];
    for( j = P; j > 0 && A [ j - 1 ] > Tmp; j-- ) {
      A[ j ] = A[ j - 1 ];
    }
    A[ j ] = Tmp;
  }
}
```

### Time complexity

Outer for loop size: 1 to N-1 = O(N)

Inner for loop size (in worst case P = N-1): N-1 to 1 = O(N)

Time complexity: O(N)\*O(N) = **O(N^2)**

## Shell Sort

One of the first algos to break the O(N^2) barrier

Shell sort works by comparing elements that are distant.

The distance between comparisons decreases with each pass.

The last pass compares adjacent elements.

### Increment sequence

- shell sort uses a sequence, h1, h2, ... ht, called the increment sequence
- requirements for increment sequence: hi < hi+1 and h1 = 1
- after a hk-pass phase, all elements spaced hk apart are sorted
  - for every i, we have a[i] <= a[i + hk] - a is hk-sorted
- carefully selecting increment sequence gives fewer swaps and better time complexity

### Time complexity

Time complexity depends on the increment sequence
Worst-case time complexity: O(N^3/2)

For the best increment sequence, time complexity can be O(N^7/6) that is close to O(N)

**Shell sort is still the fastest sorting algorithm without using any additional storage**
