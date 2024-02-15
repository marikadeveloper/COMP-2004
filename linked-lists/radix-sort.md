# Radix Sort using Array of List

Most sorting algos have time complexity between O(n log n) and O(n<sup>2</sup>).

Radix sort (also called bucket sort or card sort) is an exception, it has time complexity O(nk) where n is the number of elements and k is the number of digits in the largest number. It is a non-comparison based sorting algorithm.
It uses more memory than other sorting algorithms, it requires an extra data structure (an array of lists), plus the input array.

## Our Assumptions

- We are sorting integers
- Data to be sorted is provided in an array that is passed as input to the sorting algo
- No duplicate elements in the input array
- Sort means ascending order

## Representation

We will represent the array of lists using a 2D array. The first dimension will be the number of digits (0-9) and the second dimension will be the number of elements in the input array.

[0] [] -> [ []]-> [ []]-> [ []]-> [ []]-> [ []]-> [ []]-> [ []]-> [ []]-> [ []]-> [ []]
[1] [] -> [ []]-> [ []]-> [ []]-> [ []]-> [ []]-> [ []]-> [ []]-> [ []]-> [ []]-> [ []]
[2] [] -> [ []]-> [ []]-> [ []]-> [ []]-> [ []]-> [ []]-> [ []]-> [ []]-> [ []]-> [ []]
...
[9] [] -> [ []]-> [ []]-> [ []]-> [ []]-> [ []]-> [ []]-> [ []]-> [ []]-> [ []]-> [ []]

- the size of the array is fixed and equal to an exponent of 10 (e.g. 10 or 100 or 1000 etc.). This is because we are sorting integers and integers are base 10
- the array elements are called buckets
- each list grows and shrinks dynamically; initially each list is an empty or NULL list

## Algorithm - English Version

1. Find the number of digits in the largest number
2. For each digit position (from right to left):
   - for each element in the input array:
     - find the digit at the current position
     - add the element to the list corresponding to the digit
   - for each list:
     - remove the elements from the list and add them back to the input array
3. The input array is now sorted

## Algorithm - English Version v2

1. Let M be the number of digits in the maximum value in _a_
2. k (loop control variable) goes from 0 to M-1
3. In the k-th iteration, put each a[i] in the bucket corresponding to the k-th significant digit of a[i]
4. Copy the elements from the buckets back to the array _a_ at the end of each iteration (and free each bucket's memory)

## Example

Input: 56 45 49 16 35 26 18 23 19 8 5 4
Output: 4 5 8 16 18 19 23 26 35 45 49 56

input array _a_

```js
[
  [0]:  56
  [1]:  45
  [2]:  49
  [3]:  16
  [4]:  35
  [5]:  26
  [6]:  18
  [7]:  23
  [8]:  19
  [9]:  8
  [10]: 5
  [11]: 4
]
```

We will consider 10 buckets
Maximum value in _a_ is 56, so we will consider 2 digits -> M = 2

Create an array of 10 buckets
Each bucket (element of the array) points to an empty list
k will go from 0 to M-1 (0 to 1)

a = [56, 45, 49, 16, 35, 26, 18, 23, 19, 8, 5, 4]

[0] -> []
[1] -> []
[2] -> []
[3] -> []
[4] -> []
[5] -> []
[6] -> []
[7] -> []
[8] -> []
[9] -> []

### 0th pass

Puth each a[i] in the bucket corresponding to a[i]'s 0th significant (that is, least significant of units) digit

k = 0

- 56 -> 6 -> put 56 in bucket 6
- 45 -> 5 -> put 45 in bucket 5
- 49 -> 9 -> put 49 in bucket 9
- 16 -> 6 -> put 16 in bucket 6
- 35 -> 5 -> put 35 in bucket 5
- 26 -> 6 -> put 26 in bucket 6
- 18 -> 8 -> put 18 in bucket 8
- 23 -> 3 -> put 23 in bucket 3
- 19 -> 9 -> put 19 in bucket 9
- 8 -> 8 -> put 8 in bucket 8
- 5 -> 5 -> put 5 in bucket 5
- 4 -> 4 -> put 4 in bucket 4

[0] -> []
[1] -> []
[2] -> []
[3] -> [23]
[4] -> [4]
[5] -> [45, 35, 5]
[6] -> [56, 16, 26]
[7] -> []
[8] -> [18, 8]
[9] -> [49, 19]

Copy the elements from the buckets back to the array _a_ at the end of each iteration (and free each bucket's memory)

a = [23, 4, 45, 35, 5, 56, 16, 26, 18, 8, 49, 19]

Now all elements are sorted according to their 0th significant digit

### 1st pass

Puth each a[i] in the bucket corresponding to a[i]'s 1st significant (that is, 2nd least significant or tens) digit

k = 1

- 23 -> 2 -> put 23 in bucket 2
- 4 -> 0 -> put 4 in bucket 0
- 45 -> 4 -> put 45 in bucket 4
- 35 -> 3 -> put 35 in bucket 3
- 5 -> 0 -> put 5 in bucket 0
- 56 -> 5 -> put 56 in bucket 5
- 16 -> 1 -> put 16 in bucket 1
- 26 -> 2 -> put 26 in bucket 2
- 18 -> 1 -> put 18 in bucket 1
- 8 -> 0 -> put 8 in bucket 0
- 49 -> 4 -> put 49 in bucket 4
- 19 -> 1 -> put 19 in bucket 1

[0] -> [4, 5, 8]
[1] -> [16, 18, 19]
[2] -> [23, 26]
[3] -> [35]
[4] -> [45, 49]
[5] -> [56]
[6] -> []
[7] -> []
[8] -> []
[9] -> []

Copy the elements from the buckets back to the array _a_ at the end of each iteration (and free each bucket's memory)

a = [4, 5, 8, 16, 18, 19, 23, 26, 35, 45, 49, 56]

Now all elements are sorted according to their 1st significant digit, and the array is completely sorted

## Time Complexity

Number of passes = M (number of digits in the largest number)

Each pass has O(N) steps to put N elements from _a_ into buckets and copy them back to _a_

Total n of steps = O(MN)
But M << N, M is usually ~ 10, N ~ 10<sup>6</sup> or 10<sup>7</sup>
M can be treated as a constant, so time complexity is **O(N)**
