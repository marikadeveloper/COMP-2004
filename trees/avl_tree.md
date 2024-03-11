# AVL Tree

An AVL tree is a self-balancing binary search tree. It was the first such data structure to be invented. In an AVL tree, the heights of the two child subtrees of any node differ by at most one; if at any time they differ by more than one, rebalancing is done to restore this property. Lookup, insertion, and deletion all take O(log n) time in both the average and worst cases, where n is the number of nodes in the tree. Insertions and deletions may require the tree to be rebalanced by one or more tree rotations.

## Imbalance cases

There are four possible imbalance cases.
Let α denote the first node (moving upwards from the insert position) where imbalance happens.
Node α's two subtrees' height differ by at least 2.

1. Left-Left (LL) Imbalance: insert was made into α's left child's left subtree - **rotate right**
2. Right-Right (RR) Imbalance: insert was made into α's right child's right subtree.
3. Left-Right (LR) Imbalance: insert was made into α's left child's right subtree.
4. Right-Left (RL) Imbalance: insert was made into α's right child's left subtree.

### Left-Left (LL) Imbalance

The following is a LL because we insert 5 into 16's left child's left subtree

```plaintext
     16
    /  \
  12    19
 /  \
7    14

insert 5

       16 (balance value: 2 - left subtree's height minus right subtree's height)
      /  \
    12    19
   /  \
  7    14
 /
5
```

The solution is to **single Rotate Right**.

```plaintext
     12
    /  \
   7    16
  /    /  \
 5    14   19
```

### Right-Right (RR) Imbalance

The following is a RR because we insert 30 into 16's right child's right subtree

```plaintext
     16
    /  \
  12    19
       /  \
      18  22

insert 30

     16 (balance value: -2)
    /  \
  12    19
       /  \
      18  22
            \
            30
```

The solution is to **single Rotate Left**.

```plaintext
     19
    /  \
  16    22
 /  \     \
12  18    30
```

### Right-Left (RL) Imbalance

The following is a RL because we insert 17 into 16's right child's left subtree

```plaintext
     16
    /  \
  12    19
       /  \
      18  22

insert 17

       16 (balance value: -2)
      /  \
    12   19
        /  \
       18  22
      /
    17
```

The solution is to **double Rotate Right-Left**.

```plaintext
     18
    /  \
  16    19
 /  \     \
12   17    22
```

First we did a left rotation on 19 and then a right rotation on 16.

### Left-Right (LR) Imbalance

The following is a LR because we insert 13 into 16's left child's right subtree

```plaintext
     16
    /  \
  12    19
 /  \
10  14

insert 13

       16 (balance value: -2)
      /  \
    12    19
   /  \
  10  14
      /
    13
```

The solution is to **double Rotate Right-Left**.

```plaintext
     14
    /  \
  12    16
 /  \     \
10  13     19
```
