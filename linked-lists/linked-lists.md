# ADT and Linked Lists

## ADT

An ADT is a data type that is defined by the operations that can be performed on it. The operations are defined by the ADT, not by the implementation. The implementation of the ADT is hidden from the user.

## List ADT Operations

The first element of the list is at position 1

- `find` - returns the position of the first element with a given value
- `insert` - inserts an element at a given position
- `delete` - deletes the element at a given position
- `find_kth` - returns the element at a given position
- `print_list` - prints the list
- `make_null` - makes the list empty

### List ADT Operations Examples

list: 34, 12, 52, 16, 19

- `find(52)` - returns 3
- `insert(17, 3)` - inserts 17 after position 3
  - makes the list 34, 12, 52, 17, 16, 19
- `delete(16)` - deletes 16
  - makes the list 34, 12, 52, 17, 19
- `find_kth(4)` - returns 17, does not change the list

## Array-Based List Implementation

It is not very elegant:

- insert and delete are expensive
  - inserting at position 0 requires shifting all elements to the right, might require memory alloc
  - deleting at position 0 requires shifting all elements to the left
  - requires O(n) time
- `print_list`, `find`, `find_kth` take O(N) time
- creating a new list of N elements - insert N elements starting from a null list requires N\*O(N) = O(N<sup>2</sup>) time
  - this is because inserting takes O(N) time and we are inserting N elements so N\*O(N) = O(N<sup>2</sup>)

## Linked List - Theory

A linked list is a data structure that consists of a sequence of elements, where each element points to the next element in the sequence. The last element points to NULL. The elements are not necessarily stored in contiguous memory locations.

| ai | p |-> | ai+1 | p |-> | ai+2 | p |-> | ... | p |-> | an | p |-> NULL |

A list element is called node or cell, each node consists of a two part structure:

- data part (ai) - holds the element value
- reference part, which points to the next node in the sequence (p)
- last node points to NULL (defined by c in stdio.h)

### Header node

We can have a dummy node at the beginning of the list, called the header node. The header node does not contain any data, it points to the first node in the list.
Header node position is 0, first node position is 1.

### Our assumptions for convenience

- draw pointers as arrows
- assume integer data elements
- position of the first element is 1, header node is at position 0
- insert at position p means insert after the node at position p
- delete(x) means delete the first node with data x if it exists

## Linked List - Implementation

### Node

```c
struct Node {
  int Element;
  struct Node *Next;
};
```

This is the list node code, refined:

```c
typedef int ElementType; // declare type ElementType as int, this is the type of the data part of the node; this is clean code because we can change the type of the data part of the node by changing only one line of code

struct Node; // this tells the compiler that there is a struct called Node, but we don't know what it looks like yet

typedef struct Node *PtrToNode; // declare PtrToNode as a "pointer to a Node"
typedef PtrToNode List; // declare List as "pointer to a Node" type, because the list is a pointer to the header node
typedef PtrToNode Position; // declare Position as "pointer to a Node" type, because the position is a pointer to a node

struct Node {
  ElementType Element; // data part of the node is of type ElementType (int in this case)
  Position Next; // reference part of the node is a pointer to the next node
};
```

### List methods code

`IsEmpty` - returns 1 if the list is empty, 0 otherwise

```c
int IsEmpty(List L) {
  return L->Next == NULL;  // list is the header node, so the first node is header->next
}
```

`IsLast` - returns 1 if the position is the last position in the list, 0 otherwise

```c
int IsLast(Position P) {
  return P->Next == NULL;
}
```

`Find` - returns the position of the first occurrence of x in the list, NULL if not found

```c
Position Find(ElementType X, List L) {
  Position P;

  P = L->Next; // list is the header node, so the first node is header->next
  while (P != NULL && P->Element != X) {
    P = P->Next;
  }

  return P;
}
```

`Delete` - deletes the first occurrence of x from the list

```c
Position FindPrevious(ElementType X, List L) {
  Position P;

  P = L; // we start from L and not from L->Next because we want to find the previous node to the one we want to delete, that can be the first node
  while (P->Next != NULL && P->Next->Element != X) { // we check P->Next->Element because we want to find the previous node to the one we want to delete
    P = P->Next;
  }

  return P;
}

void Delete(ElementType X, List L) {
  Position P, TmpCell;

  P = FindPrevious(X, L); // find the previous node to the one we want to delete

  if (!IsLast(P)) { // we want to delete the node only if it exists
    TmpCell = P->Next; // save the node we want to delete in a temporary variable
    P->Next = TmpCell->Next; // make the previous node point to the node after the one we want to delete
    free(TmpCell); // free the memory of the node we want to delete
  }
}
```

`Insert` - inserts after the position p

```c
void Insert(ElementType X, List L, Position P) {
  Position TmpCell;
  TmpCell = malloc(sizeof(struct Node)); // allocate memory for the new node

  if (TmpCell == NULL) {
    printf("Out of space");
  }

  TmpCell->Element = X; // set the data part of the new node
  TmpCell->Next = P->Next; // make the new node point to the node after the position p
  P->Next = TmpCell; // make the position p point to the new node
}
```

`DeleteList` - deletes the list

```c
void DeleteList(List L) {
  Position P, Tmp;

  P = L->Next; // list is the header node, so the first node is header->next
  L->Next = NULL; // make the header node point to NULL
  while (P != NULL) {
    Tmp = P->Next; // save the next node in a temporary variable
    free(P); // free the memory of the current node
    P = Tmp; // move to the next node
  }

  free(L); // free the memory of the header node
}
```

`MakeEmpty` - makes the list empty

```c
List MakeEmpty(List L) {
  if (L != NULL) {
    DeleteList(L); // delete the list
  }

  L = malloc(sizeof(struct Node)); // allocate memory for the header node
  if (L == NULL) {
    printf("Out of space");
  }

  L->Next = NULL; // make the header node point to NULL
  return L;
}
```

## Doubly Linked List

A doubly linked list is a linked list that has two references, one to the next node and one to the previous node.
The first node's previous reference points to NULL, the last node's next reference points to NULL.

This increases space requirements (doubles the n. of pointers) and doubles cost of insertions and deletions.

It simplifies the implementation of deletion because you do not need to calculate pointers to the previous node using FindPrevious method.

### Node

```c
typedef int ElementType;

struct Node;

typedef struct Node *PtrToDoubleNode;
typedef PtrToDoubleNode List;
typedef PtrToDoubleNode Position;

struct Node {
  ElementType Element;
  Position Next;
  Position Prev;
};
```

## Circularly Linked List

A circularly singly linked list is a linked list where the last node points back to the first node.
Used for round-robin scheduling, for example.

Most likely a singly linked list

- need to adjust next pointer of last node while inserting and deleting from first or last position

## Implementing Polynomial using Lists

A polynomial is a mathematical expression that is the sum of a number of terms, each term is a constant multiplied by a variable raised to a power.

f(x) = a<sub>0</sub> + a<sub>1</sub>x + a<sub>2</sub>x<sup>2</sup> + ... + a<sub>n</sub>x<sup>n</sup>

Operations: adding or multiplying two polynomials

If polynomial is dense (most of the coefficients are non-zero):

- use an array-based representation
- index of a coefficient inside the array gives exponent of x

```c
typedef struct {
  int CoeffArray[MaxDegree + 1]; // array of coefficients
  int HighPower; // highest power of x with non-zero coefficient
} *Polynomial;

void ZeroPolynomial( Polynomial Poly ) {
  int i;

  // set all coefficients to 0 because the polynomial is 0
  for (i = 0; i <= MaxDegree; i++) {
    // MaxDegree is the maximum degree of the polynomial
    // we set all coefficients to 0
    Poly->CoeffArray[i] = 0;
  }

  // set the highest power of x with non-zero coefficient to 0
  Poly->HighPower = 0;
}

void AddPolynomial( const Polynomial Poly1, const Polynomial Poly2, Polynomial PolySum ) {
  int i;

  ZeroPolynomial( PolySum ); // set all coefficients of the sum polynomial to 0

  // add the coefficients of the two polynomials
  PolySum->HighPower = Max( Poly1->HighPower, Poly2->HighPower ); // set the highest power of x with non-zero coefficient to the highest power of x with non-zero coefficient of the two polynomials
  for (i = PolySum->HighPower; i >= 0; i--) {
    // for each coefficient from the highest power of x with non-zero coefficient to 0
    PolySum->CoeffArray[i] = Poly1->CoeffArray[i] + Poly2->CoeffArray[i]; // add the coefficients of the two polynomials
  }
}

void MultPolynomial( const Polynomial Poly1, const Polynomial Poly2, Polynomial PolyProd ) {
  int i, j;

  ZeroPolynomial( PolyProd ); // set all coefficients of the product polynomial to 0

  // multiply the coefficients of the two polynomials
  PolyProd->HighPower = Poly1->HighPower + Poly2->HighPower; // set the highest power of x with non-zero coefficient to the sum of the highest powers of x with non-zero coefficients of the two polynomials
  if (PolyProd->HighPower > MaxDegree) {
    printf("Exceeded array size");
  } else {
    for (i = 0; i <= Poly1->HighPower; i++) {
      // for each coefficient of the first polynomial
      for (j = 0; j <= Poly2->HighPower; j++) {
        // for each coefficient of the second polynomial
        PolyProd->CoeffArray[i + j] += Poly1->CoeffArray[i] * Poly2->CoeffArray[j]; // multiply the coefficients of the two polynomials and add the result to the coefficient of the product polynomial
      }
    }
  }
}
```

If polynomials are not dense, implementation using arrays is inefficient.

Example:
p1(x) = 7x<sup>3</sup> + 4x<sup>55</sup> + 27x<sup>203</sup>
p2(x) = 15x<sup>29</sup> + 9x<sup>137</sup> + 32x<sup>1004</sup>

Array implementation of a non-dense polynomials requires large but very sparse arrays - inefficient!

Each term of a polynomial is stored in a list node
List nodes are sorted in order of decreasing exponents

```c
typedef struct Node *PtrToNode;

struct Node {
  int Coefficient;
  int Exponent;
  PtrToNode Next;
};

typedef PtrToNode Polynomial; // pointer to the first node of the list; nodes are sorted by exponent in decreasing order
```
