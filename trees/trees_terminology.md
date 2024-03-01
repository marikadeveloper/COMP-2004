# Trees

## General Tree Terminology

**Tree**: A tree is a data structure that consists of nodes in a parent/child relationship. Each node has a value and a list of references to other nodes.

**Binary Tree**: A tree in which each node has at most two children.

**depth**: The depth of a node is the number of edges from the node to the tree's root node. A root node will have a depth of 0. A Binary Tree's depth will be avg sqrt(n) where n is the number of nodes in the tree.

**edge**: An edge is the link between a parent and a child node.

**height**: The height of a node is the number of edges on the longest path from the node to a leaf. A leaf node will have a height of 0. A Binary Tree's height will be avg log(n) where n is the number of nodes in the tree. Worst case height is n - 1 in the case of a tree with one long branch like a list.

**leaf**: A leaf is a node that has no children.

**root**: The root is the top node in a tree.

**subtree**: A subtree is a tree that is part of a larger tree.

## Tree Traversal

**Pre-order**: Visit the root node first, then recursively do a pre-order traversal of the left subtree, followed by a pre-order traversal of the right subtree.

**In-order**: Recursively do an in-order traversal of the left subtree, visit the root node, and finally do an in-order traversal of the right subtree.

**Post-order**: Recursively do a post-order traversal of the left subtree, do a post-order traversal of the right subtree, and visit the root node.

### Another explanation

**Preorder Traversal:** It's like saying hello to the parents first! You start at the very top (the root) and work your way down, visiting each person from the top of the family to the bottom.

Example: Say the tree is for a family with a grandma, her son Dad, and his daughter named Maya. A preorder visit would go: Grandma → Dad → Maya

**Inorder Traversal:** This is like visiting family in alphabetical order based on their first names. You start at the far left of the tree, move up to the parent, then over to the right side.

Example: The same family tree visited inorder would be: Dad → Grandma → Maya

**Postorder Traversal:** This means saying hello to the kids first! You'll begin at the very bottom of the tree (the leaves), and move upwards towards the parents and grandparents.

Example: In a postorder family visit, the order would be: Maya → Dad → Grandma

## Expression Trees

**Expression Tree**: A binary tree in which each internal node corresponds to an operator, and each leaf node corresponds to an operand.

If you do **in-order** traversal of an expression tree, you will get the original expression.

- add a left parenthesis at start of traversing each subtree
- add right parenthesis at end of traversing each subtree

If you do **post-order** traversal of an expression tree, you will get the postfix expression.

### Example

Input: Exp = an expression string in postfix
Exp = a b + c d e + \* \*

Output: An expression tree

Code with in-order traversal:

```
S = empty stack
for each element o in Exp:
  if o is operand:
    create a one-node tree (null, o, null)
    push the tree onto S
  else:
    R = pop from S
    L = pop from S
    create a tree with L as left child, o as root, and R as right child (L, o, R)
    push the tree onto S
```

Result:

```
      *
     / \
    +   *
   / \ / \
  a  b c  +
        / \
       d   e
```

Expression trees can be evaluated via a post-order traversal of the nodes:
Let L = evaluate the left subtree
Let R = evaluate the right subtree
Apply the operator at the root to L and R
Subtree evaluation is carried out recursively
