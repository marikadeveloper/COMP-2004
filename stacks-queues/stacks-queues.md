# Applications of Stacks and Queues

## Stacks

### Balancing Symbols

Balancing symbols is a common problem that can be solved using a stack. The problem is to determine if a string of symbols is balanced. A string of symbols is balanced if every opening symbol has a corresponding closing symbol and the pairs of symbols are properly nested. For example, the string `((()))` is balanced, but the string `(()` is not balanced.

```
function isBalanced(symbols):
    stack = new Stack()

    for symbol in symbols:
        if symbol is an opening symbol:
            stack.push(symbol)
        else if symbol is a closing symbol:
            if stack is empty:
                return false
            else if stack.top() is not the corresponding opening symbol for symbol:
                return false
            else:
                stack.pop()

    return stack.isEmpty()
```

### Postfix Evaluation

**Infix notation**: a + b - c / d + e \* f
e.g. 11 + 5 - 24 / 8 + 2 \* 3
Correct answer: **19**
Incorrect answer: 3

**Postfix notation**: a b c + d e \* /
e.g. 11 5 + 24 8 / - 3 2 \* +

steps:

1. 11 5 + -> 16
   16 24 8 / - 3 2 \* +
2. 24 8 / -> 3
   16 3 - 3 2 \* +
3. 16 3 - -> 13
   13 3 2 \* +
4. 3 2 \* -> 6
   13 6 +
5. 13 6 + -> **19**

Pseudo code for postfix expression evaluation

```
S = empty stack
While not EOF {
  c = read next token from file
  if c is an operand
    push (c, S)
  if c is an operator
    o2 = TopAndPop (S)
    o1 = TopAndPop (S)
    result = Perform operation o1 c o2
    push (result, S)
}
return TopAndPop (S)
```

#### infix to postfix conversion

## Infix to Postfix Conversion Explained:

Infix notation (a+b) is the common way humans write expressions, with operators between operands. Postfix notation (ab+) puts operators after operands, making evaluation easier for computers. Let's understand the conversion step-by-step:

**1. Use a Stack:**

Imagine a stack (like a pile of plates) to store operators temporarily. You'll also need an output string to build the postfix expression.

**2. Scan the Infix Expression:**

Read the infix expression character by character.

**3. Operand Encountered:**

- If the character is an operand (e.g., a, b, 5), simply **append it to the output string**.

**4. Operator Encountered:**

- If the character is an operator (+, -, \*, /, ^), check the following:
  - **Stack empty:** Push the operator onto the stack.
  - **Operator has higher precedence** than the top element of the stack: Push the operator onto the stack.
  - **Operator has lower or equal precedence**:
    - Pop operators from the stack and append them to the output string **until** you find an operator with lower precedence or an empty stack.
    - Then, push the current operator onto the stack.

**5. Parenthesis Encountered:**

- If the character is an opening parenthesis (`(`), push it onto the stack.
- If the character is a closing parenthesis (`)`):
  - Pop operators from the stack and append them to the output string **until** you encounter an opening parenthesis.
  - Discard the opening parenthesis.

**6. Repeat steps 2-5 until the entire expression is scanned.**

**7. Pop any remaining operators from the stack and append them to the output string.**

**Example:** Convert `(a + b) * c` to postfix:

**Steps:**

1. `(`: Push to stack.
2. `a`: Append to output string.
3. `+`: Push to stack.
4. `b`: Append to output string.
5. `)`: Pop `+` and append to output string.
6. `*`: Stack has higher precedence, push to stack.
7. `c`: Append to output string.
8. Stack is empty, no more steps.

**Postfix Expression:** `ab+c*`

**Pseudocode:**

```python
function infix_to_postfix(infix):
  output = ""
  stack = []
  for char in infix:
    if char.isalnum():
      output += char
    elif char == "(":
      stack.append(char)
    elif char == ")":
      while stack[-1] != "(":
        output += stack.pop()
      stack.pop()  # Remove "("
    else:
      while stack and precedence(stack[-1]) >= precedence(char):
        output += stack.pop()
      stack.append(char)
  while stack:
    output += stack.pop()
  return output

# Helper function to define operator precedence
def precedence(op):
  if op in "+-":
    return 1
  elif op in "*/":
    return 2
  elif op == "^":
    return 3
  else:
    return 0
```

### Undo Functionality

Stacks can be used to implement undo functionality in applications. For example, a text editor can use a stack to store the changes made to a document. When the user wants to undo a change, the text editor can pop the last change from the stack and revert the document to its previous state.

```
function undo():
    if stack is not empty:
        change = stack.pop()
        revertChange(change)
```

### Function Call Stack

The function call stack is a stack that is used to store information about the active subroutines of a computer program. When a function is called, the computer stores information about the function in the stack. When the function returns, the computer removes the information from the stack. The function call stack is used to keep track of the order of function calls and the local variables of each function.
