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
