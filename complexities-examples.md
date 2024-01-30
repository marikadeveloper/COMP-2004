# Quiz 1 module 2 examples

## Example 1

```sum = 0;

/*1*/ for (i = 0; i < n; i++)
/*2*/   for (j = 0; j < i*i; j++)
/*3*/     if (j % i == 0)
/*4*/       for (k = 0; k < j; k++)
/*5*/         sum ++;
/*6*/     else
/*7*/       / * do nothing – this is O(1)*/

```

To help us understand, let’s add a dummy else condition with the for loop.
Let’s start from the middle for-j loop, its size is n\*n = n<sup>2</sup> (The ‘n’ comes from the worst case value of ‘i’ in
the outer i-loop).

So, the condition in line 3, which has time complexity O(1), is evaluated n<sup>2</sup> times.

Now, let us see how these n<sup>2</sup> iterations are divided inside the body of the j-loop **due to the if condition on line 3**:

- line 4-5 is executed n times. This condition is true only when j is a multiple of i.
  In the middle loop, j goes from 0 to i\*i-1. The number of multiples of i in this range is (i\*i) / i, which simplifies to i.
  So, for each iteration of the middle loop, the innermost loop (inside the if statement) is executed 'i' times.
  More on **js example of multiples...** section;
- line 7 is executed (n<sup>2</sup>-n) times (because you subtract the running time of line 4-5 that is n)

So, the n<sup>2</sup> size of the for-j loop is divided as:
_n \* (line 4 - 5 time complexity) + (n<sup>2</sup> - n) \* (line 7 complexity)._

Now, substitute the time complexities of lines 4-5 and line 7 in the above expression.
This will give us:
n \* (n<sup>2</sup>) + (n<sup>2</sup>-n) \* (1)
= n<sup>3</sup> + n<sup>2</sup>-n
= O(n<sup>3</sup>)
Finally, multiply the last expression with the outer i-loop size to get:
n \* O(n<sup>3</sup>) = O(n<sup>4</sup>).

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

```
sum = 0;

for (i = 0; i < n ; i++) # O(n)
    sum++;
```

So we have O(n)

---

## Example 3

```
sum = 0;

for ( i = 0; i < n; i++) # O(n)
    for ( j = 0; j < i * i; j++ ) # O(n^2)
        for ( k = 0; k < j; k++ ) # O(n^2)
            sum++; # O(1)
```

So we have O(n^5)

---

## Example 4

```
sum = 0;

for (i = 0; i < n ; i++) # O(n)
    for (j = 0; j < n ; j++) # O(n)
        sum++;
```

So we have O(n^2)

---

## Example 5

```
sum = 0;

for ( i = 0; i < n; i++ ) # O(n)
    for ( j = 0; j < i; j++ ) # this is O(n) because i at worst case is n
        sum++;
```

So we have O(n^2)

---

## Example 6

```
sum = 0;

for ( i = 0; i < n; i++ ) # O(n)
    for ( j = 0; j < n * n; j++ ) # O(n^2)
        sum++;
```

So we have O(n^3)

---
