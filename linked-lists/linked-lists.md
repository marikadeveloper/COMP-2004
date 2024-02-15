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
typedef int ElementType; // declare type ElementType as int, this is the type of the data part of the node

struct Node;

typedef struct Node *PtrToNode; // declare PtrToNode as a "pointer to a Node"
typedef PtrToNode List; // declare List as "pointer to a Node" type, because the list is a pointer to the header node
typedef PtrToNode Position; // declare Position as "pointer to a Node" type, because the position is a pointer to a node

struct Node {
  ElementType Element; // data part of the node is of type ElementType (int in this case)
  Position Next; // reference part of the node is a pointer to the next node
};
```
