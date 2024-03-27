# Heaps

A heap is a complete binary tree that satisfies the heap property. The heap property states that the key of a node is greater than or equal to the keys of its children. A heap can be implemented as an array where the children of the node at index `i` are at indices `2i + 1` and `2i + 2`.

Heaps are used to implement priority queues, which are data structures that allow for efficient access to the element with the highest (or lowest) priority. The highest-priority element is always at the root of the heap.

There are two types of heaps: max-heaps and min-heaps. In a max-heap, the key of each node is greater than or equal to the keys of its children, and the highest-key element is at the root. In a min-heap, the key of each node is less than or equal to the keys of its children, and the lowest-key element is at the root.

## Operations

The main operations on a heap are:

- Insert a new element - O(log n) (height of the binary tree is log n)
- Log the element with the highest (or lowest) priority - O(1)
- Remove the element with the highest (or lowest) priority - O(log n)

## Special properties

Parent of node at index `i` is at index `i / 2`.
Left child of node at index `i` is at index `2i`.
Right child of node at index `i` is at index `2i + 1`.

## Implementation - Assumptions

- The heap is implemented as an array.
- The array will be 1-based (i.e., the root of the heap will be at index 1).
- Array at index 0 will contain a sentinel element (smallest possible value for a min-heap, largest possible value for a max-heap).
- Assume heap means binary min-heap unless otherwise specified.
- All keys are integers with no duplicates

## Parent and child indices for a D-ary heap

For a D-ary heap, the parent and child indices can be calculated as follows:

- Right child of node at index `i` is at index `D * i + 1`.
- Left child of node at index `i` is at index:
  - `D * i + 1 - (d-1)`
  - simplifies to `D * i + 1 - d + 1`
  - simplifies to `D * (i - 1) + 2`
- Parent of node at index `i` is at index:
  - if i % d == 1 -> rightmost child
    - `floor(i / D)`
  - else
    - `ceil(i / D)`
