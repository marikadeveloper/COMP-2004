# Table of contents

- [General rules](#general-rules)
  - [Constants get absorbed](#constants-get-absorbed)
  - [Addition Rule](#addition-rule)
  - [Multiplication Rule](#multiplication-rule)
  - [Simple statements](#simple-statements)
  - [For loops](#for-loops)
  - [Nested for loops](#nested-for-loops)
  - [Consecutive statements with loops](#consecutive-statements-with-loops)
  - [If-else statements](#if-else-statements)
  - [Method calls](#method-calls)
- [Algorithm Analysis](#algorithm-analysis)
  - [Binary search algorithm](#binary-search-algorithm)
  - [Another log time complexity algorithm](#another-log-time-complexity-algorithm)
  - [Another log time complexity algorithm](#another-log-time-complexity-algorithm-1)
  - [Yet another log time complexity algorithm](#yet-another-log-time-complexity-algorithm)
- [Quiz 1 module 2 examples](#quiz-1-module-2-examples)
  - [Example 1](#example-1)
  - [Example 2](#example-2)
  - [Example 3](#example-3)
  - [Example 4](#example-4)
  - [Example 5](#example-5)
  - [Example 6](#example-6)

# General rules

## Constants get absorbed

O(5) = O(1)
O(2N) = O(N)
0(1000 N^2) = O(N^2)

## Addition Rule

T1(N) = O(f1(N)), T2(N) = O(f2(N))
T1(N) + T2(N) = O(max(f1(N), f2(N)))
T1(N) = O(N^2), T2(N) = O(N log N)
T1(N) + T2(N) = O(N^2)

## Multiplication Rule

T1(N) = O(f1 (N)), T2(N) = O(f2(N))
T1(N) _ T2(N) = O(T1(N) _ T2(N))
T1(N) = O(N^2), T2(N) = O(N log N)
T1(N) _ T2(N) = O(N^3 log N)
T1(N) = O(N), T2(N) = O(1)
T1(N) _ T2(N) = O(N*1) = O(N)
T1(N) = O(N^4), T2(N). = O(N^2)
1(N) *T2(N) = O(N^4 \* N^2) = O(N^6)

N is always a positive integer - N is the number of inputs to an algorithm

## Simple statements

A simple statement takes 0(1)

```c
int 1; // one statement: 0(1)
printf("Enter i: "); // 0(1)
scanf("ed", &i); // 0(1)
int j = 5; // 0(1)
int y = i * j + 3; // 0(1)
y++; // 0(1)
printf("i=8d, j=8d, y=8d\n", i, j, k); // 0(1)
```

Add run-time of consecutive statements using addition rule
Run-time: 0(1) + 0(1) + 0(1) .. + 0(1) = 0(1)

## For loops

The running time of a for loop is at most the running time of the statements inside the for loop (including tests) times of the number of iterations.

```c
for (int j = 0; j < N; j++) // N
  k++; // O(1)
```

Run-time: N \* O(1) = O(N)

## Nested for loops

Start with the innermost loop and go outwards
The total running time of a statement inside a group of nested loops is the running time of the statement multiplied by the product of the sizes of all the loops.

```c
for (int i = 0; i < N; i++) // N
  for (int j = 0; j < N; j++) // N
    k++; // O(1)
```

Runtime: N \* N \* O(1) = O(N^2)

## Consecutive statements with loops

Add consecutive statements using the addition rule

```c
i = 5;    // O(1)
j = 10    // O(1)
k = i * j;  // O(1)
k++;      // O(1)
```

Runtime: O(1) + O(1) + O(1) + O(1) = O(1)

```c
int m = 10; // O(1)
m++; // O(1)
for (int i = 0; i < N; i++) // O(N)
  a[i]++;
for (int i = 0; i < N; i++) // O(N)
  for (int j = 0; j < N; j++) // O(N)
    k++;
```

Runtime: O(1) + O(N) + (O(N) \* O(N)) = O(N^2)

## If-else statements

```c
if (condition)
  S1;
else
  S2;
```

The running time of an if else statement is never more than the running time of the condition
plus the larger of the running times of S1 and S2

```c
if (i % 10 == 0) { // O(1)
  k++; // O(1)
} else {
  for (j = 0; j < N; j++) { // O(N)
    k += 2;
  }
}
```

Runtime: O(1) + max(O(1) + O(N))
= O(1) + O(N)
= O(N)

## Method calls

Substitute the running time of the method's code in place of running time of the method's call

### Example 1

```c
int sum_N(int n) { // O(N)
  int total = 0;
  for (int i = 1; i <= n; i++)
    total += i;

  return total;
}

int main() {
  int j, k = 5;
  k++; // O(1)
  j = sum_N(k); // O(N)
}
```

Runtime: O(1) + O(N)
= O(N)

### Example 2

```c
int sum_N(int n) { // O(N)
  int total = 0;
  for (int i = 1; i <= n; i++)
    total += i;

  return total;
}

int sum_N_sq (int n) { // O(N^2)
  int total = 0;
  for (int i = 1; i <= n*n; i++)
    total += i;
  return total;
}

int main() {
  int j, k = 5;
  if (sum_N_sq(k) % 2 == 0) { // O(N^2)
    k++; // O(1)
  } else {
    j = sum_N(k); // O(N)
  }
}
```

Runtime: O(N^2) + max(O(1), O(N))
= O(N^2) + O(N)
= O(N^2)

# Algorithm Analysis

## Binary search algorithm

Input:

- A: Sorted array of N integers
- X: Integer to search for inside A

Return:
Index of X inside A, if found
-1, if not found

```c
int BinarySearch( const int A[ ], int X, int N ){
  int Low, Mid, High;

  Low = 0; High = N - 1;

  while( Low <= High ) {
    Mid = ( Low + High ) / 2;

    if( A[ Mid ] < X )
      Low = Mid + 1;
    else if( A[ Mid ] > X )
      High = Mid - 1;
    else
      return Mid; /* Found */
  }
  return -1; /* NotFound */
}
```

At each iteration, the size of the searched array gets **halved**.

Start with N = 2<sup>k</sup>
Problem size: N
At each step, problem size gets halved:
N, N/2, N/4, N/8, ... , 1

How many steps?
k steps
where, k = log<sub>2</sub> N

**Time Complexity of Binary Search is O(log<sub>2</sub> N)**

## Another log time complexity algorithm

```c
int foo(int N){
  for (int i = 1, i <= N; i*=2)
    a++;
}
```

Assume N = 2<sup>k</sup>
At each iteration, I gets doubled:
1, 2, 4, 8, ... , 2<sup>k</sup>

How many steps?
k steps
where, k = log<sub>2</sub> N

**Time Complexity: O(log<sub>2</sub> N)**

## Another log time complexity algorithm

```c
int foo(int N){
  for (int i = 1, i <= N; i*=3)
    a++;
}
```

Assume N = 3<sup>k</sup>
At each iteration, I gets
doubled:
1, 3, 9, 27, ... , 3<sup>k</sup>

How many steps?
k steps
where, k = log<sub>3</sub> N
= log<sub>2</sub> N / log<sub>2</sub> 3
= c log<sub>2</sub> N

**Time Complexity: O(log<sub>2</sub> N)**

## Yet another log time complexity algorithm

```c
long int pow(long int X, int N ){
  if ( N == 0 )
    return 1;
  if ( N == 1 )
    return X;
  if ( N % 2 == 0 ) // N is even
    return pow( X * X, N / 2 );
  else
    return pow( X * X, N / 2 ) * X;
}
```

Main idea:
x<sup>N</sup> = (x<sup>2</sup> )<sup>N/2</sup> , if n even
x<sup>N</sup> = x(x<sup>2</sup> )<sup>N/2</sup> , if n odd

At each iteration:
x<sup>N</sup> = (x<sup>2</sup> )<sup>N/2</sup>
x<sup>N/2</sup> = (x<sup>2</sup> )<sup>N/4</sup>
x<sup>N/4</sup> = (x<sup>2</sup> )<sup>N/8</sup>
...
x<sup>2</sup> = (x<sup>2</sup> )<sup>1</sup>
x<sup>1</sup> = x

**Time Complexity: O(log<sub>2</sub> N)**

# Quiz 1 module 2 examples

## Example 1

```c
sum = 0; // O(1)

for (i = 0; i < n; i++) // O(n)
  for (j = 0; j < i*i; j++) // O(n^2)
    if (j % i == 0) // this is evaluated n^2 times
    // how many times is the if block condition verified? n^2/n = n times
      for (k = 0; k < j; k++)
        sum ++;
    else
      // how many times else block happens? n^2 - n times (subtract n from n^2 (j-loop))
      // do nothing

```

O(1) + O(n* O(n(if block complexity) + (n^2-n) (else block time complexity)))
= O(1) + O(n* [n(n^2) + (n^2-n)1])
= O(1) + O(n\* [n^3 + n^2 - n])
= O(1) + O(n^4 + n^3 - n^2)
= O(1) + O(n^4) - by addition rule of Big-O
= **O(n^4)**

### Why is the if block condition verified n^2/n times?

Suppose n = 5
What are the values that j goes through? j is going from 1 through n^2, that is _1 through 25_.
What is the value of i (in worst case) inside j-loop? i's worst case value is n, that is _5_.
Values of j: 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15...18,19,20,21...25
i:5
When is j modulo i == 0? When j = 5, 10, 15, 20, 25... So 5 times.
**In general, there are n multiples of n between 1 and n^2. That's why j modulo i == 0 for n times.**

### If block variation

If the block was `if (j % 2 == 0)`, the multiples of 2 inside n\*n range are n^2/2
2 is a constant so it would be n^2

### Js example of multiples of a number in given range

```js
const n = 4;
for (let i = 0; i < n; i++) {
  // O(n)
  for (let j = 0; j < i * i; j++) {
    // O(n^2)
    if (i % j === 0) {
      // O(n) because the nr of multiples in this range is obtained by doing i*i/i
      console.log('🟢'); // <-- this outputs 4 times
    }
  }
}

console.log(
  (4 * 4) / 4, // <-- this is (i*i)/i = 4 = n
);

// Output:
// '🟢'
// '🟢'
// '🟢'
// '🟢'
// 4
```

---

## Example 2

```c
sum = 0;

for (i = 0; i < n ; i++) // O(n)
    sum++; // O(1)
```

**O(n)**

---

## Example 3

```c
sum = 0; // O(1)

for ( i = 0; i < n; i++) // O(n)
    for ( j = 0; j < i * i; j++ ) // O(n^2)
        for ( k = 0; k < j; k++ ) // O(n^2)
            sum++; // O(1)
```

**O(n^5)**

---

## Example 4

```c
sum = 0;

for (i = 0; i < n ; i++) // O(n)
    for (j = 0; j < n ; j++) // O(n)
        sum++; // O(1)
```

**O(n^2)**

---

## Example 5

```c
sum = 0;

for ( i = 0; i < n; i++ ) // O(n)
    for ( j = 0; j < i; j++ ) // this is O(n) because i at worst case is n
        sum++; // O(1)
```

**O(n^2)**

---

## Example 6

```c
sum = 0; // O(1)

for ( i = 0; i < n; i++ ) // O(n)
    for ( j = 0; j < n * n; j++ ) // O(n^2)
        sum++; // O(1)
```

**O(n^3)**

---
