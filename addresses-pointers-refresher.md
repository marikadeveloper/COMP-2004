# Quick refresher on addresses and pointers

& = figure out the address of something

\* = go to the address of something

```c
int n = 50;
int *p = &n; // pointer that stores the address of n
printf("%i\n", *p); // print the value in that address
printf("%i\n", p); // print the address of n
printf("%p\n", &n); // print the address of n (hexadecimal)
```

strings are arrays of characters

```c
char *s = "HI!";

// the following two lines print the same things because a string is an address
// of the first character of a string
printf("%p\n", s);
printf("%p\n", &s[0]);

printf("%c\n", *s); // go to the s character         (same as s[0])
printf("%c\n", *(s + 1)); // go to the 2nd character (same as s[1])
printf("%c\n", *(s + 2)); // go to the 3rd character (same as s[2])
```

# Pointers

A pointer contains an address (in runtime memory)
For 64-bit machines the address is 8 bytes long, or 64 bits

```c
int *iptr; // pointer to an integer
char *cptr; // pointer to a character
float *fptr; // pointer to a float
```

## Initializing pointers

Pointers can be initialized to NULL (default) or to the address of a variable

```c
int i;
int *iptr1; // uninitialized pointer, points to NULL
int *iptr2 = &i; // points to the address of i
```

This is what happens in memory:

| Address | Variable name | Value  |
| ------- | ------------- | ------ |
| 0x1000  | i             | 0      |
| 0x1004  | iptr1         | NULL   |
| 0x1006  | iptr2         | 0x1000 |

## Accessing pointers

\*<pointer-name>

This gets the value of the variable pointed to by the pointer
It can be used for assignment

```c
#include <stdio.h>

int main()
{
    int i1 = 10, i2 = 8, i3;
    int *iptr = &i2; // iptr points to i2
    printf("Value pointed to by iptr: %d\n",*iptr); // prints 8 – value of i2

    i3 = *iptr; // i3’s value becomes 8 – value of i2
    *iptr = i1; // *iptr and i2’s values both become 10 because they both point to the same memory location
    printf("Value pointed to by iptr: %d\n",*iptr); // prints 10 – value of i1
    printf("i2 is also updated: %d\n",i2); // prints 10
}
```

## Pointer to pointer

A pointer to a pointer is a pointer that points to another pointer

```c
int i = 10;
int *iptr = &i; // iptr points to i
int **ipptr = &iptr; // ipptr points to iptr
printf("Value pointed to by ipptr: %d\n", **ipptr); // prints 10 – value of i
```

## Constant pointers

type \*const <pointer-name> = &<variable-name>;

It must be initialized when declared and cannot be changed
A pointer can be declared as constant, meaning that the address it points to cannot be changed

```c
// *myPtr refers to the value at the address stored in myPtr
// myPtr refers to the address of the variable it points to
/**
  Both x and *myPtr can be changed, but myPtr cannot be changed
  to point to another address
*/
int *const myPtr = &x; // int pointer to a fixed address

/**
  *myPtr cannot be changed, but x can be changed
  myPtr can be changed to point to another address
*/
const int *myPtr = &x; // pointer to a constant integer

/**
  *myPtr cannot be changed
  myPtr cannot be changed to point to another address
*/
const int *const myPtr = &x; // constant pointer to a constant integer
```

## Call by reference

In C, all function arguments are passed by **value**, which means that the function
receives a copy of the argument.
If the argument is a pointer, the function receives a copy of the pointer, but it
can modify the value at the address the pointer points to.

```c
int func1(int);

int main(void) {
  int n = 5;
  func1(n);
}

int func1(int k) {
  k = k + 2;
  return 0;
}
```

In this case, the value of n will not change because the function receives a copy of n.
Changes are made to the local copy k.
So k will be 7, but n will still be 5.

To change the value of n, we need to pass the address of n to the function.
This is called call by **reference**.

```c
int func2(int *);

int main(void) {
  int n = 5;
  func2(&n);
}

int func2(int *k) {
  *k = *k + 2;
  return 0;
}
```

In this case, the value of n will change because the function receives the address of n.
Changes are made to the value at the address k points to. So n will be 7.

## Arrays and pointers

An array name is a constant pointer to the first element of the array

```c
int arr[5] = {1, 2, 3, 4, 5};
// arr is the same as &arr[0]
// arr+1 is a pointer that points to the second element of the array
// so arr is the same as &arr[0], arr+1 is the same as &arr[1], arr+2 is the same as &arr[2], and so on
// similarly, *arr is same as arr[0], *(arr+1), that is the value pointed by *arr+1, is the same as arr[1], *(arr+2) is the same as arr[2], and so on

int arr[6] = {10, 20, 30, 40, 50, 60};

printf("Array elements printed using array notation:\n");
for (int i=0; i<6; i++)
      printf("arr[%d] = %d\n", i, arr[i]);

printf("Array elements printed using pointer notation:\n");
for (int i=0; i<6; i++)
      printf("*(arr+%d) = %d\n", i, *(arr+i));
```

## Dynamic memory allocation

Dynamic memory is allocated inside the heap, while static memory is allocated inside the stack.

### malloc()

syntax: void \*malloc(size_t size);

Allocates memory equal to `size` bytes
`size` needs to be calculated and provided by programmer based on the data type
and number of elements

Returns a pointer to the start of the allocated memory that is of type void which
can be cast into a pointer of any form
NULL pointer if the memory allocation fails

It **does not initialize the memory**, so the memory contains garbage values

### free()

syntax: void free(void \*ptr);

Releases the memory allocated by malloc

```c
int n;

printf("Enter the size of the array: ");
scanf("%d", &n);

int *arr = (int *)malloc(n * sizeof(int));
// memory 'arr' allocated but not initialized

printf("Enter %d integers separated by a single space: ", n);
for (int i = 0; i < n; i++)
    scanf("%d", arr+i); // initialize each element of 'arr'


for (int i = 0; i < n; i++)
    printf("arr[%d] = %d\n", i, *(arr+i));  //print elements of 'arr'

free(arr); // release memory allocated for 'arr' by malloc
printf("After doing free, array memory is released and array data points to garbage...\n");
printf("arr[0] = %d\n", *arr);
```

### calloc()

syntax: void \*calloc(size_t n_memb, size_t size);

Very similar to malloc, but **it initializes the memory to 0**
Allocates memory for an array of `n_memb` elements of `size` bytes each

calloc(n, item_size) = malloc(n \* item_size)

```c
int n;

printf("Enter the size of the array: ");
scanf("%d", &n);

int *arr = (int *)calloc(n, sizeof(int));
// memory 'arr' allocated and initialized to 0
// [...]
```

### realloc()

syntax: void \*realloc(void \*ptr, size_t size);

Changes the size of the previously allocated memory by allocated new area
(or changing the size of the existing area)

Can be used to increase or decrease the size of the memory block

Data copied from the old memory block to the new memory block frees the old memory block
if the two memory blocks are different

Returns a pointer to the start of the new memory block
NULL pointer if the memory allocation fails

```c
int n;

printf("Enter the size of the array: ");
scanf("%d", &n);

int *arr = (int *)malloc(n * sizeof(int));
// memory 'arr' allocated but not initialized

// [...]
printf("Enter the new size of the array: ");
scanf("%d", &n);

arr = (int *)realloc(arr, n * sizeof(int));
// memory 'arr' reallocated to new size and old data is copied to new memory
// [...]
```

## Multi-dimensional arrays and pointers

### 2D arrays

You need to allocate:

- an array (n_rows) that will contain the pointers to the rows
- an array (n_cols, of n_cols size) for each row that will contain the columns

```c
int n_rows = 3, n_cols = 4;

// ** means pointer to pointer
int **arr2d; // if i had a 3d array, i would need three asterisk ***arr3d
arr2d = (int **)malloc(n_rows * sizeof(int *)); // allocate memory for n_rows pointers

// then allocate memory for num_cols elements for each row
for (int i = 0; i < num_cols; i++)
    arr2d[i] = (int *)malloc(num_cols * sizeof(int)); // sizeof int because it's an array of integers

// Enter the data from console to initialize 'arr2d'
printf("Enter the data for the 2-d array\n");
for (int r = 0; r < num_rows; r++){
    for (int c = 0; c < num_cols; c++){
        printf("Enter item at [%d][%d]: ", r, c);
        scanf("%d", arr2d[r]+c);
    }
}

// Print elements of 'arr2d'
for (int r = 0; r < num_rows; r++){
    for (int c = 0; c < num_cols; c++)
        printf("Element at [%d][%d]: %d\n", r, c, arr2d[r][c]);
}
```

## Pointers on c structures

### Structures refresher

A structure is a collection of variables of different types under a single name
It defines a new type that compiler regards as a single entity

```c
struct pixel {
    int x;
    int y;
    char color; // 'R' for red, 'G' for green, 'B' for blue
};
```

### Pointers to structures

Declaring a pointer to a struct

```c
struct pixel *pptr;
// pptr is a pointer to a struct pixel
// you need to write struct pixel because pixel is not a type, it's a struct
```

The data members inside pptr can be accessed using the arrow operator (->)
after allocating memory for the structure

```c
pptr->x = 10;
pptr->y = 20;
pptr->color = 'R';
```

#### typedef

The `typedef` keyword is used to create an alias name for data types

```c
typedef struct pixel Pixel;
Pixel *pptr; // no need to use struct keyword again
```

Example of usage:

```c
struct pixel{
    int x; //x coord of pixel
    int y; //y coord of pixel
    char color; //color  of pixel, 'R', 'G' or, 'B'
};

typedef struct pixel Pixel;

Pixel *pptr = (Pixel *)malloc(1*sizeof(Pixel));

pptr->x = 10;
pptr->y = 5;
pptr->color = 'R';

printf("Pixel: %d, %d, %c\n",pptr->x, pptr->y, pptr->color);
```

### Self-referential structures

A structure that contains a pointer to a structure of the same type

```c
struct item {
  char *s;
  struct item *next;
}
```

I.e. an item can point to another item
...which can point to another item
...which can point to another item
...etc

This forms a list of items
